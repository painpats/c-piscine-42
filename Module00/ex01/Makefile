PURPLE = \033[10;95m
BLUE = \033[4;49;34m
PINK = \033[4;49;35m
GREY = \033[3;49;90m
C_END = \033[0m

NAME =		phonebook
SRC =		PhoneBook.cpp \
			Contact.cpp \
			main.cpp
OBJ =		$(SRC:.cpp=.o)

CC =		c++
CPPFLAGS =	-Wall -Wextra -Werror -std=c++98
RM =		rm -rf

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "$(PURPLE)##########      MAKE ✔️      ##########$(C_END)"

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	@echo "$(PINK)##########      CLEAN ✔️      ##########$(C_END) $(GREY)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(BLUE)##########      FCLEAN ✔️      ##########$(C_END) $(GREY)"

re: fclean all

.PHONY: all clean fclean re