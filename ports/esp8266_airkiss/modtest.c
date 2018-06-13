/*
 * modtest.c
 *
 *  Created on: 2018Äê6ÔÂ19ÈÕ
 *      Author: Administrator
 */
#include <stdio.h>
#include "py/runtime.h"


mp_obj_t test_cb;

STATIC void cb_main(){
	mp_call_function_0(test_cb);
	printf("cb_main finish");
}

STATIC mp_obj_t testcb(mp_obj_t cb) {
	test_cb = cb;
	cb_main();
	return mp_const_true;
}

MP_DEFINE_CONST_FUN_OBJ_1(testcb_obj, testcb);


STATIC const mp_rom_map_elem_t test_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_test) },
    { MP_ROM_QSTR(MP_QSTR_testcb), MP_ROM_PTR(&testcb_obj) },

};

STATIC MP_DEFINE_CONST_DICT(test_module_globals, test_module_globals_table);

const mp_obj_module_t test_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&test_module_globals,
};
