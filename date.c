#include <stdio.h>
#include "date.h"
#include <time.h>

char* date(char * buffer)
{
    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(buffer, 80, "%d_%m_%y", info);
    
    return buffer;
}