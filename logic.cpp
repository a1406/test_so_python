#include "comm_head.h"

static on_event_func all_event_func[4];

extern "C"
{
int install()
{
	printf("%s %d\n", __FUNCTION__, __LINE__);

	for (int i = 0; i < 100; ++i)
	{
		all_players[i].m_id = i;
		all_players[i].m_age = 10;
		all_players[i].m_name = (char *)"no name";				
	}

	void *so_game;
	so_game = dlopen("./libgame.so", RTLD_NOW);
	assert(so_game);
	install_func t = (install_func)dlsym(so_game, "install");
	assert(t);
	t();

	for (int i = 0;; ++i)
	{
		int event_id = i % 4;
		if (all_event_func[event_id])
		{
			all_event_func[event_id](event_id, &all_players[0]);
		}
		sleep(2);
	}
	
	return (0);
}

int register_event(int event_id, on_event_func func)
{
	assert(event_id >= 0 && event_id < 4);
	all_event_func[event_id] = func;
	return (0);
}

char *get_name(player *p)
{
	return p->m_name;
}
void set_name(player *p, char *name)
{
	p->set_name(name);
}
int get_age(player *p)
{
	return p->m_age;
}
void set_age(player *p, int age)
{
	p->set_age(age);
}
int get_id(player *p)
{
	return p->m_id;
}

player *get_player(int id)
{
	assert(id >= 0 && id < 100);
	return &all_players[id];
}
};
