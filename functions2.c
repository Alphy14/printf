#include "main.h"
/**
 * print_pointer - Prints the val of a pointer variable
 * @types: List a of args
 * @buffer: Buffer array
 * @flags: Calcs active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Num of printed chars
 */
int print_pointer(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char padd = ' ', extra_c = 0;
	int index = BUFF_SIZE - 2, len = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void*);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	num_addrs = (unsigned long)addrs;
	while (num_addrs > 0)
	{
		buffer[index--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+';
	else if (flags & F_SPACE)
		extra_c = ' ', len++;
	index++;
	return (write_pointer(buffer, index, len, width, flags,
				padd, extra_c, padd_start));
}
/**
 * print_non_printable - Prints ascii codes in hexa
 * of non_printable chars.
 * @types: List a of args
 * @buffer: Buffer array
 * @flags: Calcs active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Num of printed chars
 */
int print_non_printable(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int index = 0, offset = 0;
	char *str = va_arg(types, char*);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[index] != '\0')
	{
		if (is_printable(str[index]))
			buffer[index + offset] = str[index];
		else
			offset += append_hexa_code(str[index], buffer, index + offset);
		index++;
	}
	buffer[index + offset] = '\0';
	return (write(1, buffer, index + offset));
}
/**
 * print_reverse - Prints reverse string
 * @types: List a of args
 * @buffer: Buffer array
 * @flags: Calcs active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: reversed string
 */
int print_reverse(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	char *str;
	int index, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);
	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}
	for (index = index - 1; index >= 0; index--)
	{
		char s = str[index];

		write(1, &s, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13string - Prints a string in rot13.
 * @types: List a of args
 * @buffer: Buffer array
 * @flags: Calcs active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Num of chars printed
 */
int print_rot13string(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int a, b;
	int count = 0;

	char in[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (b = 0; in[b]; b++)
		{
			if (in[b] == str[a])
			{
				x = out[b];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!(in[b]))
		{
			x = str[a];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
