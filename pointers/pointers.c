#include <stdio.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    int i = 0;
    while (*(y + i) != 0)
    {
        // with array indexing
        // x[i] = y[i];
        // with pointer arithmetic
        *(x + i) = *(y + i);
        i++;
    }
    *(x + i) = '\0'; // this terminates the char pointer
    // works as planned
    // printf("This is X: %s \n", x);
    // printf("This is Y: %s \n ", y);
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, char c)
{
    printf("This is X: %s \n", str);
    // printf("This is Y: %s \n ", c);

    int i = 0;
    while (str[i] != 0)
    {
        if (str[i] == c)
        {
            return &str[i];
        }
        i++;
    }
    return '\0';
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    char *pHaystack = haystack;
    printf("Haystack pointer %s\n", pHaystack);

    int i, j, lhay = 0, lneedle = 0;

    while (haystack[lhay] != 0)
    {
        lhay++;
    }
    // printf("length hay %i", lhay);
    while (needle[lneedle] != 0)
    {
        lneedle++;
    }
    // printf("length needle %i", lneedle);

    for (i = 0; i < lhay; i++)
    {
        for (j = 0; j < lneedle; j++)
        {
            printf("i %i j %i Needle %c and Haystack %c\n", i, j, needle[j], haystack[i + j]);
            if (needle[j] == haystack[i + j])
            {
                printf("continuing\n");
                if (j == lneedle-1)
                {
                    pHaystack = haystack + i;
                    return pHaystack;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                printf("breaking\n");
                break;
            }
        }
    }
    char *n = NULL;
    return n;
}

#ifndef TESTING
int main(void)
{

    // char *string = "hello, world";
    // char empty[20];

    // string_copy(empty, string);

    // char *found_char = find_char("hello", 'l');
    // printf("Found Char: %c address %p\n", found_char[0], found_char);
    char *found_string = find_string("world", "or");
    printf("Found String: %s \n", found_string);

    // printf("Found char: %s\n", found_char);
    // printf("Found string: %s\n", found_string);

    return 0;
}
#endif
