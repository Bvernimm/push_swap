NAME = push_swap

SRC = $(wildcard src/*.c)\

INCLUDES = includes

OBJ = $(SRC:.c=.o)

CFLAGS = #-Wall -Wextra -Werror

CC = gcc

$(RM) = rm -rf

.c.o: $(SRC)
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c -o $@ $<
	@printf "%-42s\r" $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@printf "%-42s\r"

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: $(NAME) all clean fclean re