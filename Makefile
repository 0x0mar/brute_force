CC = gcc
CFLAGS = -Wall -g
LIBS = -lm
OBJ = main_caller.o allocate_numbers.o custom_number_operations.o

allocate_num: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

main_caller.c: allocate_numbers.c
	./copy_main.pl $<

