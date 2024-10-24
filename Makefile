NAME = main
SRC = julia.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -I./minilibx-linux -I/usr/include # Include directories for headers
LDFLAGS = -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz # Libraries to link


$(NAME): $(OBJ) 
	$(CC) $(OBJ) $(LDFLAGS) $(CFLAGS) -pthread -o $(NAME) # Compile and link
	rm -f $(OBJ) # Remove object files after building

clean:
	rm -f $(OBJ) # Remove object files

fclean: clean
	rm -f $(NAME) # Remove the executable

re: fclean $(NAME) # Target to rebuild everything from scratch

