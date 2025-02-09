# Monty Bytecode Interpreter

## Description

A custom interpreter for Monty ByteCode files, implemented in C. This project focuses on implementing a stack-based interpreter that processes Monty bytecode files and executes various stack and queue operations.

## Project Overview

- **Language**: C
- **Team**: Talal Omer, Tariq Omer
- **Project Duration**: Mar 26, 2024 - Mar 29, 2024

## Features

- Stack and queue operations (LIFO/FIFO)
- Basic operations:
  - `push`: Add element to stack
  - `pall`: Print all elements
  - `pint`: Print top element
  - `pop`: Remove top element
- Advanced operations:
  - `swap`: Swap top elements
  - `add/sub/mul/div/mod`: Arithmetic operations
  - `nop`: No operation
  - `rotl/rotr`: Rotate stack
  - `stack/queue`: Switch between modes
  - `pchar/pstr`: Character operations

## Requirements

- Ubuntu 20.04 LTS
- gcc compiler with options: -Wall -Werror -Wextra -pedantic -std=c89
- Betty style compliant code
- Maximum one global variable
- No more than 5 functions per file
- All files should end with a new line
- Header file: monty.h (include guarded)

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

## Usage

```bash
./monty file.m
```

### Example

```bash
$ cat bytecodes/00.m
push 1
push 2
push 3
pall
$ ./monty bytecodes/00.m
3
2
1
```

## Data Structures

```c
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

## Implemented Operations

### Mandatory Tasks

1. **push, pall**: Push element to stack and print all values
2. **pint**: Print value at top of stack
3. **pop**: Remove top element
4. **swap**: Swap top two elements
5. **add**: Add top two elements
6. **nop**: No operation

### Advanced Tasks

7. **sub**: Subtract top elements
8. **div**: Divide elements
9. **mul**: Multiply elements
10. **mod**: Modulus operation
11. **comments**: Handle # comments
12. **pchar**: Print char value
13. **pstr**: Print string
14. **rotl**: Rotate stack to top
15. **rotr**: Rotate stack to bottom
16. **stack, queue**: Switch between modes

## Error Handling

- Invalid instructions
- Stack underflow
- Memory allocation failures
- File opening issues
- Invalid push arguments

## Repository Structure

```plantxt
monty/
├── monty.h
├── main.c
├── opcode_handlers/
│   ├── basic_ops.c
│   ├── stack_ops.c
│   └── math_ops.c
├── utils/
│   ├── memory.c
│   └── parser.c
└── bytecodes/
    └── test_files.m
```

## Authors

- Talal Omer
- Tariq Omer

## License

Copyright © 2024 ALX. All rights reserved.
