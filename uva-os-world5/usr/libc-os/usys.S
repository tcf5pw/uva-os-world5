# newlib glue. same as usys.S but we change func names to avoid collision 
# with newlib 

# generated by usys.py -- do not edit
#  ./usys.py  > user_sys.S       then manual edit by FL

#include "kernel/syscall.h" 

.globl syscall_fork
    syscall_fork:
    mov x8, #SYS_fork
    svc #0
    ret          
          

.globl syscall_exit
    syscall_exit:
    mov x8, #SYS_exit
    svc #0
    ret          
          

.globl syscall_wait
    syscall_wait:
    mov x8, #SYS_wait
    svc #0
    ret          
          

.globl syscall_pipe
    syscall_pipe:
    mov x8, #SYS_pipe
    svc #0
    ret          
          

.globl syscall_read
    syscall_read:
    mov x8, #SYS_read
    svc #0
    ret          
          

.globl syscall_write
    syscall_write:
    mov x8, #SYS_write
    svc #0
    ret          
          

.globl syscall_close
    syscall_close:
    mov x8, #SYS_close
    svc #0
    ret          
          

.globl syscall_kill
    syscall_kill:
    mov x8, #SYS_kill
    svc #0
    ret          
          

.globl syscall_exec
    syscall_exec:
    mov x8, #SYS_exec
    svc #0
    ret          
          

.globl syscall_open
    syscall_open:
    mov x8, #SYS_open
    svc #0
    ret          
          

.globl syscall_mknod
    syscall_mknod:
    mov x8, #SYS_mknod
    svc #0
    ret          
          

.globl syscall_unlink
    syscall_unlink:
    mov x8, #SYS_unlink
    svc #0
    ret          
          

.globl syscall_fstat
    syscall_fstat:
    mov x8, #SYS_fstat
    svc #0
    ret          
          

.globl syscall_link
    syscall_link:
    mov x8, #SYS_link
    svc #0
    ret          
          

.globl syscall_mkdir
    syscall_mkdir:
    mov x8, #SYS_mkdir
    svc #0
    ret          
          

.globl syscall_chdir
    syscall_chdir:
    mov x8, #SYS_chdir
    svc #0
    ret          
          

.globl syscall_dup
    syscall_dup:
    mov x8, #SYS_dup
    svc #0
    ret          
          

.globl syscall_getpid
    syscall_getpid:
    mov x8, #SYS_getpid
    svc #0
    ret          
          

.globl syscall_sbrk
    syscall_sbrk:
    mov x8, #SYS_sbrk
    svc #0
    ret          
          

.globl syscall_sleep
    syscall_sleep:
    mov x8, #SYS_sleep
    svc #0
    ret          
          

.globl syscall_uptime
    syscall_uptime:
    mov x8, #SYS_uptime
    svc #0
    ret          
          

.globl syscall_lseek
    syscall_lseek:
    mov x8, #SYS_lseek
    svc #0
    ret          
          
/* cf musl clone.s
    clone(func, stack, flags, arg, ptid, tls, ctid)
            x0,   x1,    w2,    x3,  x4,   x5,  x6

    syscall(SYS_clone, flags, stack, ptid, tls, ctid)
            x8,        x0,    x1,    x2,   x3,  x4 
*/
//quest: music player (finish usr/libc-simple/usys.S first)
.globl clone
.type clone, %function
clone:
    // align stack and save func,arg
    and x1,x1,#-16
    stp x0,x3,[x1,#-16]!

    // syscall
    uxtw x0,w2
    mov x2,x4
    mov x3,x5
    mov x4,x6
    mov x8,#SYS_clone
    svc #0

    cbz x0,1f
    // parent
    ret
    // child       cf: usr/libc-simple/usys.S
1: ldp x1,x0,[sp],#16 /* STUDENT_TODO: replace this */
    blr x1
    mov x8,#SYS_exit
    svc #0    


// semaphores 
.globl sys_semcreate
    sys_semcreate:
    mov x8, #SYS_semcreate
    svc #0
    ret

.globl sys_semfree
    sys_semfree:
    mov x8, #SYS_semfree
    svc #0
    ret

.globl sys_semp
    sys_semp:
    mov x8, #SYS_semp
    svc #0
    ret

.globl sys_semv
    sys_semv:
    mov x8, #SYS_semv
    svc #0
    ret