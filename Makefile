# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 14:26:26 by ael-azra          #+#    #+#              #
#    Updated: 2022/07/29 16:45:44 by ael-azra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exe

MAIN = ./main.cpp

SRC = $(MAIN)

INC = ./vector/*

DBUG = -fsanitize=address -g

FLAG = -Wall -Wextra -Werror -std=c++98 $(DBUG)

CP = c++ $(FLAG)

all: $(NAME)

$(NAME): $(INC) $(SRC)
	@ $(CP) $(SRC) -o $(NAME)

clean:
	@echo -n
	@rm -f ./a.out

fclean: clean
	@rm -f $(NAME)

re: all fclean

.PHONY: all clean fclean re