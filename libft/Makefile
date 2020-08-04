NAME = libft.a

SRC = 	ft_atoi.c	\
		ft_bzero.c	\
		ft_calloc.c	\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_itoa.c	\
		ft_memccpy.c	\
		ft_memchr.c	\
		ft_memcmp.c	\
		ft_memcpy.c	\
		ft_memmove.c	\
		ft_memset.c	\
		ft_putchar_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_putstr_fd.c	\
		ft_split.c	\
		ft_strchr.c	\
		ft_strrchr.c	\
		ft_strdup.c	\
		ft_strjoin.c	\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strlen.c	\
		ft_strmapi.c	\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strtrim.c	\
		ft_substr.c	\
		ft_tolower.c	\
		ft_toupper.c

BONUS_SRC =	ft_atoi.c	\
			ft_bzero.c	\
			ft_calloc.c	\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_itoa.c	\
			ft_memccpy.c	\
			ft_memchr.c	\
			ft_memcmp.c	\
			ft_memcpy.c	\
			ft_memmove.c	\
			ft_memset.c	\
			ft_putchar_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\
			ft_split.c	\
			ft_strchr.c	\
			ft_strrchr.c	\
			ft_strdup.c	\
			ft_strjoin.c	\
			ft_strlcat.c	\
			ft_strlcpy.c	\
			ft_strlen.c	\
			ft_strmapi.c	\
			ft_strncmp.c	\
			ft_strnstr.c	\
			ft_strtrim.c	\
			ft_substr.c	\
			ft_tolower.c	\
			ft_toupper.c	\
			ft_lstnew.c	\
			ft_lstadd_front.c	\
			ft_lstsize.c	\
			ft_lstlast.c	\
			ft_lstadd_back.c	\
			ft_lstdelone.c 	\
			ft_lstclear.c	\
			ft_lstiter.c 	\
			ft_lstmap.c	

CFLAGS = 	-Wall -Wextra -Werror

INCLUDES = 	libft.h

O_FILES = 	$(SRC:.c=.o)

BONUS_O_FILES =	$(BONUS_SRC:.c=.o)

.PHONY = all clean fclean re bonus
all : $(NAME)

$(NAME):	$(O_FILES)
	            ar crs $(NAME) $(O_FILES)

%.o: %.c
	        gcc  $(CFLAGS) -I${INCLUDES} -c $< -o $@

clean:
	            rm -rf $(O_FILES) $(BONUS_O_FILES)

fclean: clean
	            rm -f $(NAME)

re : fclean all

bonus:		$(BONUS_O_FILES) $(NAME)
				ar crs $(NAME) $(BONUS_O_FILES)
