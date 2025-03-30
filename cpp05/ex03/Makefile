NAME    = bureaucrat-form
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC     = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
			
OBJ     = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean_shrubbery:
	find . -type f -name "*_shrubbery" -delete

clean: clean_shrubbery
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
