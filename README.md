## Assignment 3: Putting your affairs in order:

    This program tests 3 different sorting algorithms by running
    a randomly generated array through them. The algorithms are
    bubble sort, shell sort, and two different variations of quick
    sort. The first quicksort uses a stack struct and the second 
    uses a queue struct. User enters input through command-line 
    arguments that are defined below. Outputs a table that contains
    the number of elements sorted, number of comparisons made, number
    of times a number was moved, and the sorted elements.

## How to Build:

    Typing 'make' builds the program, 'make clean' removes any files
    created when it is compiled, and 'make clang-format' formats the
    files if there is a given .clang-format file.

## How to Run:

    To run the program type './sorting' followed by desired
    command-line options. Each sorting algorithms table will only be 
    printed once, even if it is requested mulitple times in the input.

    For example:  ./sorting -sb -r 50 -n 107 -p 20

    The accepted command-line options are:

    -a   Prints all of the tables
    -b   Prints the table for bubble sort
    -s   Prints the table for shell sort
    -q   Prints the table for quicksort(stack)
    -Q   Prints the table for quicksort(queue)
    -r   Sets the given random seed for array generation
    -n   Sets the number of elements in each array
    -p   Sets number of elements to be printed in each table   

--------------------------------------------------------------------

