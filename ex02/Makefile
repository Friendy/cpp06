# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 18:35:29 by mrubina           #+#    #+#              #
#    Updated: 2024/04/07 00:47:01 by mrubina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS = -std=c++98 -Wall -Werror -Wextra -Wno-unused

SRC = Base.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = identify

all: $(NAME)

$(NAME): $(OBJ)
	c++ -o $(NAME) $(OBJ) $(CXXFLAGS)

%.cpp.o: %.cpp
	c++ $(CXXFLAGS) -c  $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all