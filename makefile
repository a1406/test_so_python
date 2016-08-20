###############################################################################
#
# Generic Makefile for C/C++ Program
#
# Author: whyglinux (whyglinux AT hotmail DOT com)
# Date:   2006/03/04

# Description:
# The makefile searches in <SRCDIRS> directories for the source files
# with extensions specified in <SOURCE_EXT>, then compiles the sources
# and finally produces the <PROGRAM>, the executable file, by linking
# the objectives.

# Usage:
#   $ make           compile and link the program.
#   $ make objs      compile only (no linking. Rarely used).
#   $ make clean     clean the objectives and dependencies.
#   $ make cleanall  clean the objectives, dependencies and executable.
#   $ make rebuild   rebuild the program. The same as make clean && make all.
#==============================================================================

## Customizing Section: adjust the following if necessary.
##=============================================================================

# The executable file name.
# It must be specified.
# PROGRAM   := a.out    # the executable name
PROGRAM   := game_srv

# The directories in which source files reside.
# At least one path should be specified.
# SRCDIRS   := .        # current directory
SRCDIRS   := . 

# The source file types (headers excluded).
# At least one type should be specified.
# The valid suffixes are among of .c, .C, .cc, .cpp, .CPP, .c++, .cp, or .cxx.
# SRCEXTS   := .c      # C program
# SRCEXTS   := .cpp    # C++ program
# SRCEXTS   := .c .cpp # C/C++ program
SRCEXTS   := .cpp

INCLUDES = 
LIBPATH = 

# The flags used by the cpp (man cpp for more).
# CPPFLAGS  := -Wall -Werror # show all warnings and take them as errors
CPPFLAGS  := 

# The compiling flags used only for C.
# If it is a C++ program, no need to set these flags.
# If it is a C and C++ merging program, set these flags for the C parts.
CFLAGS    :=
CFLAGS    +=

# The compiling flags used only for C++.
# If it is a C program, no need to set these flags.
# If it is a C and C++ merging program, set these flags for the C++ parts.
CXXFLAGS  := -g -O0 -Wall -Werror -DDEBUG $(INCLUDES)
CXXFLAGS  += 

# The library and the link options ( C and C++ common).
LDFLAGS   := $(LIBPATH) 
LDFLAGS   += -rdynamic 

## Implict Section: change the following only when necessary.
##=============================================================================
# The C program compiler. Uncomment it to specify yours explicitly.
CC      = gcc

# The C++ program compiler. Uncomment it to specify yours explicitly.
#CXX     = g++

# Uncomment the 2 lines to compile C programs as C++ ones.
#CC      = $(CXX)
#CFLAGS  = $(CXXFLAGS)

# The command used to delete file.
#RM        = rm -f

## Stable Section: usually no need to be changed. But you can add more.
##=============================================================================
SHELL   = /bin/sh
SOURCES = $(foreach d,$(SRCDIRS),$(wildcard $(addprefix $(d)/*,$(SRCEXTS))))
OBJS    = $(foreach x,$(SRCEXTS), \
      $(patsubst %$(x),%.o,$(filter %$(x),$(SOURCES))))


#dirname=$(shell sh -c  '\
#	dir=`pwd | sed s/^.*\///` \
#	echo $$dir; \
#	exit; \
#')


DEPS    = $(patsubst %.o,%.d,$(OBJS))

.PHONY : all objs clean cleanall rebuild make_svn_version install print

all : main


# Rules for creating the dependency files (.d).
#---------------------------------------------------
%.d : %.c
	$(CC) -o $@ -MT $(patsubst %.c,%.o,$(<))   -MM -MD $(CFLAGS) $<

%.d : %.C
	$(CC) -o $@ -MT $(patsubst %.C,%.o,$(<))   -MM -MD $(CXXFLAGS) $<

%.d : %.cc
	$(CC) -o $@ -MT $(patsubst %.cc,%.o,$(<))   -MM -MD $(CXXFLAGS) $<

%.d : %.cpp
	$(CC) -o $@ -MT $(patsubst %.cpp,%.o,$(<))   -MM -MD $(CXXFLAGS) $<

%.d : %.CPP
	$(CC) -o $@ -MT $(patsubst %.CPP,%.o,$(<))   -MM -MD $(CXXFLAGS) $<

%.d : %.c++
	$(CC) -o $@ -MT $(patsubst %.c++,%.o,$(<))   -MM -MD $(CXXFLAGS) $<

%.d : %.cp
	$(CC) -o $@ -MT $(patsubst %.cp,%.o,$(<))   -MM -MD $(CXXFLAGS) $<

%.d : %.cxx
	$(CC) -o $@ -MT $(patsubst %.cxx,%.o,$(<))   -MM -MD $(CXXFLAGS) $<

# Rules for producing the objects.
#---------------------------------------------------
objs : $(OBJS)

%.o : %.c
	$(CC) -o $@ -c $(CPPFLAGS) $(CFLAGS) $<

%.o : %.C
	$(CXX) -o $@ -c $(CPPFLAGS) $(CXXFLAGS) $<

%.o : %.cc
	$(CXX) -o $@ -c $(CPPFLAGS) $(CXXFLAGS) $<

%.o : %.cpp
	$(CXX) -o $@ -c $(CPPFLAGS) $(CXXFLAGS) $<

%.o : %.CPP
	$(CXX) -o $@ -c $(CPPFLAGS) $(CXXFLAGS) $<

%.o : %.c++
	$(CXX -o $@ -c $(CPPFLAGS) $(CXXFLAGS) $<

%.o : %.cp
	$(CXX) -o $@ -c $(CPPFLAGS) $(CXXFLAGS) $<

%.o : %.cxx
	$(CXX) -o $@ -c $(CPPFLAGS) $(CXXFLAGS) $<

# Rules for producing the executable.
#----------------------------------------------
$(PROGRAM) : $(OBJS)
ifeq ($(strip $(SRCEXTS)), .c)  # C file
	$(CC) -o $(PROGRAM) $^ $(LDFLAGS)
else                            # C++ file
	$(CXX) -o $(PROGRAM) $^   $(LDFLAGS)
endif

main: main.o
	$(CXX) -o $(@) $^   $(LDFLAGS)

-include $(DEPS)

rebuild: clean all

clean :
	$(RM) $(OBJS) $(DEPS) main *.so

cleanall: clean
	@$(RM) $(PROGRAM) $(PROGRAM).exe


### End of the Makefile ##  Suggestions are welcome  ## All rights reserved ###
###############################################################################
