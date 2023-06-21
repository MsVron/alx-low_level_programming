#!/bin/bash

# Get all the .c files in the current directory
c_files=$(find . -maxdepth 1 -type f -name '*.c')

# Compile the .c files into object files
object_files=""
for file in $c_files; do
    object_file="${file%.c}.o"
    gcc -c -fPIC "$file" -o "$object_file"
    object_files+=" $object_file"
done

# Create the dynamic library
gcc -shared -o liball.so $object_files

# Clean up object files
rm -f $object_files
