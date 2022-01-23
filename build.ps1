gcc -c main.c
gcc -c ring_buffer.c

gcc -o executable main.o ring_buffer.o

./executable