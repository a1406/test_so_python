#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <assert.h>
#include "comm_head.h"

char *player::get_name()
{
	return m_name;
}
int player::get_age()
{
	return m_age;
}
int player::get_id()
{
	return m_id;
}
void player::set_name(char *name)
{
	m_name = strdup(name);
}
void player::set_age(int age)
{
	m_age = age;
}
void player::set_id(int id)
{
	m_id = id;
}

player all_players[100];
static void *so_logic;

int main(int argc, char *argv[])
{
    printf("%s %d\n", __FUNCTION__, __LINE__);
	
	so_logic = dlopen("./liblogic.so", RTLD_NOW);
	assert(so_logic);
	install_func t = (install_func)dlsym(so_logic, "install");
	assert(t);
	t();
	while (getchar() == 'x')
	{
		return (0);
	}
/*	
	for (int i = 0; i < 100; ++i)
	{
		all_players[i].m_id = i;
		all_players[i].m_age = 10;
		all_players[i].m_name = (char *)"no name";				
	}
*/	
    return 0;
}

