#!/bin/bash

# compile all .c files into .o files
gcc -Wall -Werror -Wextra -pedantic -c *.c

# create the static library from the .o files
ar -rc liball.a *.o

# index the static library
ranlib liball.a

# clean up the .o files
rm *.o
