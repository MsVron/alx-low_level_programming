# Dynamic Library Project

This project aims to provide a comprehensive understanding of dynamic libraries, their creation, usage, and the differences between static and shared libraries. It also covers the basic usage of the `nm`, `ldd`, and `ldconfig` commands. By completing this project, you will gain the knowledge and skills necessary to explain these concepts without relying on external resources.

## Learning Objectives

By the end of this project, you will be able to:

- Understand what dynamic libraries are and how they work
- Create dynamic libraries on Linux
- Utilize dynamic libraries in your programs
- Grasp the concept of environment variable `$LD_LIBRARY_PATH` and its role
- Distinguish between static and shared libraries and their pros and cons
- Use `nm` to examine symbols in object files and libraries
- Use `ldd` to check library dependencies
- Use `ldconfig` to manage the cache of shared library paths

## Resources

Before diving into the project, it is recommended to review the following resources:

- [Difference between Dynamic and Static Library (Static and Dynamic Linking)](https://www.geeksforgeeks.org/difference-between-static-and-dynamic-library/)
- [How to Create Dynamic Libraries on Linux](https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html)

## Requirements

### C

- Editors allowed: vi, vim, emacs
- Compilation: Ubuntu 20.04 LTS using gcc with the following options: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All source code files should end with a new line
- A `README.md` file, placed at the root of the project folder, is mandatory
- Your code should follow the Betty style guidelines. You can use `betty-style.pl` and `betty-doc.pl` for verification.
- Avoid using global variables
- Each C file should contain no more than 5 functions
- Standard library functions like `printf`, `puts`, etc. are forbidden. Instead, you can use the provided `_putchar` function.
- Please note that you don't need to include the `_putchar.c` file in your repository, as we will provide our own during evaluation.

### Bash

- Editors allowed: vi, vim, emacs
- Scripts will be tested on Ubuntu 20.04 LTS
- All script files should end with a new line
- The first line of each script file should be exactly `#!/bin/bash`
- Include a `README.md` file at the root of the project folder, describing the purpose of each script
- All script files must be executable

## Copyright - Plagiarism

Please note that solutions for the tasks in this project should be developed independently. Copying and pasting someone else's work or publishing project content is strictly prohibited. Any form of plagiarism will result in removal from the program.

Best of luck with the project! Feel free to reach out if you have any questions or need assistance.
