CC = gcc
objects = main.o update.o backup.o date.o lock.o audit.o
headers = update.h backup.h date.h lock.h audit.h

daemon : $(objects)
	$(CC) -o $@ $^ -lm
    
main.o : $(headers)
	$(CC) -g -c main.c
    
update.o : update.c
	$(CC) -c update.c
    
backup.o : backup.c
	$(CC) -c backup.c
    
date.o : date.c
	$(CC) -c date.c
    
lock.o : lock.c
	$(CC) -c lock.c

audit.o : audit.c
	$(CC) -c audit.c
clean:
	rm daemon $(objects)
