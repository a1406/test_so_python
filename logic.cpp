#include "comm_head.h"
#include <python2.7/Python.h>

void printDict(PyObject* obj)
{
	if (!PyDict_Check(obj))
		return;
	PyObject *k, *keys;
	keys = PyDict_Keys(obj);
	for (int i = 0; i < PyList_GET_SIZE(keys); i++)
	{
		k = PyList_GET_ITEM(keys, i);
		char* c_name = PyString_AsString(k);
		printf("%s\n", c_name);
	}
}

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

	for (unsigned int i = 0; i < 10; ++i)
	{
		int event_id = i % 4;
		printf("fire event %d %p\n", event_id, all_event_func[event_id]);
		if (all_event_func[event_id])
		{
			all_event_func[event_id](event_id, &all_players[event_id]);
		}

		if (i == 2)
		{
			Py_Initialize();
			if (!Py_IsInitialized())
			{
				printf("py initialize failed\n");
				return -1;
			}

			PyRun_SimpleString("import sys");
			PyRun_SimpleString("sys.path.append('./')"); 

			PyObject* pModule = PyImport_ImportModule("testpy");
			if (!pModule)
			{
				printf("Cant open python file!\n");
				return (0);
			}
			PyObject* pDict = PyModule_GetDict(pModule);
			if (!pDict)
			{
				printf("Cant find dictionary.\n");
				return -1;
			}
			PyObject* pFunHi = PyDict_GetItemString(pDict, "py_install");
			if (!pFunHi)
			{
				printDict(pDict);
				return -1;
			}
			PyObject_CallFunction(pFunHi, (char *)"");

			Py_DECREF(pFunHi); 
		}
		sleep(2);
	}

//	Py_DECREF(pDict);  	
//	Py_DECREF(pModule);  
//	Py_Finalize();  
	
	return (0);
}

};
