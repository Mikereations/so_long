NAME = so_long

SOURCES =	./conditions/conditions.c ./conditions/content_conditions.c ./conditions/walls.c \
			./utils/error.c ./utils/utils.c ./utils/player_utils.c ./utils/conclusions.c ./utils/enemy_utils.c ./utils/numbers.c\
			./so_long.c
			
BONSOURCES = ./conditions/conditions.c ./conditions/content_condition_bonus.c ./conditions/walls.c \
			./utils/error.c ./utils/utils.c ./utils/player_utils.c ./utils/conclusions.c ./utils/enemy_utils.c ./utils/numbers.c\
			./so_long.c

OBJECTS = $(SOURCES:.c=.o);

BONOBJECTS = $(BONSOURCES:.c=.o);


CFLAGS = -Wall -Werror -Wall

CC = gcc

LINK = -framework OpenGL -framework Appkit

MLX = ./minilibx/libmlx.a

LIBFT =  ./libft/libft.a

PRINTF = ./printf/libftprintf.a

${NAME} : $(SOURCES)
	$(MAKE) -C ./minilibx
	$(MAKE) -C ./libft
	$(MAKE) -C ./printf
	${CC} ${CFLAGS} -o so_long $(SOURCES) $(MLX) $(LIBFT) $(PRINTF) $(LINK)

all : ${NAME}

clean :
	$(MAKE) clean -C ./minilibx
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./printf

bonus : $(BONSOURCES)
	$(MAKE) -C ./minilibx
	$(MAKE) -C ./libft
	$(MAKE) -C ./printf
	${CC} ${CFLAGS} -o so_long $(BONSOURCES) $(MLX) $(LIBFT) $(PRINTF) $(LINK)

fclean : clean
	rm -f ${NAME}

re : fclean all
