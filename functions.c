#include "main.h"
/**
 * print_char - Prints a char
 * @types: List a of args
 * @buffer: Buffer array
 * @flags: Calcs active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Num of chars printed
 */
int print_char(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_string - Prints a string
 * @types: List a of args
 * @buffer: Buffer array
 * @flags: Calcs active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: printed chars
 */
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int index, len = 0;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (index = width - len; index > 0; index--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (index = width - len; index > 0; index--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}
/**
 * print_percent - Prints the %
 * @types: List a of args
 * @buffer: Buffer array
 * @flags: Calcs active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Num of chars printed
 */
int print_percent(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}
/**
 * print_int - Print integer
 * @types: List a of args
 * @buffer: Buffer array
 * @flags: Calcs active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Num of chars printed
 */
int print_int(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int i = BUFF_SIZE - 2, is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int ((-1) * b));
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
/**
 * print_binary - Prints an unsigned num
 * @types: List a of args
 * @buffer: Buffer array
 * @flags: Calcs active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Num of chars printed
 */
int print_binary(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned int sum, index, m, n;
	unsigned int arr[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	arr[0] = n / m;

	for (index = 1; index < 32; index++)
	{
		m /= 2;
		arr[index] = (n / m) % 2;
	}
	for (index = 0, sum = 0, count = 0; index < 32; index++)
	{
		sum += arr[index];
		if (sum || index == 31)
		{
			char s = '0' + arr[index];

			write(1, &s, 1);
			count++;
		}
	}
	return (count);
}
