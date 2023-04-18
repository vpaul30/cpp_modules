CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = fixed
SRC = main.cpp Fixed.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all