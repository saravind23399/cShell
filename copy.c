#include "shell.h"

int main(int arg,char *argv[])
{
 int source,destination;
 char buf;
 source=open(argv[1],O_RDONLY);
 destination=open(argv[2],O_WRONLY);
 if(source<0)
    printf("ERROR");
 else
  {
   while(read(source,&buf,1))
        {
        write(destination,&buf,1);
        }
   close(source);
   close(destination);
  }
}
