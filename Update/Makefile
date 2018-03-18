CC = gcc
objects = update.o
headers = 

update : $(objects)
	$(CC) -o $@ $^ -lm
    
main.o : $(headers)
	$(CC) -g -c update.c
    
clean:
	rm update $(objects)
