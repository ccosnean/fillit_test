# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 11:15:24 by ccosnean          #+#    #+#              #
#    Updated: 2016/12/13 15:23:40 by ccosnean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = *.c

OBJ = *.o

all: $(SRC) $(NAME)

$(OBJ):
	@echo "\033[1;32m" "Compiling..." "\033[0m"
	@gcc -c -Wall -Wextra -Werror $(SRC)

$(NAME): $(OBJ)
	@echo "\033[2;32m" "Files '.o' are created!"
	@gcc -o $(NAME) $(OBJ)
	@echo "\033[2m" "fillit executable created! (try ./fillit)"

clean:
	@rm -rf *.o
	@echo "\033[2;33m" "All files '.o' are deleted!" "\033[0m"
fclean: clean
	@rm -rf fillit
	@echo "\033[2;33m" "Executable 'fillit' is deleted!" "\033[0m"
re: fclean all
