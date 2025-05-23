// for c++ apps
// https://wiki.osdev.org/Calling_Global_Constructors#GNU_Compiler_Collection_-_System_V_ABI

/* crtn.c for ARM - BPABI - use -std=c99 */
typedef void (*func_ptr)(void);
 
func_ptr _init_array_end[0] __attribute__ ((used, section(".init_array"), aligned(sizeof(func_ptr)))) = { };
func_ptr _fini_array_end[0] __attribute__ ((used, section(".fini_array"), aligned(sizeof(func_ptr)))) = { };