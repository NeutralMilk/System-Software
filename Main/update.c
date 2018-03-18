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
    char * path = "rsync -r /var/www/html/intranet/index.html /var/www/html/live/";
    
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
}
