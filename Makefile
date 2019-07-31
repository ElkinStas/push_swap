# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhudson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 17:39:25 by bhudson           #+#    #+#              #
#    Updated: 2019/07/26 12:14:09 by bhudson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PUSH = push_swap

NAME_CH = checker

SRC_CH = main_for_checker.c \
		ft_min_max.c \
		ft_checker.c \
		operations1.c \
		operations2.c \
		inicialization.c \
		validation.c \
		sort.c \
		ft_check_cyclic_sort.c \
		counting.c \
		ft_memory.c \

SRC_PUSH = main.c \
		ft_min_max.c \
		ft_checker.c \
		operations1.c \
		operations2.c \
		inicialization.c \
		validation.c \
		sort.c \
		ft_check_cyclic_sort.c \
		counting.c \
		ft_memory.c \

OBJS_P = main.o\
		ft_min_max.o\
		ft_checker.o\
		operations1.o\
		operations2.o\
		inicialization.o\
		validation.o\
		sort.o\
		ft_check_cyclic_sort.o\
		counting.o\
		ft_memory.o\

OBJS_CH = main_for_checker.o\
		ft_min_max.o\
		ft_checker.o\
		operations1.o\
		operations2.o\
		inicialization.o\
		validation.o\
		sort.o\
		ft_check_cyclic_sort.o\
		counting.o\
		ft_memory.o\

INCLUDES = libft/libftprintf.a

all: $(NAME_PUSH) $(NAME_CH)

$(NAME_PUSH): $(SRC_PUSH)
		make -C libft
		gcc -c -Wall -Werror -Wextra $(SRC_PUSH) -I. -g
		gcc -Wall -Werror -Wextra $(OBJS_P) $(INCLUDES) -o $(NAME_PUSH)

$(NAME_CH): $(SRC_CH)
		gcc -c -Wall -Werror -Wextra $(SRC_CH) -I.
		gcc -Wall -Werror -Wextra $(OBJS_CH) $(INCLUDES) -o $(NAME_CH)

clean:
		make clean -C libft
		rm -f $(OBJS_P) $(OBJS_CH)

fclean: clean
		make fclean -C libft
		rm -f $(NAME_PUSH)
		rm -f $(NAME_CH)

re: fclean all
