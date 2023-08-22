#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

typedef struct format
{
	char *id;
	int (*f)();
} convert_match;

int _printf(const char *format, ...);
int printf_HEX(va_list val);
int printf_hex(va_list val);
int printf_bin(va_list val);
int printf_int(va_list args);
int _putchar(char c);
int printf_char(va_list val);
int printf_string(va_list val);
#endif
