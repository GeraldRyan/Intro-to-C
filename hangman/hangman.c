#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char HANG_STATES[7][10 * 9 + 1] =
		{
				"             +         +----     +----     +----     +----     +----     +----     +----  \0",
				"             |         |         |   O     |   O     |   O     |   O     |   O     |   O  \0",
				"             |         |         |         |   +     | --+     | --+--   | --+--   | --+--\0",
				"             |         |         |         |   |     |   |     |   |     |   |     |   |  \0",
				"             |         |         |         |         |         |         |  /      |  / \\ \0",
				"             |         |         |         |         |         |         |         |      \0",
				"/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   \0"};

void print_each_i(int *a)
{
	printf("Elements of the array:\n");
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%i ", a[i]);
	}
	printf("\n");
}
void print_each_s(char *s)
{
	// char* s = a;
	printf("String %s\n", s);
	printf("Elements of the string:\n");
	for (int i = 0; i < strlen(s); i++)
	{
		printf("%c ", s[i]);
	}
	printf("\n");
}

int *find_chars(char *s, char c)
{
	int locs[10];
	int inst = 0;
	for (int i = 0; i < strlen(s) - 1; i++)
	{
		if (s[i] == c)
		{

			locs[inst] = i;
			inst++;
		}
	}
	return locs;
}

int main(int argc, char *argv[])
{
	/* Your code here */
	printf("Welcome to Hangman\n");
	int num_tries = 8;
	char *answer = argv[1];
	char guess;
	char guesses[8];
	int *result;
	print_each_s(answer);
	for (int i = 0; i < num_tries; i++)
	{
		printf("Guess a letter: ");
		scanf(" %c", &guess);
		printf("\nGuess: %c \n", guess);
		result = find_chars(answer, guess);
		printf("Results length is %i\n", sizeof(result) / sizeof(int));
		print_each_i(result);
		printf(" ");
		i++;
	}

	return 0;
}