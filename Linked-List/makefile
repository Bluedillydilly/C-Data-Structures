CC=gcc
FLAGS=-Wextra -Wall -std=gnu99 -ggdb -lm
LIBS=-lncurses
sll=s_linked_list


_sll: $(sll).o
	$(CC) $(FLAGS) -o sll $(sll).o

$(sll).o: $(sll).c $(sll).h
	$(CC) -c $(FLAGS) $(sll).c

clean:
	rm *.o sll
