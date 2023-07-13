CC = g++
# FLAGS = -Wall -Wextra -Werror -std=c++98
FLAGS = -std=c++98


NAME = btc
SRC = main.cpp BitcoinExchange.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all