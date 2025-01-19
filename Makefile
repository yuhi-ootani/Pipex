# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 09:25:11 by oyuhi             #+#    #+#              #
#    Updated: 2025/01/19 19:39:29 by oyuhi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc 
CFLAGS =  -Wall -Wextra -Werror

LIBFT = libft/libft.a

OBJ_DIR = objs

SRCS = pipex.c pipex_helper.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT) :
	make -C libft

	
$(OBJ_DIR)/%.o : %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	rm -rf $(OBJ_DIR)
 

re : fclean all

.PHONY: all clean fclean re