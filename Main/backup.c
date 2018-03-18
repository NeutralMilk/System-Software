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
    
    char path[200];
    strcpy(path, "cp -r /var/www/html/live /var/www/html/backups/");
    strcat(path, buffer);
    int i = system(path);
    
    if(i < 0)
    {
        openlog ("assignment_log", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_INFO, "Website was not backed up.");
        closelog();
    }
    else
    {
        openlog ("assignment_log", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_INFO, "Website was backed up successfully.");
        closelog();
    }
    
    //unlock
    lock(0777);
}
