# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 16:52:25 by mfadil            #+#    #+#              #
#    Updated: 2023/05/20 13:46:25 by mfadil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= so_long
O_PATH	= obj/


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

all: $(O_PATH) $(NAME)

$(O_PATH)%.o: %.c so_long.h get_next_line_bonus.h ./ft_printf/ft_printf.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(O_PATH):
	mkdir $(O_PATH)

$(NAME): $(OBJS) printf
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) ft_printf/libftprintf.a

clean:
	rm -rf $(O_PATH)
	rm -rf *.o
	make -C ft_printf clean

printf :
	make -C ft_printf

fclean: clean
	rm -f $(NAME)
	rm -f ./ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re