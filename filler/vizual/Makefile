#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 16:18:34 by amartyne          #+#    #+#              #
#    Updated: 2018/12/07 18:58:04 by amartyne         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = vizual

SRC = main.c make_map_v.c read_map.c draw.c

HDR = vizual.c filler.h get_next_line.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC) ../libft/libft.a
	gcc -o $(NAME) $(FLAGS) -L minilibx_macos -lmlx -framework OpenGL -framework AppKit -L ../libft -lft  $(SRC)

../libft/libft.a:
	make -C ../libft/

clean:
	make clean -C ../libft

fclean:
	make fclean -C ../libft
	/bin/rm -f $(NAME)

re: fclean all
