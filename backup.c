#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>

//my .h files
#include "backup.h"
#include "date.h"
#include "lock.h"


void backup()
{
    char source[] = "/var/www/html/live";
    char dest[] = "/var/www/html/backups/";
    
    //lock
    lock(0700);
    
    char dateBuffer[80];
    char * buffer = date(dateBuffer);
    strcat(dest, buffer);
    printf("%s, %s", dest, dateBuffer);
    
    char* args[] = {"cp", "-R", source, dest, NULL};
    execv("/bin/cp", args);
    
    //unlock
    lock(0700);
}
