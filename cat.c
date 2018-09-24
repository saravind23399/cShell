#include "shell.h"
int main(int arg,char *argv[])
{
 int fp;
 char buf;
 fp=open(argv[1],O_RDONLY);
 if(fp<0) 
    printf("ERROR");
 else
  {
   while(read(fp,&buf,1)!=0)
   {
    printf("%c",buf);
   }
  }
  close(fp);
}
