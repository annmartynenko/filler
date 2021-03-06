cmake_minimum_required(VERSION 3.12)
project(vizual)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        Makefile
        vizual.h
        ./libft/get_next_line.c
        ./libft/ft_arrfree.c
        ./libft/ft_atoi.c
        ./libft/ft_bzero.c
        ./libft/ft_foreach.c
        ./libft/ft_isalnum.c
        ./libft/ft_isalpha.c
        ./libft/ft_isascii.c
        ./libft/ft_isdigit.c
        ./libft/ft_isprint.c
        ./libft/ft_itoa.c
        ./libft/ft_lstadd.c
        ./libft/ft_lstaddback.c
        ./libft/ft_lstdel.c
        ./libft/ft_lstdelone.c
        ./libft/ft_lstiter.c
        ./libft/ft_lstmap.c
        ./libft/ft_lstnew.c
        ./libft/ft_memalloc.c
        ./libft/ft_memccpy.c
        ./libft/ft_memchr.c
        ./libft/ft_memcmp.c
        ./libft/ft_memcmp.c
        ./libft/ft_memcpy.c
        ./libft/ft_memdel.c
        ./libft/ft_memmove.c
        ./libft/ft_putstr.c
        ./libft/ft_memset.c
        ./libft/ft_power.c
        ./libft/ft_putchar.c
        ./libft/ft_putchar_fd.c
        ./libft/ft_putnbr_fd.c
        ./libft/ft_putendl.c
        ./libft/ft_putendl_fd.c
        ./libft/ft_range.c
        ./libft/ft_putnbr.c
        ./libft/ft_putstr_fd.c
        ./libft/ft_sqrt.c
        ./libft/ft_toupper.c
        ./libft/ft_strcat.c
        ./libft/ft_strchr.c
        ./libft/ft_strclr.c
        ./libft/ft_strcmp.c
        ./libft/ft_strcpy.c
        ./libft/ft_strdel.c
        ./libft/ft_strdup.c
        ./libft/ft_strjoin.c
        ./libft/ft_strequ.c
        ./libft/ft_striter.c
        ./libft/ft_striteri.c
        ./libft/ft_strlcat.c
        ./libft/ft_strlen.c
        ./libft/ft_strmap.c
        ./libft/ft_strmapi.c
        ./libft/ft_strncat.c
        ./libft/ft_tolower.c
        ./libft/ft_strsplit.c
        ./libft/ft_swap.c
        ./libft/ft_strtrim.c
        ./libft/ft_strsub.c
        ./libft/ft_strstr.c
        ./libft/ft_strrchr.c
        ./libft/ft_strnstr.c
        ./libft/ft_strnew.c
        ./libft/ft_strncmp.c
        ./libft/ft_strnequ.c
        ./libft/ft_strncpy.c
        ./libft/ft_strsub.c
        make_map_v.c.c
        read_map.c
        main.c
        ./libft/ft_printf/ft_printf.c
        ./libft/ft_printf/number.c
        ./libft/ft_printf/ft_itoa_base.c
        ./libft/ft_printf/ft_putunsnbr.c
        ./libft/ft_printf/extra_fun.c ./libft/ft_printf/unicode.c ./libft/ft_printf/find_flag.c
        ./libft/ft_printf/for_flags.c ./libft/ft_printf/if_flags.c
        ./libft/ft_printf/ft_putstring.c ./libft/ft_printf/ft_putnumber.c ./libft/ft_printf/specifier.c
        ./libft/ft_printf/if_flags_d.c
        ./libft/ft_printf/ft_putchar.c ./libft/ft_printf/ft_putstr.c
        ./libft/ft_printf/ft_memcpy.c
        ./libft/ft_printf/ft_putnbr.c ./libft/ft_printf/if_flags_ito.c
        ./libft/ft_printf/valid.c ./libft/ft_printf/not_spec.c ./libft/ft_printf/ft_itoa_base_int.c
        ./libft/ft_printf/ft_itoa_unslong.c
        ./libft/ft_printf/ft_itoa_max.c ./libft/ft_printf/ft_putint.c ./libft/ft_printf/for_add.c
        ./libft/ft_printf/for_p.c
        )
