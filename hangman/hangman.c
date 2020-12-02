#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../quicksort/quicksort.c"
#include "./utilities.h"

char HANG_STATES[7][10 * 9 + 1] =
		{
				"             +         +----     +----     +----     +----     +----     +----     +----  \0",
				"             |         |         |   O     |   O     |   O     |   O     |   O     |   O  \0",
				"             |         |         |         |   +     | --+     | --+--   | --+--   | --+--\0",
				"             |         |         |         |   |     |   |     |   |     |   |     |   |  \0",
				"             |         |         |         |         |         |         |  /      |  / \\ \0",
				"             |         |         |         |         |         |         |         |      \0",
				"/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   \0"};

void reveal_word(char *word, int *locations)
{
	printf("The Word is: ");
	for (int i = 0; i < strlen(word); i++)
	{
		if (i + 1 == *locations) // 1-indexes to avoid null pointer false positive.
		{
			// printf("STARTING TO REVEAL WORD. %i %i %c locations pointer %i\n", i, strlen(word), word[i], *locations);

			printf("%c", word[i]);
			locations++;
		}
		else
		{
			printf("-");
		}
	}
	printf("\n");
}

void append_and_order(int *results, int res_length, int *all_found, int *size_all_found)
{
	// printf("FIRST PASS ALL FOUND\n");
	// print_each_i(all_found, *size_all_found);
	// printf("size of all found %i\n", *size_all_found);
	// printf("RESULTS THIS TIME\n");
	// print_each_i(results, res_length);
	// printf("length of results %i\n", res_length);

	all_found = (int *)realloc(all_found, sizeof(int) * (res_length + *size_all_found));

	for (int i = 0; i < res_length; i++)
	{
		all_found[*size_all_found + i] = results[i];
	}
	*size_all_found += res_length;
	// printf("NOW ALL FOUND AGAIN\n");
	// print_each_i(all_found, *size_all_found);
	// printf("size of all found %i\n", *size_all_found);
	// printf("ALL FOUND SORTED\n");
	// quicksort(all_found, 0, *size_all_found - 1);
	// print_each_i(all_found, *size_all_found);

	// Botom line quicksort works
	// int array[6] = {5, 4, 3, 2, 1, 0};
	// printf("ARRAY NOT QUICKSORTED\n");
	// print_each_i(array, 6);
	// quicksort(array, 0, 5);
	// printf("The array is quicksorted");
	// print_each_i(array, 6);
}

int guess_word(char *guess, char *answer)
{
	if (strcmp(guess, answer) == 0)
	{
		printf("Congratulations, that's right!!!!!!!!!!!!\n");
		return 1;
	}
	else
	{
		printf("Sorry that's not the right word. Please keep trying\n");
		return 0;
	}
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
			locs[inst] = i + 1;																		 // This 1-indexes the solutions to avoid the null pointer false positive from reveal-word function.
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
		printf("Good Guess. Let's see... ");
	}
	return 1;
}

int main(int argc, char *argv[])
{
	/* Your code here */

	int NUM_TRIES = 8;
	int *all_found = (int *)malloc(0);
	int size_all_found = 0;
	char *answer = argv[1];
	if (answer == NULL)
	{
		printf("Please provide a secret word as the first argument. (exiting). \n");
		return 0;
	}
	string_lower(answer);
	char guess;
	char bguess_word;
	char *word_guess = malloc(sizeof(char) * 10);
	char *previous = (char *)malloc(sizeof(char));
	int correct_answer_counter = 0;
	printf("Welcome to Hangman. ");
	printf("Can you guess the word of the day?\n");
	printf("You have chosen a word of %lu letters.\n", strlen(answer));
	for (int i = 0; i < NUM_TRIES; i++)
	{
		printf("\nRound %i!\n", i + 1);
		printf("previous letters guessed: %s\n\n", previous);

		printf("Do you want to try guess the word (y/n)?: ");
		scanf(" %c", &bguess_word);
		if (bguess_word == 'y')
		{
			printf("Enter your chosen word:");
			scanf("%s", word_guess);
			printf("\n");
			printf("You entered %s\n", word_guess);
			if (guess_word(word_guess, answer))
			{
				printf("Congratulations again. You are definitely going places\n");
				return 0;
			}
			else
			{
				printf("Word Guess and Answer %s %s %i %i \n", word_guess, answer, strlen(word_guess), strlen(answer));
				printf("Better luck next time\n");
				continue;
			}
		}
		while (1)
		{
			switch (i)
			{
			case 0:
				printf("Guess a letter then: ");
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
				previous[i + correct_answer_counter] = guess;
				previous = (char *)realloc(previous, sizeof(char) * (i + correct_answer_counter + 1));
				previous[i + correct_answer_counter] = guess;
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
			append_and_order(result, res_len, all_found, &size_all_found); // right now just prints. later it will append and order.
			i--;
			correct_answer_counter++;
		}
		else if (res_len > 1)
		{
			// printf(res_len);
			i--;
			printf("There are %d %c's!!\n", res_len, guess);
			append_and_order(result, res_len, all_found, &size_all_found);
			correct_answer_counter++;
		}
		// printf("PRINTING ALL FOUND SO FAR\n");
		// print_each_i(all_found, size_all_found);
		reveal_word(answer, all_found);
		// print_each_i(result, result_size);
		printf(" ");
	}

	return 0;
}