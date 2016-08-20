#include "comm_head.h"

void on_event_func1(int event_id, player *p)
{
	printf("%s: %s %d, id = %d, name = %s, age = %d\n", __FILE__, __FUNCTION__, __LINE__, p->get_id(), get_name(p), get_age(p));
}
void on_event_func2(int event_id, player *p)
{
	printf("%s: %s %d, id = %d, name = %s, age = %d\n", __FILE__, __FUNCTION__, __LINE__, p->get_id(), get_name(p), get_age(p));	
}
void on_event_func3(int event_id, player *p)
{
	printf("%s: %s %d, id = %d, name = %s, age = %d\n", __FILE__, __FUNCTION__, __LINE__, p->get_id(), get_name(p), get_age(p));	
}
void on_event_func4(int event_id, player *p)
{
	printf("%s: %s %d, id = %d, name = %s, age = %d\n", __FILE__, __FUNCTION__, __LINE__, p->get_id(), get_name(p), get_age(p));	
}


extern "C"
{
int test_install()
{
	printf("%s: %s %d\n", __FILE__, __FUNCTION__, __LINE__);
	main_func(100);
	
	register_event(0, on_event_func1);
	register_event(1, on_event_func2);
	register_event(2, on_event_func3);
	register_event(3, on_event_func4);

	player *p = get_player(2);
	set_name(p, (char *)"222");
	set_age(p, 22);

	p = get_player(3);
	set_name(p, (char *)"333");
	set_age(p, 33);	
	return (0);
}
};
