# push_swap

The **push_swap** project is a sorting algorithm challenge that requires sorting a stack of integers using a limited set of operations. The goal is to develop an efficient algorithm that outputs the fewest possible instructions to sort the stack in ascending order. The project is designed to deepen understanding of algorithm complexity, sorting techniques, and stack manipulation.

## Table of Contents
- [Project Description](#project-description)
- [Features](#features)
- [Implementation Details](#implementation-details)
- [Directory Structure](#directory-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Operations](#operations)
- [Authors](#authors)

## Project Description

In this project, you are tasked with sorting a list of integers stored in stack **A** using a predefined set of operations, with stack **B** used as auxiliary storage. The challenge is to find the most efficient sequence of operations that sorts the stack with the fewest possible moves.

The program must:
- Accept a list of integers as arguments.
- Output the smallest number of instructions needed to sort the list in ascending order.
- Handle both positive and negative integers.
- Detect and handle errors such as duplicates, non-integer input, or arguments that exceed integer limits.

This project tests your ability to design sorting algorithms and manage complexity effectively, a skill that is frequently tested in technical interviews.

## Features

- Sorting of integers using only stack operations.
- Handles positive and negative numbers.
- Custom error handling for non-integer input, duplicate numbers, or out-of-bound values.
- Efficiently outputs the smallest number of operations needed to sort the stack.

## Implementation Details

The **push_swap** algorithm is implemented using various strategies depending on the number of elements in the stack:
- **Small stacks (3-5 elements)**: A hardcoded optimal strategy to sort small numbers of elements in the fewest moves.
- **Medium stacks (up to 100 elements)**: A combination of the "divide and conquer" approach and efficient usage of both stacks A and B.
- **Large stacks (500+ elements)**: The algorithm is optimized for efficiency, using more advanced sorting techniques such as radix sort or quicksort-like partitioning.

The project follows the rule of using the smallest number of operations, ensuring that the algorithm's complexity is minimized as much as possible.

## Directory Structure

```plaintext
.
├── Makefile
├── README.md
├── header
│   └── push_swap.h
├── src
│   ├── main.c
│   ├── push_swap.c
│   └── error_handling.c
├── utils
│   ├── stack_utils.c
│   └── input_parsing.c
├── sort
│   ├── small_sort.c
│   ├── medium_sort.c
│   └── large_sort.c
└── moves
    ├── push.c
    ├── swap.c
    ├── rotate.c
    └── reverse_rotate.c
```
- Makefile: Handles compilation and cleaning tasks.
- header/: Contains the header file (push_swap.h) defining function prototypes and struct declarations.
- src/: Contains the main algorithm and error handling.
- utils/: Contains utility functions such as stack manipulation and input parsing.
- sort/: Contains sorting algorithms tailored for small, medium, and large datasets.
- moves/: Contains implementations of the various operations (push, swap, rotate, reverse rotate).

## Installation
```bash
git clone https://github.com/yourusername/push_swap.git
cd push_swap
make
```

This will produce the push_swap executable in the root directory.

## Usage

You can run the program by passing a list of integers as arguments:

```bash
./push_swap 3 2 5 1 4
```

This will output the list of operations needed to sort the stack. For example:
sa
pb
pb
ra
pa
pa

If you wish to clean or remove all of objects files use these commands respectively:

```bash
make clean
```

```bash
make fclean
```

## Operations

The program uses the following stack operations to sort the integers:

- sa: Swap the first two elements at the top of stack A.
- sb: Swap the first two elements at the top of stack B.
- ss: Swap the first two elements of both stacks A and B.
- pa: Push the top element of stack B to stack A.
- pb: Push the top element of stack A to stack B.
- ra: Rotate all elements of stack A upwards (first element becomes the last).
- rb: Rotate all elements of stack B upwards.
- rr: Rotate both stack A and stack B upwards.
- rra: Reverse rotate all elements of stack A (last element becomes the first).
- rrb: Reverse rotate all elements of stack B.
- rrr: Reverse rotate both stack A and stack B.

## Authors
