#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "comm_head.h"

class player
{
public:
	char *get_name()
	{
		return m_name;
	}
	int get_age()
	{
		return m_age;
	}
	int get_id()
	{
		return m_id;
	}
	void set_name(char *name)
	{
		m_name = strdup(name);
	}
	void set_age(int age)
	{
		m_age = age;
	}
	void set_id(int id)
	{
		m_id = id;
	}

	int m_id;
	char *m_name;
	int m_age;
};

static player all_players[100];

int main(int argc, char *argv[])
{
    printf("%s %d\n", __FUNCTION__, __LINE__);
	for (int i = 0; i < 100; ++i)
	{
		all_players[i].m_id = i;
		all_players[i].m_age = 10;
		all_players[i].m_name = (char *)"no name";				
	}
    return 0;
}

