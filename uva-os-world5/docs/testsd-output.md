## Sample output (QEMU)

### boot message for test_sd() 
```
....
kernel.c:174 entering init
unittests.c:332 read 1 blk takes: 1 ms
unittests.c:339 Dumping the partition table
unittests.c:340 # Status Type  1stSector    Sectors
unittests.c:348 1 80     06            0     262080
unittests.c:348 2 00     00            0          0
unittests.c:348 3 00     00            0          0
unittests.c:348 4 00     00            0          0
unittests.c:361 read cur boot counter: 16777471
unittests.c:366 written 1 blk takes: 1 ms
```