#include "main.h"
/**
 * print_unsigned - Prints an unsigned num
 * @types: List a of args
 * @buffer: Buffer array
 * @flags: Calcs active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Num of printed chars
 */
int print_unsigned(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[index--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[index--] = (num % 10) + '0';
		num /= 10;
	}
	index++;
	return (write_unsignd(0, index, buffer, flags, width, precision, size));
}
/**
 * print_octal - Prints an unsigned num in octal
 * @types: List a of args
 * @buffer: Buffer array
 * @flags: Calcs active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Num of printed chars
 */
int print_octal(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int num0 = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[index--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[index--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && num0 != 0)
		buffer[index--] = '0';
	index++;
	return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - Prints an unsigned num in hexa
 * @types: List a of args
 * @buffer: Buffer array
 * @flags: Calcs active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Num of printed chars
 */
int print_hexadecimal(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - Prints an unsigned num in upper hexa
 * @types: List a of args
 * @buffer: Buffer array
 * @flags: Calcs active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Num of printed chars
 */
int print_hexa_upper(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}
/**
 * print_hexa - Prints a hexa num in upper or lower
 * @types: List a of args
 * @map_to: Array of vslues to map the nums to
 * @buffer: Buffer array
 * @flags: Calcs active flags
 * @flag_ch: Calcs active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Num of printed chars
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int num0 = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[index--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[index--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && num0 != 0)
	{
		buffer[index--] = flag_ch;
		buffer[index--] = '0';
	}
	index++;
	return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}