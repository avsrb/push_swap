NAME	=	libft.a

LIST	=	ft_atoi.c			ft_bzero.c			ft_isalnum.c\
			ft_isalpha.c		ft_isascii.c		ft_isdigit.c\
			ft_isprint.c		ft_memccpy.c		ft_memchr.c\
			ft_memcmp.c			ft_memcpy.c			ft_memmove.c\
			ft_memset.c			ft_strchr.c			ft_strlcat.c\
			ft_strlcpy.c		ft_strlen.c			ft_strncmp.c\
			ft_strnstr.c		ft_strrchr.c		ft_tolower.c\
			ft_toupper.c 		ft_calloc.c			ft_strdup.c\
			ft_substr.c			ft_strjoin.c		ft_strtrim.c\
			ft_putchar_fd.c		ft_putstr_fd.c		ft_putendl_fd.c\
			ft_putnbr_fd.c		ft_split.c			ft_itoa.c\
			ft_strmapi.c		ft_strnew.c			ft_strcpy.c\
			ft_strclr.c			get_next_line.c		get_next_line_utils.c\
			ft_atoi_int.c		ft_error.c			ft_lstfind.c\
			ft_lstnew.c			ft_lstadd_front.c	ft_lstsize.c\
			ft_lstlast.c		ft_lstadd_back.c	ft_lstdelone.c\
			ft_lstclear.c		ft_lstfind_error.c		ft_lstfindmax.c\
			ft_max.c			ft_lstfindmin.c		ft_lstmed.c\
			ft_strcmp.c
			
HEADER	=	libft.h	get_next_line.h

OBJ		=	$(patsubst %.c, %.o, $(LIST))

FLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	ar rcs $(NAME) $?

%.o		:	%.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@
	
clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re
