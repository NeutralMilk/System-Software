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
    char * update_exec_path = "rsync -r /var/www/html/intranet/ /var/www/html/live/";
    
    if(system(update_exec_path) > 0)
    {
        openlog ("error_log", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_INFO, "Live website was not updated: %s", strerror(errno));
        closelog();
    }
}
