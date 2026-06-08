

LIBFT = libft/libft.a

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT)
	cc $(SRCS) $(LIBFT) -o $(NAME)