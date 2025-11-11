#  ft_printf — 100/100 ✅



##  Overview

`ft_printf` recreates the behavior of the standard C `printf` function — handling formatted output using **variadic functions** and **low-level system calls** (`write`).
The goal of the project is to understand argument parsing, memory management, and output formatting at a deeper level.

---

##  Features

✅ Supported conversions:

* `%c` — Print a single character
* `%s` — Print a string (`(null)` if `NULL`)
* `%p` — Print a pointer address (`(nil)` if `NULL`)
* `%d` / `%i` — Print a signed decimal integer
* `%u` — Print an unsigned integer
* `%x` / `%X` — Print hexadecimal (lowercase / uppercase)
* `%%` — Print a literal `%`

✅ Behavior:

* Returns the **number of characters printed**
* Fully **norm-compliant**, **leak-free**, and **identical to real `printf`**

---

##  Usage

###  Compilation

```bash
make
```

This will generate:

```
llibftprintf.a
```

###  Example

```c
#include "ft_printf.h"

int main(void)
{
	int count = ft_printf("Hello %s, I am %d years old!\n", "Name", 21);
	ft_printf("Printed %d characters.\n", count);
	return (0);
}
```

Compile and run:

```bash
gcc main.c libftprintf.a && ./a.out
```

---

##  Project Structure

```
ft_printf/
├── ft_printf.c
├── ft_printf.h
├── utils.c
└── Makefile
```

---

##  Results

| Category         | Result             |
| ---------------- | ------------------ |
| Moulinette grade |  **100/100**     |
| Norminette       | ✅ Passed           |
| Memory leaks     | 🚫 None            |
| Behavior         | ✅ Matches `printf` |
