# Doubly Linked List - Print Elements

This project focuses on working with doubly linked lists in C. In this particular task, we will implement a function that prints all the elements of a doubly linked list.

## Resources

To complete this project, it is recommended to review the following resources:

- [What is a Doubly Linked List](https://en.wikipedia.org/wiki/Doubly_linked_list)

## Learning Objectives

By the end of this project, you should be able to:

- Understand the concept of a doubly linked list.
- Utilize doubly linked lists in your code.
- Seek and find relevant information independently.

## Requirements

- Allowed editors: vi, vim, emacs.
- All your files will be interpreted/compiled on Ubuntu 20.04 LTS using python3 (version 3.8.5).
- All your files should end with a new line.
- Include a `README.md` file at the root of the project folder.
- Your code should follow the Betty style. It will be checked using `betty-style.pl` and `betty-doc.pl`.
- Do not use global variables.
- Each file should contain no more than 5 functions.
- The only C standard library functions allowed are `malloc`, `free`, `printf`, and `exit`.
- Your function prototypes should be included in the header file `lists.h`.
- Don't forget to push your header file.
- All header files should have include guards.

## Data Structure

For this project, please use the following data structure:

```c
/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;

## Tasks
Implement the function size_t print_dlistint(const dlistint_t *h); that prints all the elements of a dlistint_t list.
The function should return the number of nodes in the list.
Your code will be compiled using the following command: gcc -Wall -Werror -Wextra -pedantic main.c <files>.c -o <output_file>
