
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xortega <xortega@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 12:15:31 by xortega           #+#    #+#              #
#    Updated: 2024/10/02 12:25:22 by xortega          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Traps

SRC = main.cpp ClapTrap.cpp
OBJ = $(SRC:%.cpp=%.o)
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
