#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
    char * fifoFile = "/tmp/fifoFile";
    
    //create the FIFO (named pipe)
    mkfifo(fifoFile, 0666);
    
    char msg[] = "backup";
    fd = open (fifoFile, O_WRONLY);
    write(fd, msg, sizeof(msg));
    close(fd);
    unlink(fifoFile);
    return 0;
}