# 0x1E. C - Search Algorithms

This repository contains C programs that implement various search algorithms. The project aims to reinforce the understanding of search algorithms, including linear search and binary search, and when to choose the best search algorithm based on specific needs.

## Learning Objectives

By completing this project, you will gain knowledge in the following areas:

- Understanding what a search algorithm is.
- Familiarity with linear search and binary search.
- Determining the best search algorithm based on specific requirements.

## Requirements

- Allowed editors: vi, vim, emacs.
- All files will be compiled on Ubuntu 20.04 LTS using gcc with specific options: -Wall -Werror -Wextra -pedantic -std=gnu89.
- All files should end with a new line.
- A README.md file at the root of the project folder is mandatory.
- Code should follow the Betty style, checked using betty-style.pl and betty-doc.pl.
- No global variables are allowed.
- No more than 5 functions per file.
- Only the printf function from the standard library is allowed; calls to functions like strdup, malloc, etc., are forbidden.
- Prototypes of all functions should be included in the header file named `search_algos.h`.
- Don't forget to push the header file.
- All header files should be include guarded.

## Usage

To compile the programs, use the provided compilation command for each file. For example:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-linear.c -o linear_search
```

Run the compiled program:

```bash
./linear_search
```

## Big O Notations

In some files, you will be required to write big O notations. Please use the following format:

- O(1)
- O(n)
- O(n!)
- n*m -> O(nm)
- n square -> O(n^2)
- sqrt n -> O(sqrt(n))
- log(n) -> O(log(n))
- n * log(n) -> O(nlog(n))

## Disclaimer

Copying and pasting someone else’s work is strictly forbidden and may result in removal from the program. Plagiarism is not tolerated. You are encouraged to come up with solutions to meet the learning objectives mentioned above.