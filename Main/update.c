#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <syslog.h>

//my .h file
#include "update.h"

void update()
{
    //source and destination
    char path[200];
    strcpy(path, "cp -u -a /var/www/html/intranet/. /var/www/html/live");
    
    //lock
    //lock(0700);
    
    int i = system(path);
    if(i < 0)
    {
        openlog ("assignment_log", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_INFO, "Website was not updated.");
        closelog();
    }
    else
    {
        openlog ("assignment_log", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_INFO, "Website was updated successfully.");
        closelog();
    }
    
    //unlock
    //lock(0777);
}
