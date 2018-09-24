#include "shell.h"



void shell(char* username)
{
    printf("The UNIX Shell\n**************\n\n");
    while(1)
    {
        printf("theUnixShell@%s $ ",username);
        char line[100];
        gets(line);
        //printf("%s\n",line);
        //printf("%d\n",strlen(line));
        char* splitStrings[10]; //can store 10 words of 10 characters
        for(int i = 0 ; i <10 ; i++)
        {
            splitStrings[i]=malloc(10*sizeof(char));
        }
        int i,j,cnt;
        j=0; cnt=0;
        for(i=0;i<=(strlen(line));i++)
        {
            // if space or NULL found, assign NULL into splitStrings[cnt]
            if(line[i]==' '||line[i]=='\0')
            {
                splitStrings[cnt][j]='\0';
                cnt++;  //for next word
                j=0;    //for next word, init index to 0
            }
            else
            {
                splitStrings[cnt][j]=line[i];
                j++;
            }
        }
        splitStrings[cnt]=NULL;
        if(fork())
        {
            execv(splitStrings[0],splitStrings);
        }
        else
        {
            wait();
        }
    }
}

int main()
{
    shell("aravind");
}