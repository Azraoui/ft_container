# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 10:02:58 by ael-azra          #+#    #+#              #
#    Updated: 2022/04/01 10:23:25 by ael-azra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = container

SRC = ./main.cpp

CMP = c++

FLAG = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRC:.cpp=.o)

INC = 

all: $(NAME)

$(NAME): $(SRC) $(INC)
	@$(CMP) $(FLAG) $(SRC) -c
	@clang++ $(FLAG) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all