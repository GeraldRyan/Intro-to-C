#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
// #include "../pointers/pointers.h"


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
    Define the Person struct by specifying the fields that make up the
    Person type. Don't forget to specify the type of each field. A 
    Person should have the fields `name`, `age`, `height`, and `weight`.
*/
typedef struct Person {
    char* name;
    int age;
    int height;
    int weight;
} Person;

/*
    Creates an instance of the Person struct that receives all the relevant
    pieces of data associated with a Person instance.
    Allocates the appropriate amount of memory to hold an instance of the 
    Person struct, and then sets the struct's fields with the input data.
    When setting the `name` field, use your previously-built string_dup
    function, which handles the allocation of memory for the new string.
*/
Person *createPerson(char *name, int age, int height, int weight)
{
    Person *newPerson = malloc(sizeof(Person));
    newPerson->name = malloc(sizeof(name));
    string_copy(newPerson->name, name);


    newPerson->height = height;
    newPerson->weight = weight;
    newPerson->age = age;
    return newPerson;
}

/*
    Given a pointer to a Person struct, frees up the memory that holds the
    Person's name as well as the memory that holds the Person instance.
*/
void destroyPerson(Person *who)
{
    free(who->name);
    free(who);
 
}

#ifndef TESTING
int main(void)
{
    Person *tony = createPerson("Tony Stark", 32, 64, 140);

    printf("  Name: %s\n", tony->name);
    printf("   Age: %d\n", tony->age);
    printf("Height: %d\n", tony->height);
    printf("Weight: %d\n", tony->weight);

    // destroyPerson(tony);

    return 0;
}
#endif