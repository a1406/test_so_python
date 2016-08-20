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
	return (0);
}
};
