# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hastid <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 22:07:00 by hastid            #+#    #+#              #
#    Updated: 2019/12/20 10:57:44 by hastid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAG = -Wall -Wextra -Werror

SRC = src/main.c \
	  src/julia.c \
	  src/burning.c \
	  src/mandelbrot.c \
	  src/fract_hook.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(FLAG) libft/libft.a -lmlx -framework OpenGl -framework AppKit $(OBJ) -o $(NAME)

%.o: %.c
	@gcc $(FLAC) -o $@ -c $<

clean:
	@make clean -C libft
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
