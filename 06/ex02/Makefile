CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = realType
SRC = main.cpp Base.cpp A.cpp B.cpp C.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

.cpp.o:
	$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all