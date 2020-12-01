#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void print_each_i(int *a, int size)
{
	printf("{ ");
	for (int i = 0; i < size; i++)
	{
		printf("%i ", a[i]);
	}
	printf("}\n");
}

void print_each_s(char *s)
{
	// char* s = a;
	printf(":{");
	for (int i = 0; i < strlen(s); i++)
	{
		printf("%c ", s[i]);
	}
	printf("}\n");
}