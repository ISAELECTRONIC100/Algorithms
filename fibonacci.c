/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/* 
*  Author: Isael García Luis
*  Date: 01/05/2020
*/

#include <stdio.h>

#define FIBONACCI_MAX   17


int * fibonacci();
void printFiboSequence(int * fiboSequence);

int main()
{
    int *fiboSequence;
    printf("This program displays the first %d numbers of the standard fibonacci sequence\n", FIBONACCI_MAX);
    
    fiboSequence = fibonacci();
    printFiboSequence(fiboSequence);

    return 0;
}


/* 
* Fibonacci Sequence
* Starts with 1 and 1. Each subsequent number is the sum of the two previous numbers.
*/
int * fibonacci()
{
    static int fibonacci[FIBONACCI_MAX];
    int fiboNumber;
    
    for(fiboNumber = 0; fiboNumber < FIBONACCI_MAX; fiboNumber++)
    {
        if(fiboNumber < 2)
            fibonacci[fiboNumber] = fiboNumber;
        else
            // Each subsequent number is the sum of the two previous numbers.
            fibonacci[fiboNumber] = fibonacci[fiboNumber - 1] + fibonacci[fiboNumber - 2];
    }
    
    return fibonacci;
}


/*
* Print fibonacci sequence up to FIBONACCI_MAX
* i.e. 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987...
*/
void printFiboSequence(int * fiboSequence)
{   
    int fiboNumber;
    for(fiboNumber = 0; fiboNumber < FIBONACCI_MAX; fiboNumber++)
    {
        printf("%d, ", fiboSequence[fiboNumber]);
    }
}
