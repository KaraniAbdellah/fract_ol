NAME = main
SRC = main.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Imlx_linux -I/usr/include
LDFLAGS = -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(CFLAGS)  -o $(NAME)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

