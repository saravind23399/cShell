#include "shell.h"

void shell(char* username)
{
    printf("The UNIX Shell\n**************\n\n");
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
}

int main()
{
    shell("aravind");
}