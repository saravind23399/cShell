#include "shell.h"

int main(int argc,char* argv[])
{
  int fp;
  char buf;
  fp=open(argv[2],O_RDONLY);
  if(fp < 0)
  {
    printf("No file Found\n");
  }
  else
  {
    int i=0;
    char temp[100];
    while(read(fp,&buf,1))
    {
      if(buf != '\n')
        {
        temp[i]=buf;
        }
        else
        {
         temp[i]='\0';
         if(strstr(temp,argv[1]) != NULL)
           {
            printf("%s",temp);
            printf("\n");
           }
           i=-1;
        } 
        i++;
    }
   }
  printf("\n");
  return 1;
}
