NAME = main
SRC = main.c

CC = gcc
CFLAGS = -Imlx_linux -I/usr/include
LDFLAGS = -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz


$(NAME): $(OBJ)
	$(CC) $(SRC) $(LDFLAGS) -o $(NAME) && ./$(NAME)


clean:
	rm -f $(SRC)

fclean: clean
	rm -f $(NAME)


