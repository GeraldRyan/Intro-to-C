#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char HANG_STATES[7][10 * 9] =
		{
				"             +         +----     +----     +----     +----     +----     +----     +----  ",
				"             |         |         |   O     |   O     |   O     |   O     |   O     |   O  ",
				"             |         |         |         |   +     | --+     | --+--   | --+--   | --+--",
				"             |         |         |         |   |     |   |     |   |     |   |     |   |  ",
				"             |         |         |         |         |         |         |  /      |  / \\ ",
				"             |         |         |         |         |         |         |         |      ",
				"/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   "};

void print_each(int * a){
	printf("Elements of the array:\n");
	for (int i = 0; i< sizeof(a)/sizeof(int); i++){
		printf("%i ", a[i]);
	}
	printf("\n");
}

int *find_chars(char *s, char c)
{
	int locs[10];
	int inst = 0;
	for (int i = 0; i < strlen(s) - 1; i++)
	{
		// printf("answer: %s, i is %i, s[i] %c, char guess: %c\n", s, i, s[i], c);
		if (s[i] == c)
		{
			// printf("Matching\n");
			// printf("inst: %i  i %i \n", inst, i);
			locs[inst] = i;
			// printf("locs[inst] %i", locs[inst]);
			inst++;
		}
	}
	// printf("PRINTING EACH\n");
	// print_each(locs);
	// printf("LOCS: %i", locs);
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
	for (int i = 0; i < num_tries; i++)
	{
		printf("Guess a letter: ");
		scanf(" %c", &guess);
		printf("\nGuess: %c \n", guess);
		result = find_chars(answer, guess);
		printf("Results length is %i\n", sizeof(result)/sizeof(int));
		print_each(result);
		i++;
	}
	// printf("%s", HANG_STATES[2]);

	return 0;
}