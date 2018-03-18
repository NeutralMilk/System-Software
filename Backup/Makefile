CC = gcc
objects = backup.o
headers = 

backup : $(objects)
	$(CC) -o $@ $^ -lm
    
main.o : $(headers)
	$(CC) -g -c backup.c
    
clean:
	rm backup $(objects)
