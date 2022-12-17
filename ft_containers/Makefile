# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slahlou <slahlou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 10:23:14 by slahlou           #+#    #+#              #
#    Updated: 2022/12/17 10:09:42 by slahlou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_container
COMPILO	=	c++
FLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I $(HEADDIR)

SRCDIR	=	test/
SRC		=	main_map.cpp

OBJDIR	=	obj/
OBJ		=	$(addprefix $(OBJDIR), $(SRC:.cpp=.o))

REAL	=	-DREAL=0

HEADDIR	=	headers/
HEADERS	=	$(addprefix $(HEADDIR), \
			map.hpp\
			vector.hpp\
			stack.hpp\
			traits_utils.hpp\
			traits_utils_pair.hpp\
			)


$(NAME): $(OBJ)
	$(COMPILO) -o $(NAME) $(OBJ)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(COMPILO) $(INCLUDE) $(FLAGS) $(REAL) -c $< -o $@


all: $(NAME)

diff :
	make re NAME='std_container' REAL='-DREAL=1'

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

diffclean :
	rm -rf std_container
	rm -rf diff real mine

re: clean fclean all


.PHONY: re clean fclean diffclean diff
