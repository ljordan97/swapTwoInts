swapTwoInts is a CLI application in C that reads in two integers, swaps them and prints both the newly swapped values to “prove” to the user that the values were swapped and the running average of all previously swapped values with the following requirements.

    This application must run indefinitely until killed by the user
    The code must use two ring buffers to maintain the running averages using a ring buffer
	library of your own creation (i.e one ring buffer for x, one ring buffer for y)
    The swap function cannot internally use temporary variables to swap the integer arguments
    The code must compile without warnings (i.e. nothing returned when using -Wall and -Wextra)
    The code must be modular enough to be unit tested
    The code must be well commented and conform to some form of coding “standard” 

 This code adheres to the Barr Group's Embedded C standard which can be found here
https://barrgroup.com/sites/default/files/barr_c_coding_standard_2018.pdf

Author: Levi Jordan, September 19th, 2022

Compiler: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
