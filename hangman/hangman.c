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

void print_each_i(int *a, int size)
{
	printf("{ ");
	for (int i = 0; i < size; i++)
	{
		printf("%i ", a[i]);
	}
	printf("}\n");
}

// void reveal_it(char *word, int *locations)
// {
// 	for (int i = 0; i < strlen(word); i++)
// 	{
// 		if (i == locations)
// 		{

// 			printf(word[i]);
// 		}
// 		else
// 		{
// 			printf("-");
// 		}
// 		locations++;
// 	}
// 	printf("\n");
// }

void string_lower(char *s)
{
	for (int i = 0; i < strlen(s); i++)
	{
		s[i] = tolower(s[i]);
	}
}

void append_and_order(int *results, int res_length, int *all_found, int *size_all)
{
	printf("FIRST PASS ALL FOUND\n");
	print_each_i(all_found, *size_all);
	printf("size of all found %i\n", *size_all);
	printf("RESULTS THIS TIME\n");
	print_each_i(results, res_length);
	printf("length of results %i\n", res_length);

	all_found = (int*) realloc(all_found,sizeof(int)*(res_length + *size_all));
	
	for (int i = 0; i<res_length; i++){
		all_found[*size_all+i] = results[i];
	}
	*size_all +=res_length;
	printf("NOW ALL FOUND AGAIN\n");
	print_each_i(all_found, *size_all);
	printf("size of all found %i\n", *size_all);

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

int *find_chars(char *s, char c, int *size)
{
	int inst = 0;
	int *locs = malloc(sizeof(int)); // 0
	// printf("%s is string; Stringlength is %lu\n", s, strlen(s));
	for (int i = 0; i < strlen(s); i++)
	{
		// printf("i=%i of length=%lu s[i]=%c\n", i, strlen(s), s[i]);
		// printf("TRUE OR FALSE %c = %c = %i\n", c, s[i], c == s[i]);
		// int equal = c==s[i];
		// printf("Equal %i", equal);
		if (c == s[i])
		{
			// printf("ran\n");
			locs = (int *)realloc(locs, sizeof(int) * (inst + 1)); // 1, 2, 3, 4,
			locs[inst] = i;
			inst++;
		}
	}
	*size = inst;
	// printf("SIZE %i\n", *size);
	return locs;
}
int validate_guess(char *previous, char g) // this is returning a 1 and should return a 0
{

	int bFound;
	int size;
	int *locs = find_chars(previous, g, &size);
	// printf("Size is %u\n", size); // so good so far.
	// print_each_i(locs, size);
	bFound = size;
	// printf("bFound should be 0 (pass) or a positive int (fail): %i\n", bFound);
	if (bFound > 0)
	{
		printf("You have already guessed this letter. Try a different one!\n\n");
		return 0;
	}
	else
	{
		printf("Good Guess. Let's see...\n");
	}
	return 1;
}

int main(int argc, char *argv[])
{
	/* Your code here */

	int NUM_TRIES = 8;
	int *all_found = (int *)malloc(1);
	int size_all = 0;
	char *answer = argv[1];
	string_lower(answer);
	char guess;
	char *previous = (char *)malloc(sizeof(char));
	printf("Welcome to Hangman. ");
	printf("Can you guess the word of the day?\n");
	printf("You have chosen a word of %lu letters.\n", strlen(answer));
	for (int i = 0; i < NUM_TRIES; i++)
	{
		printf("\nRound %i!\n", i + 1);
		printf("previous letters guessed: %s\n\n", previous);
		while (1)
		{
			switch (i)
			{
			case 0:
				printf("Guess a letter: ");
				break;
			default:
				printf("Guess again (%i remaining):", NUM_TRIES - i);
			}
			scanf(" %c", &guess);
			guess = tolower(guess);
			// int x = validate_guess(previous, guess);
			// printf("Validate Guess %i\n", x);
			if (validate_guess(previous, guess))
			{
				printf("Checking your answer... \n");
				// add valid guess to list of previousious guesses
				previous[i] = guess;
				previous = (char *)realloc(previous, sizeof(char) * (i + 1));
				previous[i] = guess;
				// print_each_s(previous);
				break;
			}
		}
		int *result;
		int result_size;
		result = find_chars(answer, guess, &result_size);
		int res_len = result_size;
		// printf("Size of res length, %i\n", res_len);

		if (res_len == 0)
		{
			printf("There are no %c's in the word\n", guess);
		}
		else if (res_len == 1)
		{
			printf("There is 1 %c!\n", guess);
			append_and_order(result, res_len, all_found, &size_all); // right now just prints. later it will append and order. 
		}
		else if (res_len > 1)
		{
			// printf(res_len);
			printf("There are %d %c's!!\n", res_len, guess);
			append_and_order(result, res_len, all_found, &size_all);

		}

		// print_each_i(result, result_size);
		printf(" ");
	}

	return 0;
}