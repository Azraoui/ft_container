NAME = exe

MAIN = main.cpp

SRC = $(MAIN)

INC =	./ft_stack/stack.hpp ./ft_map/map.hpp \
		./ft_map/srcs/avl.hpp ./ft_map/iterators/*.hpp\
		./ft_vector/iterators/*.hpp ./ft_vector/vector.hpp\
		./sharedUtils/*.hpp

DBUG = -fsanitize=address -g

FLAG = -Wall -Wextra -Werror -std=c++98 #$(DBUG)

CPP = c++ $(FLAG)

all: $(NAME)

$(NAME): $(INC) $(SRC)
	@ $(CPP) $(SRC) -o $(NAME)

clean:
	@echo -n
	@rm -f ./a.out

fclean: clean
	@rm -f $(NAME)

re: all fclean

.PHONY: all clean fclean re