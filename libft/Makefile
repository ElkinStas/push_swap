NAME = libftprintf.a

SRC = ./libft/*.c
OBJS = countresh2.o\
		ft_atoi.o\
		ft_bzero.o\
		ft_checklongitude.o\
		ft_convertation2.o\
		ft_create_base.o\
		ft_indent4.o\
		ft_isalnum.o\
		ft_isalpha.o\
		ft_isascii.o\
		ft_isdigit.o\
		ft_isprint.o\
		ft_itoa.o\
		ft_loputnbrindentprint.o\
		ft_lstadd.o\
		ft_lstdel.o\
		ft_lstdelone.o\
		ft_lstiter.o\
		ft_lstmap.o\
		ft_lstnew.o\
		ft_memalloc.o\
		ft_memccpy.o\
		ft_memchr.o\
		ft_memcmp.o\
		ft_memcpy.o\
		ft_memdel.o\
		ft_memmove.o\
		ft_memset.o\
		ft_print_float.o\
		ft_printf.o\
		ft_putchar_fd.o\
		ft_putchar.o\
		ft_putendl_fd.o\
		ft_putendl.o\
		ft_putnbr_fd.o\
		ft_putnbr.o\
		ft_putpointer.o\
		ft_putstr_fd.o\
		ft_putstr.o\
		ft_qsort.o\
		ft_single_part.o\
		ft_strcat.o\
		ft_strchr.o\
		ft_strclr.o\
		ft_strcmp.o\
		ft_strcpy.o\
		ft_strdel.o\
		ft_strdup.o\
		ft_strequ.o\
		ft_striter.o\
		ft_striteri.o\
		ft_strjoin.o\
		ft_strlcat.o\
		ft_strlen.o\
		ft_strmap.o\
		ft_strmapi.o\
		ft_strncat.o\
		ft_strncmp.o\
		ft_strncpy.o\
		ft_strnequ.o\
		ft_strnew.o\
		ft_strnstr.o\
		ft_strrchr.o\
		ft_strsplit.o\
		ft_strstr.o\
		ft_strsub.o\
		ft_strtrim.o\
		ft_text.o\
		ft_tolower.o\
		ft_toupper.o\
		ft_zerodigital.o\
		functflag2.o\
		functionfloat.o\
		functionindent5.o\
		functionsixbig.o\
		get_next_line.o\
		zerodigital2.o\
		zerodigital3.o\
		zerodigital4.o\
		zerodigital6.o\
		zerodigital7.o\
		zerodigital8.o\






all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) -I /libft/libft.h
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
