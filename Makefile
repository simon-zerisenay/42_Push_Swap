# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 15:37:36 by szerisen          #+#    #+#              #
#    Updated: 2023/04/01 21:07:51 by szerisen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END=$'\x1b[0m
BOLD=$'\x1b[1m
UNDER=$'\x1b[4m
REV=$'\x1b[7m
GREY=$'\x1b[30m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m
BLINK=$'\x1b[48m
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap
C_NAME = checker

SRC_PATH = src/
C_SRC_PATH = bonus/
OBJ_PATH = obj/

SRC		= main.c utilities.c operations.c assign_sorting_index.c validator.c \
		 bidirectional_moves_counter.c target_finder.c sort_three_vals.c midpoint.c calculate_cost.c \
		  order_stack_a.c allocate_position.c reorder_both.c build_stack.c do_both.c

C_SRC	= checker_bonus.c build_stack_bonus.c validate_args_bonus.c operations_bonus.c \
			utilities_bonus.c do_both_bonus.c

# SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

# C_SRCS	= $(addprefix $(C_SRC_PATH), $(C_SRC))
C_OBJ	= $(C_SRC:.c=.o)
C_OBJS	= $(addprefix $(OBJ_PATH), $(C_OBJ))


m: $(OBJ_PATH) $(NAME)

bonus: $(OBJ_PATH) $(C_NAME)

all: $(OBJ_PATH) $(NAME) $(OBJ_PATH) $(C_NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "\n${PURPLE}${BOLD}${BLINK}                                             ✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔                  ${END}"

$(OBJ_PATH)%.o: $(C_SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	
$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	@cd ./libft && make
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)
	@echo "\n${GREEN}${BOLD}${BLINK}>>>>>>>>>>>>>>>>>>>>>>>>>>>>       ✅ ✅ ✅ ✅ ✅  MANDATORY COMPILATION SUCCESSFULL   🙌 🙌 🙌         <<<<<<<<<<<<<<<<<<<<<<<<<<<<${END}"
	@echo "\n${GREEN}${BOLD}${BLINK}>>>>>>>>>>>>>>>>>>>>>>>>>>>>                   BY    SIMON ZERISENAY   😎😎😎😎😎😎😎😎                 <<<<<<<<<<<<<<<<<<<<<<<<<<<<${END}"
$(C_NAME): $(C_OBJS)
	@cd ./libft && make
	@$(CC) $(CFLAGS) $(C_OBJS) ./libft/libft.a -o $(C_NAME)
	@echo "\n${GREEN}${BOLD}${BLINK}>>>>>>>>>>>>>>>>>>>>>>>>>>>>           ✅ ✅ ✅ ✅ ✅  BONUS COMPILATION SUCCESSFULL   🙌 🙌 🙌         <<<<<<<<<<<<<<<<<<<<<<<<<<<<${END}"
	@echo "\n${GREEN}${BOLD}${BLINK}>>>>>>>>>>>>>>>>>>>>>>>>>>>>                   BY    SIMON ZERISENAY   😎😎😎😎😎😎😎😎                 <<<<<<<<<<<<<<<<<<<<<<<<<<<<${END}"
clean:
	@cd ./libft && make fclean
	@rm -rf $(OBJ_PATH)
	@echo "\n${YELLOW}${BOLD}>>>>>>>>>>>>>>>>>>>>>>>>>>>>                 ✅ ✅ ✅ ✅ ✅  CLEANING SUCCESSFULL   🎉🎉🎉🎉🎉🎉       <<<<<<<<<<<<<<<<<<<<<<<<<<<<${END}"
fclean:  clean
	@rm -f $(NAME) $(C_NAME)
	@echo "\n${YELLOW}${BOLD}>>>>>>>>>>>>>>>>>>>>>>>>>>>>                 ✅ ✅ ✅ ✅ ✅  CLEANING SUCCESSFULL   🎉🎉🎉🎉🎉🎉       <<<<<<<<<<<<<<<<<<<<<<<<<<<<${END}"

re: fclean all