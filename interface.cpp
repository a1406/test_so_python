#include "comm_head.h"

extern "C"
{
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

