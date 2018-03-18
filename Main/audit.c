#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <syslog.h>
#include <sys/stat.h>
#include "audit.h"
#include <fcntl.h>

void audit()
{

    char * audit_ = {"ausearch -f /var/www/html/intranet> /var/www/html/accesslog.txt"};
    //perform the audit
    int i = system(audit_);
    
    if(i < 0)
    {
        openlog ("assignment_log", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_INFO, "Audit failed.");
        closelog();
    }
    else
    {
        openlog ("assignment_log", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_INFO, "Audit complete.");
        closelog();
    }
        
    
}