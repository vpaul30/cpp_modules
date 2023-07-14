CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex03
SRC = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

OBJ_DIR = obj/
OBJ =  $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

debug:
	make FLAGS="$(FLAGS) -D DEBUG"

$(OBJ_DIR)%.o:%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -o $@ -c $<

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all