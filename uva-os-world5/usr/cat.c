#include "user.h"

char buf[512];

void
cat(int fd)
{
  int n;

  // read until returning 0
  while((n = read(fd, buf, sizeof(buf))) > 0) {
    // printf("read %d bytes\n", n);
    if (write(1, buf, n) != n) {
      fprintf(2, "cat: write error\n");
      exit(1);
    }
  }
  if(n < 0){
    fprintf(2, "cat: read error\n");
    exit(1);
  }
}

int
main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 1){
    cat(0);
    exit(0);
  }
  
  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      fprintf(2, "cat: cannot open %s\n", argv[i]);
      exit(1);
    }  // else printf("open %s ok\n", argv[1]);
    cat(fd);
    close(fd);
  }
  exit(0);
}
