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

extern "C"
{
int main_func(int n)
{
	printf("%s %d n = %d\n", __FUNCTION__, __LINE__, n);
	return (0);
}
};
	
int main(int argc, char *argv[])
{
    printf("%s %d\n", __FUNCTION__, __LINE__);
	
	so_logic = dlopen("./liblogic.so", RTLD_NOW | RTLD_GLOBAL);
	assert(so_logic);
	install_func t = (install_func)dlsym(so_logic, "logic_install");
	assert(t);
	t();
	int c = getchar();
	printf("getchar %d\n", c);
	return (0);
}

