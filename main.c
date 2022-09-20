/** @file main.c
 *
 * @brief a CLI application that swaps two ints, storing previous values in a
 *        ring buffer, and printing the running averages
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2000, 2018 Michael Barr. This software is placed in the
 * public domain and may be used for any purpose. However, this notice must not
 * be changed or removed. No warranty is expressed or implied by the publication
 * or distribution of this source code.
 */

#include <stdlib.h> 
#include <stdio.h>
#include <ctype.h>   // isdigit()

#include "ringBuffer.c"

//TODO: implement swap function

int main()
{
    int userInput[2];
    
    puts("Input two integers, one at a time:");

    for(int inputCount = 0; inputCount < 2; inputCount++)
    {
        printf("Num%d: ", inputCount + 1);
        //read ints and sanitize
        for (int ch = fgetc(stdin); ch != EOF && ch != '\n'; ch = fgetc(stdin)) 
        {
            if (isdigit(ch))
            {
                printf("Read in '%c'\n\n", ch);
                userInput[inputCount] = ch;
            }
            else
            {
                fprintf(stderr, "'%c' is not a valid digit :(\n\n", ch);
                --inputCount;
            }
        }
    }

    //when input has been read, perform swap
    
}