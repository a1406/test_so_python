from ctypes import *;

api = CDLL('./libinterface.so')
api.test_interface()

def py_event1(event_id, player):
    print "in py_event1, id =", event_id
    age = api.get_age(player)
    print "age =", age

def py_install( ):
    print "py_install"

   
pDownTextInfoFv = CFUNCTYPE(c_void_p, c_int, c_ulong)
pDownTextInfoHandle = pDownTextInfoFv(py_event1);
api.register_event(1, pDownTextInfoHandle);



