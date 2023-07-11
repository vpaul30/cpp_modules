CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = bureaucrat
SRC = main.cpp Bureaucrat.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all