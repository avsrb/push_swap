NAME	= push_swap

LIST	= main.c utils.c validation.c from_the_article.c sort.c\
		./action/swap.c ./action/rotate.c ./action/reverce_rorate.c ./action/push.c

HEADER	= ./push_swap.h

GCC		=	gcc -Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	: $(LIST) $(HEADER)
	@$(MAKE) -C ./libft
	@$(GCC) $(LIST) ./libft/libft.a -o $(NAME)
	@echo ebal shatal!

clean	:
	@rm -f $(OBJ)
	@$(MAKE) fclean -C ./libft
	@echo Done clean!

fclean	: clean
	@rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
