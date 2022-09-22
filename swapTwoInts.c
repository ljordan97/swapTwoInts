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
#include <string.h>

#include "ringBuffer.c"

/**
 * @brief given two ints, swap them in place
 * 
 * @param[in out] array of 2 ints to swap
 */
void swapTwoInts(int* numsToSwap)
{
    printf("Going to swap %d with %d\n", numsToSwap[0], numsToSwap[1]);

    numsToSwap[0] += numsToSwap[1];
    numsToSwap[1] = numsToSwap[0] - numsToSwap[1];
    numsToSwap[0] -= numsToSwap[1];

    printf("swapped values: %d, %d\n", numsToSwap[0], numsToSwap[1]);
}

/**
 * @brief prompt user for two integers, store
 * 
 * @param[out] array to store two ints
 */
void promptUserForTwoInts(int* twoInts)
{

    //read ints and sanitize
    char s[12];
    int n;

    puts("Input two integers, one at a time:");
    for(int inputCount = 0; inputCount < 2; inputCount++)
    {
        //prompt user for one num
        printf("Num%d: ", inputCount + 1);

        fgets(s, sizeof(s), stdin);

        n = atoi(s);

        if (strlen(s) == 0 || s[0] == '\n') 
        {
            printf("Please enter an integer: ");
            --inputCount;
        }

        //store input if acceptable
        twoInts[inputCount] = n;
        
        //consume the rest of the input buffer if too much was given
        char* eolPosition = strchr(s, '\n');
        if(!eolPosition)
        {
            int c;
            for(c = fgetc(stdin); (c != EOF) && (c != '\n'); c = fgetc(stdin))
            {
                //discard
                ;
            }

        }

        //reset buffer
        s[0] = '\0';
        n = 0;
    }

}

int main()
{
    //init two ring buffers to store swapped values 
    const int ringBufferSize = 20;

    int* buffer1 =   malloc(ringBufferSize * sizeof(int));
    int* buffer2 =   malloc(ringBufferSize * sizeof(int));

    ringBufferHandle ringBuffer1 = initRingBuffer(buffer1, ringBufferSize);
    ringBufferHandle ringBuffer2 = initRingBuffer(buffer2, ringBufferSize);

    while(1)
    {
        //get user input
        int userInput[2]; 
        promptUserForTwoInts(userInput);
        
        //when input has been read, perform swap
        swapTwoInts(userInput);

        //update values
        push(ringBuffer1, userInput[0]);
        push(ringBuffer2, userInput[1]);

        //view buffer
        printBuffer(ringBuffer1);

        //calculate and display new averages
        printf("Ring buffer 1 Average: %f\n", bufferAvg(ringBuffer1));
        printf("Ring buffer 2 Average: %f\n\n\n", bufferAvg(ringBuffer2));
    }
}