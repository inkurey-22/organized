##
## EPITECH PROJECT, 2024
## base_repo
## File description:
## Makefile
##

SRC    =    src/main.c	\
			src/add.c	\
			src/del.c	\
			src/disp.c	\
			src/sort.c

NAME   =    organized

CC     =    gcc

CFLAGS =    -Iinclude -Llib -lmy -lshell -g

OBJ    =    $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	make clean -C lib

fclean:	clean
	rm -f $(NAME)
	make fclean -C lib

re:	fclean all
