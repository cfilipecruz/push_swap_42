NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I.

SRCS = src/push_swap.c \
	src/args_handle.c \
	src/utils.c \
	src/metrics.c \
	src/stack_utils.c \
	src/stack_utils_2.c \
	src/op_s.c \
	src/op_p.c \
	src/math.c \
	src/op_r.c \
	src/op_rr.c \
	src/initialization.c \
	src/algo_simple.c \
	src/algo_simple_exec.c \
	src/algo_simple_helpers.c \
	src/algo_medium.c \
	src/algo_complex.c \
	src/algo_adaptive.c \
	src/benchmark.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
