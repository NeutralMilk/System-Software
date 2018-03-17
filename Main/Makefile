CC = gcc
objects = main.o update.o backup.o date.o lock.o
headers = update.h backup.h date.h lock.h

myprog : $(objects)
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
    
clean:
	rm -r myprog $(objects)
