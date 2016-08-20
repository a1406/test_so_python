#ifndef __COMM_HEAD_H
#define  __COMM_HEAD_H
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <assert.h>
#include <unistd.h>

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
	int main_func(int n);
	
	typedef int (*install_func)();
	int install_logic();
	int uninstall_logic();

	int install_test();
	int uninstall_test();

		//为了方便python调用
	typedef void (*on_event_func)(int event_id, player *p); 
//event_id  0-3
	int register_event(int event_id, on_event_func func);
	
	char *get_name(player *p);
	void set_name(player *p, char *name);
	int get_age(player *p);
	void set_age(player *p, int age);
	int get_id(player *p);
		//0-99
	player *get_player(int id);
	
};

#endif /*   */
