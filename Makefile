# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 16:52:25 by mfadil            #+#    #+#              #
#    Updated: 2023/05/13 19:18:46 by mfadil           ###   ########.fr        #
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
				get_next_line_bonus_utils.c \
				helpers.c \
				hook.c \
				test.c \
				tools_1.c \
				tools_2.c \
				tools_3.c \
				tools_4.c \
				utils.c \
				main.c

OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(O_PATH), $(OBJ))

all: $(O_PATH) $(NAME)

$(O_PATH)%.o: %.c so_long.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(O_PATH):
	mkdir $(O_PATH)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(O_PATH)
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re