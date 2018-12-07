#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 16:18:34 by amartyne          #+#    #+#              #
#    Updated: 2018/12/07 18:57:06 by amartyne         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =  amartyne.filler

SRC = filler.c write_file.c make_map.c piece.c distance.c can_insert.c \
find_t.c

HDR = filler.h get_next_line.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC) ./libft/libft.a
	gcc -o $(NAME) $(FLAGS) -L libft -lft $(SRC)

./libft/libft.a:
	make -C libft

clean:
	make clean -C libft

fclean:
	make fclean -C libft
	/bin/rm -f $(NAME)

visual:
	make -C ./vizual

re: fclean all
