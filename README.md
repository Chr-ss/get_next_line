# Get Next Line

## Description
This project involves creating a function that reads and returns a line from a file descriptor. It introduces an important concept in C programming: static variables.

## Features
- Reads a line from a file descriptor, returning it as a string.
- Works for both files and standard input.
- Returns `NULL` when there is nothing left to read or when an error occurs.
- Must include the newline character (`\n`) except when EOF is reached.

## Mandatory Requirements
- Function Name: `get_next_line`.
- Prototype: `char *get_next_line(int fd);`.
- Allowed external functions: `read`, `malloc`, and `free`.
- No use of global variables.
- Must compile with `-D BUFFER_SIZE=n`.
- Code should be norm-compliant and not cause memory leaks.

## Bonus Part
- Implement `get_next_line` to manage multiple file descriptors simultaneously.
- Use only one static variable.
- Submit additional files with `_bonus` suffix:
  - `get_next_line_bonus.c`
  - `get_next_line_bonus.h`
  - `get_next_line_utils_bonus.c`.

## Compilation & Testing
Compile with:
```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

Run with:
```sh
./gnl <filename>
```

## Submission Guidelines
- Submit the following files:
  - `get_next_line.c`
  - `get_next_line_utils.c`
  - `get_next_line.h`
  - (Bonus) `get_next_line_bonus.c`, `get_next_line_utils_bonus.c`, `get_next_line_bonus.h`.
- Make sure all required rules are in `Makefile`.
- Submit only via the assigned Git repository.

## Notes
- Ensure the function works with different buffer sizes (1, 9999, etc.).
- `lseek()` and `libft` usage is forbidden.
- Prepare various test cases, as peer evaluation will be conducted.
