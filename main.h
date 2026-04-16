#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

void flush_buffer(char buffer[], int *index);
void add_to_buffer(char buffer[], int *index, char c, int *count);

void print_string_buffer(char *str, char buffer[], int *index, int *count);
void print_special_string(char *str, char buffer[], int *index, int *count);

void print_number_buffer(long int n, char buffer[], int *index, int *count);
void print_binary_buffer(unsigned int n, char buffer[], int *index, int *count);
void print_unsigned_buffer(unsigned int n, char buffer[], int *index, int *count);

void print_octal_buffer(unsigned int n, char buffer[], int *index, int *count);
void print_hex_buffer(unsigned int n, int uppercase, char buffer[],
	int *index, int *count);
void print_pointer_buffer(void *ptr, char buffer[], int *index, int *count);

#endif
