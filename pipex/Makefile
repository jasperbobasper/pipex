SRC = ft_split.c ft_strjoin.c libft_utils.c pipe_utils.c pipex.c
NAME = pipex
LIBNAME = pipex.a
OBJ = $(SRC:.c=.o)
MAIN = main.c
INCLUDES = ./
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): lib
	gcc $(FLAGS) $(MAIN) $(LIBNAME) -o $(NAME)

lib: $(OBJ_FILES)
	gcc $(FLAGS) -I$(INCLUDES) -c $(SRC)
	ar rcs $(LIBNAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(LIBNAME)

re: fclean all

.PHONY: all clean fclean lib re