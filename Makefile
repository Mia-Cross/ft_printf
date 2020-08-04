NAME = libftprintf.a

SRCS = 	ft_numeric_values_utils.c	\
		ft_itoa_base_di.c	\
		ft_itoa_base_ux.c	\
		parsing_functions.c	\
		ft_printf.c	\
		ft_printf_addr.c	\
		ft_printf_char.c	\
		ft_printf_nbr.c	\
		ft_printf_nbr_hx.c	\
		ft_printf_nbr_u.c	\
		ft_printf_str.c

O_FILES = 	$(SRCS:.c=.o)

LIBFT	=		libft.a

CFLAGS = 	-Wall -Wextra -Werror 

HEADER = 	ft_printf.h

.PHONY = 	all clean fclean re bonus
all : $(NAME)

$(NAME):	$(LIBFT) $(O_FILES) 
		ar crs $(NAME) $(O_FILES)

$(LIBFT):
		cd libft; make re; make clean; cd ..
		cp libft/$(LIBFT) $(NAME)

.c.o:
		gcc $(CFLAGS) -I${HEADER} -c $< -o $(<:.c=.o)

clean:
	    rm -rf $(O_FILES)

fclean: clean
		cd libft; rm -f $(LIBFT); cd ..
	    rm -f $(NAME)

re : fclean all
