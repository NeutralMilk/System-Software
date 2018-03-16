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
    
    struct stat st;
    
    char path[100] = "/var/ww/html/live";
    
    stat (path, &st);
    
    i = mode;
    
    int m = chmod(path, i);
    if(m < 0)
    {
        openlog("locklog", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_INFO, "Failed to lock files: %s", strerror(errno));
        closelog();
    }
    
}