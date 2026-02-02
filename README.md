*This project has been created as part of the 42 curriculum by emi.*

# Push_swap

A highly efficient stack sorting algorithm implementation using two stacks and a limited set of operations.

## Description

Push_swap is a sorting algorithm project that challenges you to sort a stack of integers using only two stacks (`a` and `b`) and a predefined set of operations. The goal is to sort the stack `a` in ascending order using the minimum number of operations.

The project implements **four distinct sorting strategies** with different time complexities:

1. **Simple Algorithm** - O(n^2) - Selection sort adaptation
2. **Medium Algorithm** - O(n * sqrt(n)) - Chunk-based sorting
3. **Complex Algorithm** - O(n log n) - Radix sort (LSD)
4. **Adaptive Algorithm** - Automatically selects the best strategy based on disorder

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack `a` |
| `sb` | Swap the first two elements of stack `b` |
| `ss` | Execute `sa` and `sb` simultaneously |
| `pa` | Push the top element from `b` to `a` |
| `pb` | Push the top element from `a` to `b` |
| `ra` | Rotate stack `a` upward (first element becomes last) |
| `rb` | Rotate stack `b` upward |
| `rr` | Execute `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack `a` (last element becomes first) |
| `rrb` | Reverse rotate stack `b` |
| `rrr` | Execute `rra` and `rrb` simultaneously |

## Instructions

### Compilation

```bash
# Compile push_swap
make

# Compile checker (bonus)
make bonus

# Clean object files
make clean

# Full clean (including binaries)
make fclean

# Recompile
make re
```

### Usage

```bash
# Basic usage (uses adaptive algorithm by default)
./push_swap 4 67 3 87 23

# Force specific strategy
./push_swap --simple 5 4 3 2 1      # O(n^2)
./push_swap --medium 5 4 3 2 1      # O(n * sqrt(n))
./push_swap --complex 5 4 3 2 1     # O(n log n)
./push_swap --adaptive 5 4 3 2 1    # Adaptive (default)

# Enable benchmark mode
./push_swap --bench 5 4 3 2 1

# Verify sorting with checker
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23

# Count operations
./push_swap $(shuf -i 1-100 -n 100 | tr '\n' ' ') | wc -l
```

## Algorithm Explanations

### 1. Simple Algorithm - O(n^2)

**Strategy**: Selection sort adaptation

This algorithm pushes all elements from stack `a` to stack `b`, then repeatedly finds the maximum element in `b` and pushes it back to `a`. This ensures elements are returned in sorted order.

**Complexity Analysis**:
- Finding the maximum in `b`: O(n)
- Rotating to bring max to top: O(n)
- Total: O(n) * n elements = **O(n^2)**

**When to use**: Small datasets or when simplicity is preferred over efficiency.

### 2. Medium Algorithm - O(n * sqrt(n))

**Strategy**: Chunk-based sorting

The algorithm divides elements into sqrt(n) chunks based on their normalized values:
1. Normalize all values to range [0, n-1]
2. Push elements to `b` in chunks, keeping larger values on top
3. Push back to `a` by repeatedly moving the maximum to the top

**Complexity Analysis**:
- Dividing into sqrt(n) chunks: each chunk has sqrt(n) elements
- Processing each chunk: O(n) rotations to find elements
- Total: sqrt(n) chunks * O(n) operations = **O(n * sqrt(n))**

**When to use**: Medium-sized datasets (50-200 elements).

### 3. Complex Algorithm - O(n log n)

**Strategy**: Radix sort (Least Significant Digit)

Uses binary representation of normalized values:
1. Normalize values to [0, n-1]
2. For each bit position (from LSB to MSB):
   - Push elements with bit=0 to `b`
   - Rotate elements with bit=1 in `a`
   - Push all elements back to `a`
3. After processing log(n) bits, stack is sorted

**Complexity Analysis**:
- Number of bits to process: log(n)
- Operations per bit: O(n)
- Total: **O(n log n)**

**When to use**: Large datasets (500+ elements) with high disorder.

### 4. Adaptive Algorithm

**Strategy**: Disorder-based selection

The adaptive algorithm measures the "disorder" of the input (percentage of inverted pairs) and selects the appropriate strategy:

| Disorder | Strategy | Complexity |
|----------|----------|------------|
| < 20% | Rotation-based | O(n) |
| 20% - 50% | Chunk-based (Medium) | O(n * sqrt(n)) |
| >= 50% | Radix sort (Complex) | O(n log n) |

**Disorder Calculation**:
```
disorder = (number of inverted pairs) / (total possible pairs)
```

Where an inverted pair is when `a[i] > a[j]` for `i < j`.

**Rationale for Thresholds**:
- **< 20%**: Stack is nearly sorted; simple rotations can fix it efficiently
- **20-50%**: Moderate disorder benefits from chunking without the overhead of radix
- **>= 50%**: High disorder requires a systematic approach like radix sort

## Performance Benchmarks

Expected performance for random inputs:

| Size | Target (pass) | Good | Excellent |
|------|--------------|------|-----------|
| 100 | < 2000 | < 1500 | < 700 |
| 500 | < 12000 | < 8000 | < 5500 |

## Project Structure

```
push_swap/
├── Makefile
├── README.md
├── includes/
│   └── push_swap.h
├── libft/
│   ├── Makefile
│   ├── libft.h
│   └── *.c
├── src/
│   ├── main.c
│   ├── stack.c, stack_utils.c
│   ├── ops_*.c (operations)
│   ├── parsing.c, parsing_args.c
│   ├── utils.c, utils2.c
│   ├── disorder.c
│   ├── sort_small.c
│   ├── sort_simple.c
│   ├── sort_medium.c
│   ├── sort_complex.c
│   ├── sort_adaptive.c
│   ├── data.c
│   └── benchmark.c
└── src_bonus/
    └── checker_bonus.c
```

## Resources

### Classic References

- [Sorting Algorithms - Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Radix Sort - GeeksforGeeks](https://www.geeksforgeeks.org/radix-sort/)
- [The Art of Computer Programming - Donald Knuth](https://en.wikipedia.org/wiki/The_Art_of_Computer_Programming)
- [Big-O Notation - Khan Academy](https://www.khanacademy.org/computing/computer-science/algorithms/asymptotic-notation/a/big-o-notation)

### AI Usage

AI assistance (Claude) was used for:
- Initial code structure and boilerplate generation
- Algorithm optimization suggestions
- Documentation and README creation
- Code review and bug identification

All generated code was reviewed, tested, and understood before inclusion in the project.

## Author

- **emi** - 42 Student

## License

This project is part of the 42 curriculum.
