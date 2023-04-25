#imclude "main.h"
/**
 * print_buffer - Prints the content of the buffer,
 * if it exists.
 * @buffer: Array of chars
 * @buff_ind: Buffer index
 * Return: void
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
/**
 * _printf - Returns the number of chars printed,
 * excluding the \0.
 * @format: Character string
 * Return: Printed chars, excluding \0.
 */
int _printf(const char *format, ...)
{
	int index, flags, width, precision, size;
	int printed_chars = 0, printed = 0, buff_ind = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (index = 0; format && format[index] != '\0'; index++)
	{
		if (format[index] != '%')
		{
			buffer[buff_ind++] = format[index];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &index);
			width = get_width(format, &index, args);
			precision = get_precision(format, &index, args);
			size = get_size(format, &index);
			index++;
			printed = handle_print(format,
					&index, args, buffer, flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(args);
	return (printed_chars);
}
