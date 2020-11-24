#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
	printf("Elements of the int array:\n");
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%i ", a[i]);
	}
	printf("\n");
}

void string_lower(char* s){
	for (int i = 0; s[i]; i++){
		s[i] = tolower(s[i]);
	}
}

// int validate_guess(char *prev, char g)
// {

	
// 	int bFound = sizeof(find_chars(prev, g)) / sizeof(int);
// 	print("bFound should be 0 (false) or a positive int (true): %i", bFound);
// 	if (bFound > 0)
// 	{
// 		print("You have already guessed this letter. Try a different one");
// 		return 0;
// 	}

// 	return 1;
// }

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

	int num_tries = 8;
	char *answer = argv[1];
	string_lower(answer);
	char guess;
	char guesses[8];
	int *result;
	print_each_s(guesses);
	printf("Welcome to Hangman\n");
	printf("Word of the day is %s ):", answer);
	printf("You have chosen a word of length %i\n", strlen(answer));
	for (int i = 0; i < num_tries; i++)
	{
		switch (i)
		{
		case 0:
			printf("Guess a letter: ");
			break;
		default:
			printf("Guess again (%i remaining):", num_tries - i);
		}
		scanf(" %c", &guess);

		printf("\nYou guessed %c! \n", guess);
		result = find_chars(answer, guess);
		int res_len = sizeof(result) / sizeof(int);
		printf("Size of res length, %i\n", res_len);

		if (res_len = 0)
		{
			printf("There are no %c's in the word\n", guess);
		}
		else if (res_len == 1)
		{
			printf("There is 1 %c\n", guess);
		}
		else
		{
			printf("There are %i %c's\n", res_len, guess);
		}

		print_each_i(result);
		printf(" ");
	}

	return 0;
}