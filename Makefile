NAME = exe

MAIN = ./main.cpp

SRC = $(MAIN)

INC = ./vector/*

FLAG = -Wall -Wextra -Werror -std=c++98

CP = c++ $(FLAG)

all: $(NAME)

$(NAME): $(INC) $(SRC)
	@ $(CP) $(SRC) -o $(NAME)

clean:
	@echo -n

fclean: clean
	@rm -f $(NAME)

re: all fclean

.PHONY: all clean fclean re