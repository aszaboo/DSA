# Sequential Lists

## What is a sequential list?

A sequential list in C++ is essentially an array with added functionality. C++ offers a list like structure called a vector, this is an array with added functionality such as variable size, insert and deletion function abstractions, begin and end function to get pointers to the start and end values in a list, and other pointer functions.

## Properties of a sequential list

As a sequential list is implemented using an array all the memory is stored together in a block on the heap. It is stored on the heap rather than the stack as the memory size needs to be able to increase and decrease dynamically meaning that the ADS for a variable sequential list needs to be implemented using dynamic memory as the final size of the list is not known at compile time. 

## List Structure


