# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 16:52:25 by mfadil            #+#    #+#              #
#    Updated: 2023/05/22 14:30:27 by mfadil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= so_long
O_PATH	= obj/

PRINTF_LIB = ft_printf/libftprintf.a


SRC		=		check_contour.c \
				check_data.c \
				check_matrix.c \
				do_collect.c \
				do_moves.c \
				exit.c \
				get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
				helpers.c \
				hook.c \
				tools_1.c \
				tools_2.c \
				tools_3.c \
				tools_4.c \
				utils.c \
				main.c

OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(O_PATH), $(OBJ))

all: $(NAME)

$(O_PATH)%.o: %.c so_long.h get_next_line_bonus.h ./ft_printf/ft_printf.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@


$(NAME): $(OBJS) $(PRINTF_LIB)
	$(CC) $(OBJS) ft_printf/libftprintf.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf ./obj/*.o
	make -C ft_printf clean

$(PRINTF_LIB) :
	make -C ft_printf

fclean: clean
	rm -f $(NAME)
	rm -f ./ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re