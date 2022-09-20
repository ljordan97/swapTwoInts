/** @file ringBuffer.h
 * 
 * @brief A ring buffer to store integers, and some useful functions
 *
 * @par       
 * COPYRIGHT NOTICE: (header template) (c) 2018 Barr Group.  All rights reserved.
 */ 

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

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
ringBufferHandle initRingBuffer(int* buffer, int capacity);

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
 * @brief add all elements of the ring buffer together
 * 
 * @param[in] buffer ring buffer to sum
 * 
 * @return sum of all elements. long long to prevent overflow when summing
 */
long long sum(ringBufferHandle buffer);

/* -------------------------------------------------------------------------- */

/**
 * @brief get the average value of the buffer
 * 
 * @param[in] buffer ring buffer to avg
 * 
 * @return average buffer value, double to minimize rounding error
 */
double avg(ringBufferHandle buffer);

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
bool isEmpty(ringBufferHandle bufferHandle);

/* -------------------------------------------------------------------------- */

/**
 * @brief Determine if the ring buffer is full or not
 * 
 * @param[in] handle to ring buffer
 * 
 * @return 1 if full, 0 if not full
 */
bool isFull(ringBufferHandle bufferHandle);

/* -------------------------------------------------------------------------- */

/**
 * @brief get the current size of the buffer
 * 
 * @param[in] handle to ring buffer
 * 
 * @return size of the buffer in bytes
 */
size_t size(ringBufferHandle bufferHandle);

/* -------------------------------------------------------------------------- */

#endif /* RINGBUFFER_H */

/*** end of file ***/
