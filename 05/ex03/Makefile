CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = form
SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
	  RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp \
	  EmptyForm.cpp


OBJ_DIR = obj/
OBJ =  $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)%.o:%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -o $@ -c $<

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f *_shrubbery
	rm -f $(NAME)

re: fclean all