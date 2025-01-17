# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 13:46:22 by oyuhi             #+#    #+#              #
#    Updated: 2025/01/17 12:33:23 by oyuhi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

#r: Add or replace object files in the archive.
#c: Create the archive if it doesn’t already exist.
#s: Create an index of symbols to speed up linking.
ARS = ar rcs



SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c \
		ft_lstnew_bonus.c ft_lstsize_bonus.c \
		ft_get_next_line.c ft_get_next_line_utils.c \
		ft_printf.c ft_printf_utils.c \
		ft_array_dup.c ft_array_free.c ft_error.c ft_strlen_newline.c \
		

OBJ_DIR = objs
OBJS = $(SRCS:.c=.o)
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME) 

$(NAME): $(OBJS)
	$(ARS) $(NAME) $(OBJS)
	
# Compile each .c file into its corresponding .o file.
# %: matches any string (used for pattern matching).
# $<: the first dependency (source .c file).
# $@: the target file (.o file to be created).
$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -f $(BONUS_FLAG)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all bonus clean fclean re