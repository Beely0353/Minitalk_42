NAME = minitalk.a

GCC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar

RC = -rcs

SERVER = server
CLIENT = client


LIBFT = $(addprefix libft/,) \
	   ft_strlen.c \
	   ft_atoi.c \
	   ft_isdigit.c \
	   ft_isascii.c \
	   ft_putchar_fd.c \
	   ft_putnbr_fd.c \

SRC = server.c \
	client.c \
# ifdef FLAG
# 	SRC_COMP = $(SRC) $(SRC_B)
# else
# 	SRC_COMP = $(SRC)
# endif

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	mv libft/libft.a ./minitalk.a
	$(AR) ${RC} $(NAME) $(OBJ)
	$(CC) -o $(SERVER) server.c $(NAME)
	$(CC) -o $(CLIENT) client.c $(NAME)

%.o: %.c
	$(GCC) $(FLAGS) -c $< -o $@

clean:
	make -C libft/ clean
	rm -rf ${OBJ}

fclean:clean
	rm -rf ${NAME} ${CLIENT} ${SERVER}

re: fclean all
