NAME = RPN
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp RPN.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp RPN.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	 rm -f $(OBJ)

fclean: clean
	 rm -f $(NAME)

re: fclean all
