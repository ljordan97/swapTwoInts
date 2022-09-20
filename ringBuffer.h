/** @file ringBuffer.h
 * 
 * @brief A ring buffer to store integers, and some useful functions
 *          implementated with design by contract, will fail hard if 
 *          misused.
 * 
 *          use-case specific assumption: values are never removed
 *              once full, the buffer remains full for its lifespan
 *
 * @par       
 * COPYRIGHT NOTICE: (header template) (c) 2018 Barr Group.  All rights reserved.
 */ 

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <stdbool.h> 


typedef struct ringBuffer ringBuffer;

//user should interact with the ring buffer via its handle
typedef ringBuffer* ringBufferHandle;

/* -------------------------------------------------------------------------- */

/**
 * @brief Initialize a ring buffer to a given size
 * 
 * @param[in] buffer to store ints
 * @param[in] capacity how many ints to store
 * 
 * @return handle to the newly created ringBuffer
 */
ringBufferHandle initRingBuffer(int* data, int capacity);

/* -------------------------------------------------------------------------- */

/**
 * @brief add a value to the ring buffer
 * 
 * @param[out] buffer ring buffer to add data to
 * @param[in] newValue value to add to buffer
 */
void push(ringBufferHandle buffer, int newValue);

/* -------------------------------------------------------------------------- */

/**
 * @brief get the average value of the buffer
 * 
 * @param[in] buffer ring buffer to avg
 * 
 * @return average buffer value, float to minimize rounding error
 */
float avg(ringBufferHandle buffer);

/* -------------------------------------------------------------------------- */

/**
 * @brief Remove all int data from the ring buffer
 * 
 * @param[out] buffer ringBuffer to clear
 */
void clearRingBuffer(ringBufferHandle buffer);

/* -------------------------------------------------------------------------- */

/**
 * @brief Determine if the ring buffer is empty or not
 * 
 * @param[in] handle to ring buffer
 * 
 * @return 1 if empty, 0 if not empty
 */
bool isEmpty(ringBufferHandle buffer);

/* -------------------------------------------------------------------------- */

/**
 * @brief get the current size of the buffer
 * 
 * @param[in] handle to ring buffer
 * 
 * @return size of the buffer in bytes
 */
size_t size(ringBufferHandle buffer);

/* -------------------------------------------------------------------------- */

#endif /* RINGBUFFER_H */

/*** end of file ***/
