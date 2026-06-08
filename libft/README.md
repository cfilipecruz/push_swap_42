_This project has been created as part of the 42 curriculum by cmarques_

# 📚 Libft

---

## 🧾 Description

**Libft** is a foundational C project from the 42 curriculum that consists of recreating a subset of standard C library functions, along with additional utility functions.

The main goal of this project is to develop a deep understanding of:

* Memory management
* Pointer manipulation
* String handling
* Low-level programming concepts

By reimplementing these functions from scratch, this library becomes a reusable toolkit that will be used in future 42 projects.

---

## ⚙️ Instructions

### 🔧 Compilation

To compile the library, run:

```bash
make
```

This will generate the static library:

```bash
libft.a
```

---

### 🧩 Usage

Include the header file in your project:

```c
#include "libft.h"
```

Compile your program with the library:

```bash
cc main.c libft.a
```

---

### 🧹 Cleaning

```bash
make clean     # removes object files
make fclean    # removes object files and libft.a
make re        # recompiles everything
```

---

## 📦 Library Overview

This library includes reimplementations of standard C functions and additional utilities, grouped as follows:

### 🔤 Character & String Functions

* `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
* `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`
* `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`
* `ft_strmapi`, `ft_striteri`

---

### 🧠 Memory Functions

* `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`
* `ft_memchr`, `ft_memcmp`, `ft_calloc`

---

### 🔢 Conversion Functions

* `ft_atoi`
* `ft_itoa`

---

### 🖨️ File Descriptor Output

* `ft_putchar_fd`, `ft_putstr_fd`
* `ft_putendl_fd`, `ft_putnbr_fd`

---

### 🔗 Linked List Functions (Bonus)

* `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`
* `ft_lstlast`, `ft_lstadd_back`
* `ft_lstdelone`, `ft_lstclear`
* `ft_lstiter`, `ft_lstmap`

These functions implement a singly linked list structure using:

```c
typedef struct s_list
{
	void            *content;
	struct s_list   *next;
}   t_list;
```

---

## 📚 Resources

### 📖 Documentation & References
* man pages (`man malloc`, `man write`, etc.)
* GNU C Library documentation
* 42 intra subject and guidelines

---

### 🤖 AI Usage

AI tools (such as ChatGPT) were used during this project for:

* Clarifying concepts (e.g., pointers, linked lists, memory allocation)
* Debugging specific issues and understanding edge cases

All implementations were written and understood by the author, with AI serving as a learning aid rather than a source of direct solutions.

## 👨‍💻 Author

* cmarques (42 Student)
