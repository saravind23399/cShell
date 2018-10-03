#include "shell.h"

void append(char* username, char* password)
{
  struct user it;
  int i;
  FILE *fp;
  fp=fopen("users.bin","ab");
  if (fp==NULL)
  {
    printf("Error opening file. Exiting...\n");
    exit(1);
  }
  strcpy(it.name,username);
  strcpy(it.password,password);  
  fwrite(&it,sizeof(struct user),1,fp);
  fclose(fp);
  printf("User added...\n");
}

int main()
{
    printf("Enter the username : ");
    char uname[30];
    scanf("%s",uname);
    printf("Enter the password : ");
    char password[30];
    scanf("%s",password);
    append(uname,password);
}