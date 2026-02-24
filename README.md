*This project has been created as part of the 42 curriculum by ewaltz, alemyre.*

# Description

This project is an introduction to algorithmic computing.  
Essentially, we receive a list and need to get it sorting only using a defined numbers of operation and 2 stack at most.  
There can be any number of arguments.  
The goal being to get the list sorted as effiently as possible.  

The program manipulates two stacks (`a` and `b`) using the following operations:

### 🔹 Swap
- **`sa` (swap a)** — Swap the first two elements at the top of stack **a**. Does nothing if there is only one or no elements.
- **`sb` (swap b)** — Swap the first two elements at the top of stack **b**. Does nothing if there is only one or no elements.
- **`ss`** — Perform `sa` and `sb` simultaneously.

### 🔹 Push
- **`pa` (push a)** — Take the first element at the top of stack **b** and push it onto stack **a**. Does nothing if **b** is empty.
- **`pb` (push b)** — Take the first element at the top of stack **a** and push it onto stack **b**. Does nothing if **a** is empty.

### 🔹 Rotate
- **`ra` (rotate a)** — Shift all elements of stack **a** upward by one. The first element becomes the last.
- **`rb` (rotate b)** — Shift all elements of stack **b** upward by one. The first element becomes the last.
- **`rr`** — Perform `ra` and `rb` simultaneously.

### 🔹 Reverse rotate
- **`rra` (reverse rotate a)** — Shift all elements of stack **a** downward by one. The last element becomes the first.
- **`rrb` (reverse rotate b)** — Shift all elements of stack **b** downward by one. The last element becomes the first.
- **`rrr`** — Perform `rra` and `rrb` simultaneously.


# Instructions

### Requirements

• A C compiler (clang or gcc)  

### Compile

To use the program, you first need to clone the repository on your device.  
You then can use the Makefile commands to compile the program using `make`.

### Run

Once compiled, you will need to call the program.  
The arguments are the list you want to sort.  
It can be one big string or individual arguments.  
For a cleaner experience, we recommand placing the flags you want to use preceding the list numbers.  

Here is an example :

`./push_swap --simple --bench 7 2 5`

The flag `--bench` will print you on the standard error output all the relevant information:  

- `chosen algorithm`  
- `input size`  
- `disorder percentage`  
- `number of operations done`  
- `details on each operation` 

The flags `--simple`, `--medium` and `--complex` are explained below under Justification of the algorithms.


# Resources

- `https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/`

# Algorithm Explanation and Justification

The function is using 3 differents algorithms:  
1. `Selective`  
2. `Chunk`
3. `Radix`  

### 1. Selective sorting

The idea of this method is to get to the smallest number and push it to the `b` stack.  
To get to the smallest number, we either `ra` or `rra` depending on which is faster.  
Once all the numbers are in the `b` stack, we simply `pa` until they are all pushed.  

This method is `O(n2)` efficient, meaning operations grow with the square of the input size.  
So it's good for small input sizes.  

###	2. Chunk based sorting

This algorithm will divide the size into chunks of it's square root.  
It will then `pb` the said chunks one after the other.  
Once all the numbers are in `b`, it will `pa` after a series of `rb` so they are in the good order.  
The furthest they can be will be the chunk size.  

This method is `O(n√n)` efficient, meaning there will be `√n` number of operations for every number.  

### 3. Radix sorting

This algorithm will order the list through binary numbers.  
It will look at all the numbers as a binary and sort them digit by digit, starting with the smallest to the biggest.  
The idea being we will `pb` all of the numbers that returns `0` for the digit we are looking for.  
Once we went through the whole list, we `pa`.  
We do this for all the bits.  

This method is `O(n log n)` efficient, meaning we will do `log n` operations on all the numbers.  
The bigger the number, the smaller the additional operations.  
Hence why this method is very efficient for big sizes.  

# Disorder and Adaptive

### Disorder

Before any operations are done, the program will calculate the disorder based on the ratio of adjacent inversions over total pairs.  
That means that we are only looking at whether a number is well placed compared to the next one, for all the numbers.  
We then turn that number into a percentage and use it to choose what algorithm will be selected if the flag `--adaptive` is put (or no algorithm flags at all).  

### Adaptive  

As said above, `adaptive` will select a sorting based purely on the `disorder` percentage.  
The threshold goes as follows: 

- `< 0.2` → selection

- `0.2–0.5` → chunk based

- `≥ 0.5` → radix

# Work Contributions

### EWALTZ

- Started the parsing with string method
- Made the flags work
- Did the bench flag
- Coded the `chunk_based` and `radix` algorithms
- Took care of all of the `printf` stuff and their output
- Added documentation structure

### ALEMYRE

- Changed the parsing to use linked chained list
- Coded `selection` alrightm
- Implemented the disorder calculation
- Modified the `Makefile`
- Wrote the `README.md`
- Verified the possible leaks