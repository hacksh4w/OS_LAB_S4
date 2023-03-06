#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define FILE 8
#define FOLDER 84
void printFiles(char path[100], int tabCount)
{
    struct dirent *dptr;
    DIR *dirp;
    if ((dirp = opendir(path)) == NULL)
    {
    }
    //printf("%s %d \n", path, tabCount);
    
    while (dptr = readdir(dirp))
    {
        if (strcmp(dptr->d_name, ".") == 0)
        {
            continue;
        }
        if (strcmp(dptr->d_name, "..") == 0)
        {
            continue;
        }
        for(int i=0; i<tabCount; i++)
    	    printf("\t");
        printf("%s", dptr->d_name);
        if (dptr->d_type == FILE)
        {
            printf("\n");
        }
        else
        {
            printf("/\n");
            strcat(path, "/");
            strcat(path, dptr->d_name);
            printFiles(path, tabCount+1);
        }
    }
}

int main()
{
    char rootPath[100] = ".";
    printFiles(rootPath, 0);
    return 0;
}
