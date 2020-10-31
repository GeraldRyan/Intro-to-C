#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Given a character array s (as a pointer), return the number of 
    characters in the string.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s)
{
    int l = 0;
    while (s[l] != 0)
    {
        l++;
    }

    // printf("LENGTH %i \n", l);
    return l;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/

// char *reverse_string(char *rv, char *s)
// {

// 	int rslength = string_length(s);
// 	int index = 0;

// 	for (int i = rslength - 1; i >=0; i--) {
// 	  rv[index] = s[i];
// 	  index = index + 1;
// 	}
// 	rv[index] = '\0';
// 	return rv;

// }

char *reverse_string(char *rv, char *s) 
{
    int length = string_length(s);
    int temp;
    (rv) = s;
    int g;

    for (g = 0; g < (length / 2); g++)
    {
        temp = (rv)[length - g - 1];
        (rv)[length - g - 1] = (rv)[g];
        (rv)[g] = temp;
        // s[length] = "\0";
    }
    // rv[length] = '\0';
    return rv;
}

// char *reverse_string(char **rv, char *s) 
// {
//     int length = string_length(s);
//     int temp;
//     (*rv) = s;

//     // for (int g = 0; g < length / 2; g++)
//     // {
//     //     temp = *(s+ (length - g - 1));
//     //     *(s+(length - g - 1)) = *(s+g);
//     //     *(s+g) = temp;
//     //     // s[length] = "\0";
//     // }
//     for (int g = 0; g < length / 2; g++)
//     {
//         temp = (*rv)[length - g - 1];
//         (*rv)[length - g - 1] = (*rv)[g];
//         (*rv)[g] = temp;
//         // s[length] = "\0";
//     }
    // rv = s;

    // printf("LENGTH %i, STRLEN() %lu RV %s \n", string_length(rv), strlen(rv), rv);
    // char *str = "supercalifragilisticexpialidocious";
    // printf("SDL:KJSDFKJSDF %s\n", str);
    // printf("%c\n", *str);
    // printf("%c\n", *(str +string_length(str)-1));
//     return rv;
// }

#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
