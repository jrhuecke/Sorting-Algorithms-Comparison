CC = clang
CFLAGS = -Wall -Werror -Wextra -Wpedantic
all: sorting

sorting: sorting.o set.o stats.o bubble.o shell.o stack.o quick.o queue.o
	$(CC) $(CFLAGS) -o sorting sorting.o set.o stats.o bubble.o shell.o stack.c quick.o queue.o

sorting.o: sorting.c
	$(CC) $(CFLAGS) -c sorting.c 

set.o: set.c
	$(CC) $(CFLAGS) -c set.c

stats.o: stats.c
	$(CC) $(CFLAGS) -c stats.c

bubble.o: bubble.c
	$(CC) $(CFLAGS) -c bubble.c

shell.o: shell.c
	$(CC) $(CFLAGS) -c shell.c

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

quick.o: quick.c
	$(CC) $(CFLAGS) -c quick.c

queue.o: queue.c
	$(CC) $(CFLAGS) -c queue.c

clean:
	rm -f *.o sorting

format:
	clang-format -i -style=file *.h *.c
