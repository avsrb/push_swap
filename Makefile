NAME	= push_swap
NAME_B	= checker

LIST	= ./src/main.c ./src/utils.c ./src/validation.c ./src/sort.c\
		./action/swap.c ./action/rotate.c ./action/reverce_rotate.c ./action/push.c

LIST_B	= ./bonus/main.c \
		./bonus/action/swap.c ./bonus/action/rotate.c ./bonus/action/reverce_rotate.c ./bonus/action/push.c

HEADER	= ./push_swap.h

OBJ		=	$(patsubst %.c, %.o, $(LIST))

OBJ_B	=	$(patsubst %.c, %.o, $(LIST_B))

GCC		=	gcc -Wall -Wextra -Werror

all		: $(NAME)

bonus	: $(NAME_B)

%.o	:	%.c $(HEADER)
	$(GCC) -c $< -o $@

$(NAME)	: $(OBJ) $(LIST)
	$(MAKE) -C ./libft
	$(GCC) $(LIST) ./libft/libft.a -o $(NAME)
#	@echo Сould you please give me the numbers to sort?

$(NAME_B)	: $(OBJ_B) $(LIST_B)
	$(MAKE) -C ./libft
	$(GCC) $(LIST_B) ./libft/libft.a -o $(NAME_B)
	#@echo Play?

clean	:
	rm -f $(OBJ) $(OBJ_B)
	$(MAKE) fclean -C ./libft
#	@echo Done clean!

fclean	: clean
	rm -f $(NAME) $(NAME_B)

re		:	fclean all

.PHONY	:	all clean fclean re bonus
