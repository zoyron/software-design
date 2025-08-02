# C vs Python Linked List

This directory has two simple programs that do the same thing: read numbers from `random_numbers.txt` and build a linked list from them. One is written in C, the other in Python.

The point is to compare their performance. It's a straightforward way to see the speed difference between C (with manual memory management) and Python (with its garbage collector) on a memory-heavy task.

## The Code

*   `linkedlistFromFile.c`: The C version, using `struct` and `malloc`/`free`.
*   `linkedlist_from_file.py`: The Python version, using a `Node` class.

## Running the Comparison

You can test the speed yourself using the `time` command.

### C

```bash
# Compile it
gcc -o linkedlistFromFile linkedlistFromFile.c

# Run it
time ./linkedlistFromFile
```

### Python

```bash
# Run it
time python3 linkedlist_from_file.py
```
