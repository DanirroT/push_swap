_This project has been created as part of the 42 curriculum by dmota-ri._

# Description

This project is designed to teach students how to build sorting algorithms with a specific set of restrictive rules.

The goal is to create an algorithm, using a limited set of operations, that **sorts** a given set of **unique numbers** in **ascending order** using the smallest number of moves possible. The rules are as follows:
- We have two stacks (lists of numbers) named `a` and `b`. At the beginning:
    - The stack `a` will have the input.
    - The stack `b` is empty.
- The possible operations for manipulating and sorting the stacks are:
    - Swap: Swap the first two elements at the top of a stack or do nothing if there is only one element or none.
        - sa (swap `a`) for stack `a`
        - sb (swap `b`) for stack `b`
        - ss for both stacks at once
    - Push: Take the first element at the top of one stack and put it at the top of the other. Do nothing if the first is empty.
        - pa (push `a`) from stack `b` to stack `a`
        - pb (push `b`) from stack `a` to stack `b`
    - Rotate: Shift up all elements of a stack by 1. The first element becomes the last one.
        - ra (rotate `a`) for stack `a`
        - rb (rotate `b`) for stack `b`
        - rr for both stacks at once
    - Reverse Rotate: Shift down all elements of a stack by 1. The last element becomes the first one.
        - rra (reverse rotate `a`) for stack `a`
        - rrb (reverse rotate `b`) for stack `b`
        - rrr for both stacks at once

# Instructions

For compilation, a Makefile is provided. Running the command `make` on a shell console will compile the program.
The output of this compilation will be a push_swap executable.
To use it as intended, run it with a set of integer arguments. It will work with multiple integer arguments, as well as a single argument composed of numbers separated by spaces.
- example:
    - `./push_swap 1 2 3 4 0 5`
    - `./push_swap "1 2 3 4 0 5"`
- If an error occurs, the message `Error` will appear on the standard error output. This may be caused by incorrect inputs (such as non-integers or duplicates) or by certain memory-related issues.
- If no arguments are given or if the arguments given are already in order, nothing will be displayed, as no sorting is required.
- If the arguments given need sorting, the list of moves according to the rules will be displayed. This list of operations will sort the input in ascending order.

# Resources

I’ve started this project before this file was necessary, so unfortunately, I don’t believe I have all the sources or references I’ve used here and there.

I started somewhat foolishly by searching information on sorting algorithms without really understanding that the rules of this project would not allow most of what I learned to be useful.

After some realignment and making some of my own lower complexity algorithms (Simple Solve, Push to Side, Rotate to Side), I searched on 42 forums for new algorithms to add to mine. I elected to use Radix and Chunking, along with my own.

For further explanation of particular aspects of the algorithms I was not understanding, I sometimes checked in with AI with mixed results. When encountering certain errors, I also used it as a tool to sift through the lengthy error messages I am not yet familiar with (my own in-built debugging outputs while in development and Valgrind memory testing output, for example).

## Sources:
- https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
- https://www.geeksforgeeks.org/c/bitwise-operators-in-c-cpp/a
- https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0