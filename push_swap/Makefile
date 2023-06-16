# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 08:56:05 by pcazac            #+#    #+#              #
#    Updated: 2023/06/14 13:54:27 by pcazac           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft/libft.a

VPATH = src/ ; obj/
LIB_PATH = -Llibft
LIBRARY = -lft
OBJ_PATH = obj

SRC = push_swap.c init_check.c push_swap_utils.c list_utils.c sort_check.c\
	sort_small.c presort.c push_b.c move_calculate.c\
	move_calculate2.c choose_smaller.c

OBJ = $(SRC:%.c=$(OBJ_PATH)/%.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
CMLAGS = -fsanitize=address -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@echo "---I'M PUSHING!---"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_PATH) $(LIBRARY)

$(LIBFT):
	@echo "---Calling the library---"
	make -C $(@D) fclean
	make -C $(@D) all

$(OBJ_PATH)/%.o : %.c
	@echo "---Santa's making objects---"
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "---Cleaning this mess---"
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf $(OBJ_PATH)
	$(MAKE) -C ./libft/ clean

fclean: clean
	@echo "---Making a deep clean---"
	@/bin/rm -f $(NAME)
	$(MAKE) -C ./libft/ fclean
	
re: fclean all

memory:
	@echo "---Is this supposed to leak?---"
	@$(CC) $(LIB_PATH) $(LIBRARY) $(CMLAGS) $(OBJ)

.PHONY: all clean fclean re memory
