#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 16:18:34 by amartyne          #+#    #+#              #
#    Updated: 2018/11/13 16:18:37 by amartyne         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =  amartyne.filler

SRC = get_next_line.c filler.c write_file.c make_map.c piece.c distance.c

HDR = filler.h get_next_line.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	make -C libft
	gcc -o $(NAME) $(FLAGS) -L libft -lft $(SRC)

clean:
	make clean -C libft

fclean:
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all