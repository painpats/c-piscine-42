NAME =		megaphone
SRC =		megaphone.cpp
OBJ =		$(SRC:.cpp=.o)

CC =		c++
CPPFLAGS =	-Wall -Wextra -Werror -std=c++98
RM =		rm -rf

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
