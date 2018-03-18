// Orphan Example
// The child process is adopted by init process, when parent process dies.
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <syslog.h>
#include <sys/stat.h>
#include <time.h>
#include "update.h"
#include "backup.h"
#include <fcntl.h>

#define MAX_BUF 1024

int main()
{
    time_t now;
    struct tm newyear;
    double seconds;
    time(&now);  /* get current time; same as: now = time(NULL)  */
    newyear = *localtime(&now);
    newyear.tm_hour = 15;
    newyear.tm_min = 49;
    newyear.tm_sec = 0;

    // Implementation for Singleton Pattern if desired (Only one instance running)

    // Create a child process
    int pid = fork();

    if (pid > 0)
    {
        // if PID > 0 :: this is the parent
        // this process performs printf and finishes
        printf("Parent process");
        sleep(10);  // uncomment to wait 10 seconds before process ends
        exit(EXIT_SUCCESS);
    }
    else if (pid == 0)
    {
       // Step 1: Create the orphan process
       printf("Child process");

       // Step 2: Elevate the orphan process to session leader, to loose controlling TTY
       // This command runs the process in a new session
       if (setsid() < 0)
       {
            exit(EXIT_FAILURE);
       }

       // We could fork here again , just to guarantee that the process is not a session leader
       int pid = fork();
       if (pid > 0)
       {
          exit(EXIT_SUCCESS);
       }

       else
       {

          // Step 3: call umask() to set the file mode creation mask to 0
          // This will allow the daemon to read and write files
          // with the permissions/access required
          umask(0);

          // Step 4: Change the current working dir to root.
          // This will eliminate any issues of running on a mounted drive,
          // that potentially could be removed etc..
          if (chdir("/") < 0 ) { exit(EXIT_FAILURE); }

          // Step 5: Close all open file descriptors
          /* Close all open file descriptors */
          int x;
          for (x = sysconf(_SC_OPEN_MAX); x>=0; x--)
          {
             close (x);
          }

          while(1)
          {
             sleep(1);
             //printf("child 1: my parent is: %i\n", getppid());
             time(&now);
             seconds = difftime(now,mktime(&newyear));
             printf("\n%.f", seconds);
              
            //when the difference between the curent time and our desired time is 0, this will run.
             if (seconds == 0)
             {
                backup();
                update();
                audit();
            }

            //continuously looking out for a message from the backup and update.
            int fd;
            char * fifoFile = "/tmp/fifoFile";
            char buf[MAX_BUF];
            fd = open(fifoFile, O_RDONLY);
            read(fd,buf,MAX_BUF);
            if(strcmp(buf, "backup") == 0)
            {
                backup();
                audit();
            }
              
            if(strcmp(buf, "update") == 0)
            {
                update();
                audit();
            }
            close (fd);
          }
       }
    }

return 0;
}

