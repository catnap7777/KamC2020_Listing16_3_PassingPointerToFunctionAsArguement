//Listing 16.3 Passing a pointer to a function as an argument; page 391

#include <stdio.h>

//function prototypes. the function func1() takes as
// its one argument a pointer to a function that takes no
// arguments and has not return value

void func1 (void (*p)(void));
void one(void);
void two(void);
void other(void);

int main(void)
{

    //the pointer to a function
    void (*ptr)(void);
    int nbr;

    for(;;)  //<-- endless loop
    {
        puts("\nEnter an integer between 1 and 10, 0 to exit: ");
        scanf("%d", &nbr);

        if(nbr == 0)
            break;
        else if(nbr ==1)
            ptr = one;      //set ptr equal to the address of function one
                            //Remember: a function name without the parenthesis is
                            // a pointer (the address) to that function
        else if(nbr == 2)
            ptr = two;      //set ptr equal to the address of function two...
        else
            ptr = other;    //set ptr equal to the address of function other...

        func1(ptr);
    }
    return 0;
}

void func1(void (*p)(void))
{
    p();    //call the function pointed to by ptr...
            //points to another function - one(),two(), other()
}

void one(void)
{
    puts("You entered 1.");
}

void two(void)
{
    puts("You entered 2.");
}

void other(void)
{
    puts("You entered something other than 1 or 2.");
}

