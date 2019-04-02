##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile
##

SRC_DIR	=	src/
LIB_DIR	=	lib/my/
INC_DIR	=	include/
TESTS_DIR	=	tests/

TARGET	=	my_defender

CFLAGS	=	-g -I $(INC_DIR) -lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio -lcsfml-network

LDFLAGS	=	-L $(LIB_DIR) -lmy

SRC	=	src/main.c \
		src/event.c \
		src/create_struct.c	\
		src/create_settings.c	\
		src/manage_sett_menu.c	\
		src/create_play.c	\
		src/other_events.c	\
		src/display.c	\
		src/events_menu_sett.c	\
		src/clocks_move.c	\
		src/score.c \
		src/gameplay.c	\
		src/scene.c \
		src/different_path.c	\
		src/set_objects.c	\
		src/place_icon.c \
		src/audio_manager.c\
		src/display_game.c	\
		src/path_krillin.c \
		src/events_towers.c


OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all:	$(TARGET)

# `make` normal
$(TARGET): $(OBJ)
	make -C $(LIB_DIR)
	$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS) $(CFLAGS);

# `make clean` clean lib/*.o + projet
clean:
	make clean -C $(LIB_DIR)
	$(RM) $(OBJ)

# `make clean` clean + binary/library
fclean: clean
	make fclean -C $(LIB_DIR)
	$(RM) $(TARGET)

# `make tests_run` criterion
tests_run:
	make re -C $(TESTS_DIR)

re:	fclean all

.PHONY: all clean fclean re
