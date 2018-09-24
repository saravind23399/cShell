    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <dirent.h>
    #include <time.h>
    #include <pwd.h>
    #include <grp.h>
    int main(int argc, char* argv[])
    {

        DIR *td;
        struct dirent *thefile;
        struct stat thestat;
        struct passwd *tf;
        struct group *gf;
        char buf[512];

        td = opendir(".");
        if (argc == 1 )
        {
        while((thefile = readdir(td)) != NULL)
        {
            if (strcmp(thefile->d_name,".")==0 || strcmp(thefile->d_name,"..")==0)
                continue;
            printf("\t%s", thefile->d_name);
        }
        printf("\n");
        }
        else if(argc==2 && strcmp(argv[1],"-l")==0)
        {
        while((thefile = readdir(td)) != NULL)
        {
            if (strcmp(thefile->d_name,".")==0 || strcmp(thefile->d_name,"..")==0)
                continue;
            sprintf(buf, "%s/%s", ".", thefile->d_name);
            stat(buf, &thestat);

            switch (thestat.st_mode & S_IFMT)
                {
                case S_IFBLK:
                printf("b");
                break;
                case S_IFCHR:
                printf("c");
                break;
                case S_IFDIR:
                printf("d");
                break;
                case S_IFIFO:
                printf("p");
                break;
                case S_IFLNK:
                printf("l");
                break;
                case S_IFSOCK:
                printf("s");
                break;
                default:
                printf("-");
                break;
                    }
            printf( (thestat.st_mode & S_IRUSR) ? " r" : " -");
            printf( (thestat.st_mode & S_IWUSR) ? "w" : "-");
            printf( (thestat.st_mode & S_IXUSR) ? "x" : "-");
            printf( (thestat.st_mode & S_IRGRP) ? "r" : "-");
            printf( (thestat.st_mode & S_IWGRP) ? "w" : "-");
            printf( (thestat.st_mode & S_IXGRP) ? "x" : "-");
            printf( (thestat.st_mode & S_IROTH) ? "r" : "-");
            printf( (thestat.st_mode & S_IWOTH) ? "w" : "-");
            printf( (thestat.st_mode & S_IXOTH) ? "x" : "-");
            printf("%d ", thestat.st_nlink);

            tf = getpwuid(thestat.st_uid);
            printf("%s ", tf->pw_name);

            gf = getgrgid(thestat.st_gid);
            printf("\t%s ", gf->gr_name);

            printf("\%zu",thestat.st_size);
            printf("\t%s", thefile->d_name);
            printf("\t%s", ctime(&thestat.st_mtime));

        }
        closedir(td);
    }
    else
    {
        printf("     Invalid command !\n");
        return 0;
    }
    }
