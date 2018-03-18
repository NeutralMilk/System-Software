#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <syslog.h>
#include <errno.h>
#include <setjmp.h>

#include "lock.h"

void lock(int mode)
{
    int i;
    int exception_int;
    
    char path[100] = "/var/www/html/";
            
    i = chmod(path, mode);
    if(i < 0)
    {
        openlog ("assignment_log", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_INFO, "Lock unsuccessful");
        closelog();
    }
    else
    {
        openlog ("assignment_log", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_INFO, "Lock successful.");
        closelog();
    }
    
}