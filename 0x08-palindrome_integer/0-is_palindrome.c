#include "palindrome.h"
#include <string.h>

/**
 * is_palindrome - function that checks whether or not a given unsigned
 * integer is a palindrome.
 * @n: unsigned number to evaluate
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	int i = 0, length = 0;
	char str_num[11] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\n'};

	if (n < 10)
		return (1);
	number_to_string(n, str_num);
	length = strlen(str_num) - 1;
	for (i = 0; i < length; i++)
	{
		if (str_num[i] != str_num[length])
			return (0);
		length--;
	}
	return (1);
}

/**
 * number_to_string - converts a number to a string
 * @number: number to convert
 * @string: char pointer to store string
 *
 * Return: void
 */

void number_to_string(unsigned long number, char *string)
{
	int pos = 0;
	unsigned long aux = 0, base = 10, char_aux = 48;

	if (number < 10)
	{
		string[0] = number + char_aux;
		string[1] = '\0';
		return;
	}
	for (pos = 0; number != 0; pos++)
	{
		aux = number % base;
		string[pos] = aux + char_aux;
		number /= base;
	}
	string[pos] = '\0';
}
