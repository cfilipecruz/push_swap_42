NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I.

SRCS = src/push_swap.c \
	src/args_handle.c \
	src/utils.c \
	src/metrics.c \
	src/temp_functions.c \
	src/stack_utils.c \
	src/op_s.c \
	src/op_p.c \
	src/op_r.c \
	src/op_rr.c \


OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME) clean_objs

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean_objs:
	rm -f $(OBJS) src/*.o

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean_objs clean fclean re
