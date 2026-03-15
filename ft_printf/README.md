# ft_printf

`ft_printf` is a project from 42 School. The goal is to implement a custom version of the standard C function `printf`. This implementation supports basic format specifiers and returns the number of characters printed, just like the standard `printf`.

---

## 📦 Features

Supported format specifiers:

| Specifier | Description |
|-----------|------------|
| `%c`     | Print a single character |
| `%s`     | Print a string |
| `%p`     | Print a pointer (memory address) |
| `%d`, `%i` | Print a signed decimal number |
| `%u`     | Print an unsigned decimal number |
| `%x`     | Print a number in hexadecimal (lowercase) |
| `%X`     | Print a number in hexadecimal (uppercase) |
| `%%`     | Print the '%' character |

---

## ⚙️ Usage

### Compilation

The project is compiled using the provided `Makefile`. Example:

```bash
make

This will create the library libftprintf.a and object files.

To clean generated files:

make clean   # removes .o files
make fclean  # removes .o files and libftprintf.a
make re      # rebuilds the project from scratch
Example Usage
#include "ft_printf.h"

int main(void)
{
    int ret;

    ret = ft_printf("Hello, %s! Your score is %d%%\n", "Alice", 95);
    ft_printf("Printed characters: %d\n", ret);
    return 0;
}

Output:

Hello, Alice! Your score is 95%
Printed characters: 33
📝 Implementation Details

Uses low-level write(1, ...) for output.

Pointer output includes the 0x prefix.

Handles NULL strings ((null)) and NULL pointers ((nil)).

Recursive functions for numbers (int, unsigned int, hex, pointer).

💻 Project Structure
ft_printf/
├─ ft_printf.c
├─ ft_printchar.c
├─ ft_printstr.c
├─ ft_printnbr.c
├─ ft_print_unsigned.c
├─ ft_print_hex.c
├─ ft_print_ptr.c
├─ ft_printf.h
├─ Makefile
└─ libft/ (helper library)
🔧 Dependencies

libft (included and compiled via the Makefile).
