NAME = fillit

SRCS = fillit.c \
		check_file_valid.c \
		solve_and_print.c \
		tools.c \
		print_solution.c \
		solve.c \
		

OBJS = $(SRCS:.c=.o)

CFLAGS += -Wall -Wextra

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) libft.a

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re