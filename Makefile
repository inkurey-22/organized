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
   			src/sort.c  \
   			src/compare.c

BONUS_SRC = src/main.c	\
   			src/add.c	\
   			bonus/del_bonus.c	\
   			src/disp.c	\
   			src/sort.c	\
   			src/compare.c

NAME   =    organized
BONUS_NAME = organized_bonus

CC     =    gcc

CFLAGS =    -Iinclude -Llib -lmy -lshell -g

OBJ    =    $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

bonus:	$(BONUS_NAME)

$(BONUS_NAME):	$(BONUS_OBJ)
	make -C lib
	$(CC) -o $(BONUS_NAME) $(BONUS_OBJ) $(CFLAGS)

run:	all
	./$(NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	make clean -C lib

fclean:	clean
	rm -f $(NAME) $(BONUS_NAME)
	make fclean -C lib

re:	fclean all
