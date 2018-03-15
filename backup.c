#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>

//my .h files
#include "backup.h"
#include "date.h"


void backup()
{
    char source[] = "/var/www/html/live";
    char dest[] = "/var/www/html/backups";
    
    //lockAllFiles(source);
    
    char dateBuffer[80];
    char * buffer = date(dateBuffer);
    strcat(dest, buffer);
    printf("%s", dest);
    
    char* args[] = {"cp", "-R", source, dest, NULL};
    execv("/bin/cp", args);
    //unlockAllFiles(source);
}
