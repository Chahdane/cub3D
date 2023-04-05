SRCS =  ./main.c ./parsing/errors/*.c ./parsing/*.c ./raycasting/*.c ./lib/*.c \
./parsing/tools/*.c ./get_next_line/*.c

NAME = cub3D

FLAGS =  -lmlx -framework OpenGL -framework AppKit

CC = cc

HEADERS = cub3d.h

all : $(NAME)

$(NAME): $(SRCS)	
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	rm -f $(NAME)

fclean : clean

re: fclean all
