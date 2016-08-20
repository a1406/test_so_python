#ifndef __COMM_HEAD_H
#define  __COMM_HEAD_H
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <assert.h>

class player
{
public:
	char *get_name();
	int get_age();
	int get_id();
	void set_name(char *name);
	void set_age(int age);
	void set_id(int id);
	int m_id;
	char *m_name;
	int m_age;
};

extern player all_players[100];

extern "C"
{
	typedef int (*install_func)();
	int install_logic();
	int uninstall_logic();

	int install_test();
	int uninstall_test();	
};

#endif /*   */
