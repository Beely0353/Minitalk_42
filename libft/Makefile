NAME = libft.a

GCC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar

RC = -rcs

SRC = ft_strlen.c ft_atoi.c ft_isdigit.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c 

OBJ = ${SRC:.c=.o}

$(NAME): $(OBJ)
	$(AR) ${RC} $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c
	$(GCC) $(FLAGS) -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean:clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
