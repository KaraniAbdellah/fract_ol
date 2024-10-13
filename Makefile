NAME = main
SRC = main.c
OBJ = $(SRC:.c=.o) # define object file "main.o"


CC = gcc
CFLAGS = -Imlx_linux -I/usr/include # include function for drawing from miniLibX
LDFLAGS = -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz # link you code with MiniLibX and X11 libraries


# this for execution
$(NAME): $(OBJ) 
	$(CC) $(OBJ) $(LDFLAGS) $(CFLAGS) -pthread  -o $(NAME) # compile the object
	rm -f $(OBJ) # remove object file after the executable created


# remove object file by running "make clean"
clean:
	rm -f $(OBJ)


# remove object files and the final executable by "make fclean"
fclean: clean
	rm -f $(NAME)


# rebuild the project from scratch by "make re"
re: fclean $(NAME)


