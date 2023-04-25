#include "main.h"
/**
 * get_flags - Calcs active flags
 * @format: Formatted string
 * @i: take a parameter
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
	int a, curr_i;
	int flags = 0;

	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (a = 0; FLAGS_ARR[a] != '\0'; a++)
		{
			if (format[curr_i] == FLAGS_ARR[a])
			{
				flags |= FLAGS_ARR[a];
				break;
			}
		}
		if (FLAGS_ARR[a] == 0)
			break;
	}
	*i = curr_i - 1;
	return (flags);
}

