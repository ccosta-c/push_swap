# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 20:09:19 by ccosta-c          #+#    #+#              #
#    Updated: 2023/04/29 17:24:52 by ccosta-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COLORS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COMMANDS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CC = cc
RM = rm -f
AR = ar -rcs

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FLAGS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CFLAGS		= -Wall -Wextra -Werror -g
MKFLAGS		= --no-print-directory
LIBFTFLAGS	= -L ./libft -lft

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FOLDERS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
DEPS		= includes
SRCS		= .
SRCS_BONUS	= bonus
LIBFT		= libft

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FILES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
SRC				= lst_operations.c checks.c sort.c utils_3.c utils.c operations.c operations_2.c algorithms.c utils_2.c
OBJS 			:= $(SRC:.c=.o)
BONUS			= lst_operations.c checks.c utils.c operations.c operations_2.c utils_2.c
OBJS_BONUS		:= $(BONUS:.c=.o)
NAME			= push_swap
NAME_BONUS		= checker
TARGET			= $(addprefix $(SRCS)/, $(OBJS))
TARGET_BONUS	= $(addprefix $(SRCS_BONUS)/, $(OBJS_BONUS))


#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RULES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
all: $(NAME)

$(NAME): $(TARGET)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)libft/*$(RESET)"
	make $(MKFLAGS) -sC $(LIBFT)

	$(CC) $(CFLAGS) main.c $(TARGET) $(LIBFTFLAGS) -o $(NAME)

	echo "$(GREEN)Done.$(RESET)"

%.o : %.c
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean $(MKFLAGS) -sC $(LIBFT)
	echo "[$(RED) Deleted $(RESET)] $(GREEN)libft/*.o$(RESET)"
	echo "[$(RED) Deleted $(RESET)] $(GREEN)*/*.o$(RESET)"
	$(RM) $(TARGET) $(TARGET_BONUS)

fclean: clean
	make fclean $(MKFLAGS) -sC $(LIBFT)
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

bonus: $(TARGET_BONUS)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)libft/*$(RESET)"
	make $(MKFLAGS) -sC $(LIBFT)
	$(CC) $(CFLAGS) bonus/main_bonus.c $(TARGET_BONUS) $(LIBFTFLAGS) -o $(NAME_BONUS)
	echo "$(GREEN)Done.$(RESET)"

re: fclean all

.SILENT:
