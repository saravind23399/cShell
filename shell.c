#include "shell.h"

void shell(char* username)
{
    while(1)
    {
        printf("theUnixShell@%s $ ",username);
        char line[100];
        gets(line);
        char* splitStrings[10]; 
        for(int i = 0 ; i <10 ; i++)
        {
            splitStrings[i]=malloc(10*sizeof(char));
        }
        int i,j,cnt;
        j=0; cnt=0;
        for(i=0;i<=(strlen(line));i++)
        {
            if(line[i]==' '||line[i]=='\0')
            {
                splitStrings[cnt][j]='\0';
                cnt++;  
                j=0;    
            }
            else
            {
                splitStrings[cnt][j]=line[i];
                j++;
            }
        }
        splitStrings[cnt]=NULL;
        if(strcmp("exit",splitStrings[0])!=0)
        {
            int status = 0;
            pid_t wpid;
            pid_t child = fork();
            if(child==0)
            {
                execv(splitStrings[0],splitStrings);
                return;
            }
            while ((wpid = wait(&status)) > 0);
        }
        else
        {
            printf("Logout\n");
            exit(EXIT_SUCCESS);
        }
    }
}

int search(char* username, char* password)
{
  FILE *fp;
  struct user it;
  int found=0;
  fp=fopen("users.bin","rb");
  while (1)
  {
    fread(&it,sizeof(it),1,fp);
    if (feof(fp))
      break;
    if (strcmp(it.name,username)==0 && strcmp(it.password,password)==0)
    {
      return 1;
    }
  }
    return 0;
}

int main()
{
    printf("The UNIX Shell\n**************\n\n");
    char uname[30];
    char password[30];
    int found = 0;
    for(int i = 0;i<3;i++)
    {
        printf("Username : ");
        scanf("%s",uname);
        printf("Password : ");
        scanf("%s",password);
        if(search(uname,password)==1)
        {
            fflush(stdin);
            found=1;
            break;
        }
    }
    if(found)
    {
        shell(uname);
    }
    return 0;
}