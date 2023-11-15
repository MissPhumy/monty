# Monty - The Monty Language Interpreter

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

---

## Compilation
All files should be compiled with `gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

## Usage
You can execute the `monty` program by writing `./monty <file>`. <br />
The `<file>` argument is mandatory. This file containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.


## Monty Byte Code Commands
- `push <int>` - pushes an element to the stack
- `pall` - prints all the values on the stack, starting from the top of the stack
- `pint` - prints the value at the top of the stack, followed by a new line
- `pchar` - prints the char at the top of the stack, followed by a new line
- `pstr` - prints the string starting at the top of the stack, followed by a new line
- `pop` - removes the top element of the stack
- `swap` - swaps the top two elements of the stack
- `rotl` - rotates the stack to the top
- `rotr` - rotates the stack to the bottom
- `add` - adds the top two elements of the stack
- `sub` - subtracts the top element of the stack from the second top element of the stack
- `div` - divides the second top element of the stack by the top element of the stack
- `mul` - multiplies the second top element of the stack with the top element of the stack
- `mod` - computes the rest of the division of the second top element of the stack by the top element of the stack
- `stack` - sets the format of the data to a stack (LIFO). This is the default behavior of the program
- `queue` - sets the format of the data to a queue (FIFO)
- `nop` - doesn’t do anything

## Comments
Every good language comes with the capability of commenting. When the first non-space character of a line is #, the line is interpreted as a comment. Also, everything that is written after the opcode (except for push) is ignored, you can comment your lines just after your instructions.

## Runtime
The monty program runs the bytecodes line by line and stop if either:
- it executed properly every line of the file (return EXIT_SUCCESS)
- it finds an error in the file (return EXIT_FAILURE)
- an error occured (return EXIT_FAILURE)

---

## Authors
[Prudence Radebe](https://github.com/MissPhumy)
