NAME	= push_swap

LIST	= main.c utils.c validation.c from_the_article.c sort.c\
		./action/swap.c ./action/rotate.c ./action/reverce_rorate.c ./action/push.c

HEADER	= push_swap.c

GCC		=	gcc -Wall -Wextra -Werror -O2

OBJ		=	$(@patsubst %.c, %.o, $(LIST))

all		: $(NAME)

$(NAME)	: $(OBJ) ./push_swap.h
	@$(MAKE) -C ./libft
	@$(GCC) $(LIST) ./libft/libft.a -o $(NAME)
	@echo Done!

%.o		:	%.c $(HEADER)
	$(GCC) -c $< -o $@

clean	:
	@rm -f $(OBJ)
	@$(MAKE) fclean -C ./libft
	@echo Done clean!

fclean	: clean
	@rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
