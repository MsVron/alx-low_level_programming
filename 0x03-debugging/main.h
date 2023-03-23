
#ifndef HOLBERTON_H_SEEN
#define HOLBERTON_H_SEEN
#include <stdio.h>

/**
 * positive_or_negative - checkes wheteher a number is positive or negative
 * @i: the number to be checked
 * Return: 0, 1, and -1 according to the sign
 */

void positive_or_negative(int i);

/**
 * largest_number - returns the largest of 3 numbers
 * @a: first integer
 * @b: second integer
 * @c: third integer
 * Return: largest number
 */

int largest_number(int a, int b, int c);

/**
 * convert_day - converts day of month to day of year, without accounting
 * for leap year
 * @month: month in number format
 * @day: day of month
 * Return: day of year
 */

int convert_day(int month, int day);

/**
 * print_remaining_days - takes a date and prints how many days are
 * left in the year, taking leap years into account
 * @month: month in number format
 * @day: day of month
 * @year: year
 * Return: void
 */

void print_remaining_days(int month, int day, int year);

#endif
