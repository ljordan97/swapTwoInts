/** @file ringBuffer.c
 * 
 * @brief implementation of the API declared in ringBuffer.h
 *
 * @par       
 * COPYRIGHT NOTICE: (source file template) (c) 2018 Barr Group. All rights reserved.
 */

#include <assert.h>
#include "ringBuffer.h"

struct ringBuffer {
    int * data;
    size_t head;
    size_t tail;
    unsigned int capacity;
    bool full;
};

ringBufferHandle initRingBuffer(int* data, const unsigned int capacity)
{
    //verify memory and size
    assert(data && capacity);

    ringBufferHandle ringBuff = malloc(sizeof(ringBuffer));
    
    //verify memory allocation
    assert(ringBuff);

    ringBuff->data = data;

    ringBuff->capacity = capacity;

    clearRingBuffer(ringBuff);

    return ringBuff;
}

void clearRingBuffer(ringBufferHandle buffer)
{
    assert(buffer);

    buffer->full = false;
    buffer->head = 0;
    buffer->tail = 0;

    //verify the empty actually worked
    assert(isEmpty(buffer));
}

bool isEmpty(ringBufferHandle buffer)
{
    assert(buffer);

    return (buffer-> head == buffer-> tail) && (!buffer->full);
}

size_t size(ringBufferHandle buffer)
{
    assert(buffer);

    if (buffer->full)
    {
        return buffer->capacity;
    }
    else
    {
        return (buffer->head) - (buffer->tail);
    }
}

void push(ringBufferHandle buffer, const int newValue)
{
    assert(buffer && (buffer->data));

    buffer->data[buffer->head] = newValue;

    //if the buffer was already full, tail needs to move
    if (buffer->full)
    {
        if (++(buffer->tail) == buffer->capacity)
        {
            buffer->tail = 0;
        }
    }

    //update head and check if the add filled the buffer
    if(++(buffer->head) == buffer->capacity)
    {
        //reset the head
        buffer->head = 0;
    }

    //update full status
    buffer->full = (buffer->head) == (buffer->tail);
}

float bufferAvg(ringBufferHandle buffer)
{
    assert(buffer && buffer->data);
    
    //long long to prevent overflow
    long long int runningSum = 0;

    unsigned int bufSize = size(buffer);

    for (unsigned int i = 0; i < bufSize; i++)
    {
        //doesn't matter if buffer has wrapped, math is the same
        runningSum += (buffer->data[i]);
    }

    return (runningSum / (float)bufSize);
}

void printBuffer(ringBufferHandle buffer)
{
    printf("dumping buffer of size %ld and capacity %d\n", size(buffer), buffer->capacity);
    for(unsigned int i = 0; i < size(buffer); i++)
    {
        printf("%d\n", buffer->data[i]);
    }
}

/*** end of file ***/
