#include "main.h"
/**
 * is_printable - Checks if a char is printable.
 * @c: Char
 * Return: 1 if success, 0, otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * append_hexa_code - Append ascii in hex code to buffer
 * @buffer: Array of chars
 * @i: Index
 * @ascii_code: ASCII code
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}
/**
 * is_digit - Checks if a char is digit
 * @c: Char to be checked
 * Return: 1, if true, and 0, otherwise.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/**
 * convert_size_number - Casts a num to the specified size.
 * @num: Number to be casted
 * @size: Num indicating the type to be casted
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}
/**
 * convert_size_unsgnd - Casts a number to the specified size.
 * @num: Number to be casted
 * @size: Num indicating the size to be casted.
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
