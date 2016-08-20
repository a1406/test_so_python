#include "comm_head.h"

extern "C"
{
int logic_install()
{
	printf("%s: %s %d\n", __FILE__, __FUNCTION__, __LINE__);

	for (int i = 0; i < 100; ++i)
	{
		all_players[i].m_id = i;
		all_players[i].m_age = 10;
		all_players[i].m_name = (char *)"no name";				
	}

	void *so_test, *so_interface;

	so_interface = dlopen("./libinterface.so", RTLD_NOW | RTLD_GLOBAL);
	if (!so_interface)
		printf("%s\n", dlerror());
	assert(so_interface);

	so_test = dlopen("./libtest.so", RTLD_NOW);
	if (!so_test)
		printf("%s\n", dlerror());
	assert(so_test);
	install_func t = (install_func)dlsym(so_test, "test_install");
	assert(t);
	t();

	for (unsigned int i = 0;; ++i)
	{
		int event_id = i % 4;
		printf("fire event %d %p\n", event_id, all_event_func[event_id]);
		if (all_event_func[event_id])
		{
			all_event_func[event_id](event_id, &all_players[event_id]);
		}
		sleep(2);
	}
	
	return (0);
}

};
