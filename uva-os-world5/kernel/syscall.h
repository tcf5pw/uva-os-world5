// from xv6. to be included by the kernel and user code (via source-to-source gen)

// System call numbers
// 0 .. unused??
#define SYS_fork    1
#define SYS_exit    2
#define SYS_wait    3
#define SYS_pipe    4
#define SYS_read    5
#define SYS_kill    6
#define SYS_exec    7
#define SYS_fstat   8
#define SYS_chdir   9
#define SYS_dup    10
#define SYS_getpid 11
#define SYS_sbrk   12
#define SYS_sleep  13
#define SYS_uptime 14
#define SYS_open   15
#define SYS_write  16
#define SYS_mknod  17
#define SYS_unlink 18
#define SYS_link   19
#define SYS_mkdir  20
#define SYS_close  21       
// below not in xv6
#define SYS_lseek  22       
#define SYS_clone  23       
#define SYS_semcreate  24
#define SYS_semfree  25
#define SYS_semp  26
#define SYS_semv  27

#define __NR_syscalls	 28  // == highest syscall_no + 1
