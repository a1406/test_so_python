#include "comm_head.h"

void on_event_func1(int event_id, player *p)
{
	printf("%s: %s %d, id = %d\n", __FILE__, __FUNCTION__, __LINE__, p->get_id());
}
void on_event_func2(int event_id, player *p)
{
	printf("%s: %s %d, id = %d\n", __FILE__, __FUNCTION__, __LINE__, p->get_id());
}
void on_event_func3(int event_id, player *p)
{
	printf("%s: %s %d, id = %d\n", __FILE__, __FUNCTION__, __LINE__, p->get_id());
}
void on_event_func4(int event_id, player *p)
{
	printf("%s: %s %d, id = %d\n", __FILE__, __FUNCTION__, __LINE__, p->get_id());
}


extern "C"
{
int test_install()
{
	printf("%s: %s %d\n", __FILE__, __FUNCTION__, __LINE__);
//	register_event(0, on_event_func1);
//	register_event(1, on_event_func2);
//	register_event(2, on_event_func3);
//	register_event(3, on_event_func4);	
	return (0);
}
};
