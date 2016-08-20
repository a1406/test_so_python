#include "comm_head.h"

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

	for (;;)
	{
		sleep(2);
	}
	
	return (0);
}
};
