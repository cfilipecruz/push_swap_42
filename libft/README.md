# Taco's Libft

Before you begin working in Milestone 0, 42 requires you to first implement your own version of a few C library functions (and some external ones too).
It's pretty neat, because you can (and probably will) use this library through the 42 curriculum.  
So in other words: They made me create the tools that I will use in the future. Cool, right?  
I tried to be as clever as possible with my implementations, although there's a 99.99% certainty that I actually made them less cycle-efficient with my hacky solutions.

## Overview
Here's an overview of all the functions I implemented:
  
Functions to check and manipulate characters:
- ft_isalpha
- ft_isdigit
- ft_isalnum
- ft_isascii
- ft_isprint
- ft_toupper
- ft_tolower

Functions to manipulate strings:
- ft_strlen
- ft_strlcpy
- ft_strlcat
- ft_strchr
- ft_strrchr
- ft_strncmp
- ft_strnstr
- ft_substr
- ft_strjoin
- ft_strtrim
- ft_split
- ft_strmapi
- ft_striteri

Functions to manipulate memory:
- ft_calloc
- ft_memset
- ft_bzero
- ft_memcpy
- ft_memmove
- ft_memchr
- ft_memcmp
- ft_strdup

Functions for int to string conversion:
- ft_atoi
- ft_itoa

Functions to write to a file descriptor:
- ft_putchar_fd
- ft_putstr_fd
- ft_putendl_fd
- ft_putnbr_fd

Functions to create and manipulate lists:
- ft_lstnew
- ft_lstadd_front
- ft_lstsize
- ft_lstlast
- ft_lstadd_back
- ft_lstdelone
- ft_lstclear
- ft_lstiter
- ft_lstmap


The lists that libft works with are defined in the following struct:
```c
typedef struct s_list
{
	void		*content;
	struct s_list   *next;
}                       t_list;
```

## Instructions
To compile Libft (only building a static file is supported in the Makefile) into a static library, just run `make` **without any argument**.  
To clear the output files, including *libft.a*, run `make fclean`. You can also run `make clean` if you want to keep *libft.a*.

### Usage
## Instructions

### Building the library

To compile the library, run:

```sh
make
```

This will generate the static library file `libft.a`.

To remove object files:

```sh
make clean
```

To remove all generated files (including `libft.a`):

```sh
make fclean
```

---

### Using the library

After building `libft.a`, you can use it in your own projects.

#### Example project structure:

```
project/
├── main.c
├── libft/
│   ├── libft.a
│   └── libft.h
```

#### 1. Include the header in your source files:

```c
#include "libft.h"
```

#### 2. Compile your program:

From the root of your project, run:

```sh
cc main.c -Llibft -lft -Ilibft
```

#### Explanation:

* `-Llibft` tells the compiler where to find the library
* `-lft` links `libft.a`
* `-Ilibft` tells the compiler where to find the header file

---

### Alternative (same directory)

If `libft.a` is in the same directory as your source file, you can just compile with:

```sh
cc main.c libft.a
```

---

### Notes

* Make sure to run `make` inside the `libft` directory before compiling your project
* The library is statically linked, meaning all required code is included in the final binary


## Resources
### On the use of AI...
I used AI during this project, yes. And for what, you ask?  
My usage of AI was done strictly only for the following objectives:
* Emotional support
* Debugging memory (*gulp\*)
* Figuring out a function's steps on a high level

I used [CS50's rubber ducky](https://cs50.ai/chat) for this. It sucks at emotional support, but it was pretty alright for the rest.

man - for the most part, manpages were reliable enough for figuring out a function's behavior, but edge-cases that I'd have to handle weren't always mentioned, still, this should be the first place you check.  
peers - talking to someone, both on your level, or under you, or above you, will definitely help you figure out what to do next to finish this project! You can do it! Peers helped me a lot during this project.
