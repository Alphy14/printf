#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);

int handle_print(const char *fmt, int *i, va_list list,
		char buffer[], int flags, int width, int precision, int size);

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
/* SIZES */
#define S_SHORT 1
#define S_LONG 2

/**
 * struct fmt - operation structure
 * @fmt: Format
 * @func: Function
 */
struct fmt
{
	char fmt;
	int (*func)(va_list, char[], int, int, int, int);
};

typedef struct fmt fmt_t;

/* FUNCTIONS TO PRINT CHARS AND STRINGS */
int print_char(va_list types, char buffer[], int flags,
		int width, int precision, int size);

int print_percent(va_list types, char buffer[], int flags
		int width, int precision, int size);

int print_string(va_list types, char buffer[], int flags,
		int width, int precision, int size);

/* FUNCTIONS TO PRINT NUMBERS */
int print_int(va_list types, char buffer[], int flags,
		int width, int precision, int size);

int print_binary(va_list types, char buffer[], int flags,
		int width, int precision, int size);

int print_unsigned(va_list types, char buffer[], int flags,
		int width, int precision, int size);

int print_octal(va_list types, char buffer[], int flags,
		int width, int precision, int size);

int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size);

/* FUNCTION TO PRINT MEMORY ADDRESS */
int print_pointer(va_list types, char buffer[], int flags,
		int width, int precision, int size);

/* FUNCTIONS TO HANDLE OTHER SPECIFIERS */
int get_flags(const char *format, int *i);

int get_width(const char *format, int *i, va_list list);

int get_precision(const char *format, int *i, va_list list);

int get_size(const char *format, int *i);

/*FUNCTION TO PRINT STRING IN REVERSE */
int print_reverse(va_list types, char buffer[], int flags,
		int width, int precision, int size);

/* FUNCTION TO PRINT A STRING IN ROT13 */
int print_rot13string(va_list types, char buffer[]
		int flags, int width, int precision,
		int size);

/* WIDTH HANDLER FUNCTIONS */
int handle_write_char(char c, char buffer[], int flags,
		int width, int precision, int size);

int write_number(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);

int write_num(int ind, char buffer[], int flags,
		int width, int precision, int length,
		char padd, char extra_c);

int write_pointer(char buffer[], int ind, int length
		int width, int flags, char padd,
		char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind, char buffer[],
		int flags, int width, int precision,
		int size);

/* FUNCTION TO PRINT NON-PRINTABLE CHARACTERS */
int print_non_printable(va_list types, char buffer[]
		int flags, int width, int precision,
		int size);

/* UTILS */
int is_printable(char);

int append_hexa_code(char, char[], int);

long int convert_size_number(long int num, int size);

int is_digit(char);

long int conver_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
