#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char **argv) {
   if (argc < 2) {
       printf("type error!\n");
   }
   else {
       sleep(atoi(argv[1]));
   }
   exit(0);
}
