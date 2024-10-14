PURPLE = \033[4;49;31m
BLUE = \033[4;49;34m
PINK = \033[4;49;35m
C_END = \033[0m

NAME =		LOOOOOSEEERR
SRC =		main.cpp \
			sed.cpp 
OBJ =		$(SRC:.cpp=.o)

CC =		c++
CPPFLAGS =	-Wall -Wextra -Werror -std=c++98 -g
RM =		rm -rf

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "$(PURPLE)##########      MAKE ✔️       ##########$(C_END)"

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	@echo "$(PINK)##########      CLEAN ✔️      ##########$(C_END)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(BLUE)##########      FCLEAN ✔️     ##########$(C_END)"

re: fclean all

.PHONY: all clean fclean re