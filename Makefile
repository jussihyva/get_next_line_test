# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 10:58:39 by jkauppi           #+#    #+#              #
#    Updated: 2019/11/23 15:28:14 by jkauppi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	get_next_line_test
SRCS			=	../get_next_line/
INCLUDES		=	$(SRCS)
CC			=	gcc
LIB_FOLDER		=	$(INCLUDES)/libft
LIB_NAME		=	ft
FLAGS			=	-g -Wall -Werror -Wextra -I $(LIB_FOLDER) -I $(INCLUDES)
C_FUNCTIONS		=       get_next_line


C_FILES		=	$(addprefix $(SRCS), $(addsuffix .c, $(C_FUNCTIONS)))
O_FILES		=	                     $(addsuffix .o, $(C_FUNCTIONS))
D_FILES		=	                     $(addsuffix .d, $(C_FUNCTIONS))

all: $(NAME)
.PHONY: all

$(NAME): $(O_FILES) $(NAME).c
	$(CC) $(FLAGS) -o $(NAME) $(NAME).c  $(C_FILES) -L $(LIB_FOLDER) -l $(LIB_NAME)

$(O_FILES):%.o:$(INCLUDES)%.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	\rm -f $(O_FILES)
	\rm -f $(D_FILES)

fclean: clean
	\rm -f $(NAME)
.PHONY: fclean

re: fclean all
