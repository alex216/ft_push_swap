# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 12:04:47 by yliu              #+#    #+#              #
#    Updated: 2024/02/13 17:05:31 by yliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/zsh

# compiler option and etc
NAME			= push_swap
BONUS_NAME		= checker
LIBRARY			= libft.a
CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=address,integer,undefined
RM				= rm -rf
ECHO			= echo -e

# color and line
DEF_COLOR		=	\033[0;39m
ORANGE			=	\033[0;33m
GRAY			=	\033[0;90m
RED				=	\033[0;91m
GREEN			=	\033[1;92m
YELLOW			=	\033[1;93m
BLUE			=	\033[0;94m
MAGENTA			=	\033[0;95m
CYAN			=	\033[0;96m
WHITE			=	\033[0;97m
LINE			= 	\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500
LINE_BONUS		= 	\u2500

BASIC_SRCS 		= \
				  ./src/main/calculate_procedure.c \
				  ./src/main/copy_argv_to_lst.c \
				  ./src/main/copy_argv_to_lst_helper.c \
				  \
				  ./src/operate/operate_basic_stack_ope1.c \
				  ./src/operate/operate_basic_stack_ope2.c \
				  ./src/operate/operate_both_stack.c \
				  ./src/operate/operate_stack_a.c \
				  ./src/operate/operate_stack_b.c \
				  \
				  ./src/strategy/ope_bubble_sort.c \
				  ./src/strategy/ope_quick_sort.c \
				  ./src/strategy/ope_select_insert.c \
				  ./src/strategy/ope_three_four_five_node.c \
				  \
				  ./src/strategy_helper/append_sa_if_needed.c \
				  ./src/strategy_helper/select_push_insert.c \
				  \
				  ./src/utils/utils_basic.c \
				  ./src/utils/utils_debug.c \
				  ./src/utils/utils_list_cmds.c \
				  ./src/utils/utils_list_query.c \
				  ./src/utils/utils_list_query1.c \
				  ./src/utils/utils_struct_get_context.c \
				  ./src/utils/utils_struct_modify.c \
				  ./src/utils/utils_trivial.c \

##########################################
# library directory
LIB_DIR			= ./libft
BASE_INC_DIR	= ./libft/inc

# mandatory directory
SRCS_DIR		= ./src
OBJS_DIR		= ./obj
MAN_INC_DIR		= $(BASE_INC_DIR) ./inc

# bonus directory
BONUS_SRCS_DIR	= ./bonus_src
BONUS_OBJS_DIR	= ./bonus_obj
BONUS_INC_DIR	= $(BASE_INC_DIR) ./inc ./bonus_inc

##########################################
# headers files
ORIGIN_HEADERS	= ./inc/push_swap.h
LIB				= $(LIB_DIR)/$(LIBRARY)

# mandatory files
SRCS			= $(BASIC_SRCS) ./src/main/main.c
BASIC_OBJS		= $(subst $(SRCS_DIR), $(OBJS_DIR), $(BASIC_SRCS:.c=.o))
OBJS			= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
HEADERS 	   	= $(ORIGIN_HEADERS)

# bonus files
BONUS_SRCS 	   	= $(BONUS_SRCS_DIR)/checker.c
BONUS_OBJS		= $(subst $(BONUS_SRCS_DIR), $(BONUS_OBJS_DIR), $(BONUS_SRCS:.c=.o))
BONUS_HEADERS	= $(HEADERS) ./bonus_inc/push_swap_bonus.h

##########################################

all:			$(NAME) $(BONUS_NAME)

bonus:			$(BONUS_NAME)

$(BONUS_NAME):	$(LIB)
				@make bonus_step_0

$(NAME):		$(LIB)
				@make man_step_0

$(LIB):
				@make -C ./libft

man_step_0:			
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\t./$(NAME) \t$(WHITE)checking...$(DEF_COLOR)"
				@$(ECHO) -n "\e$(GRAY)$(LINE)\r$(DEF_COLOR)"
				@make man_step_1

man_step_1:		$(OBJS) $(LIB)
				@$(CC) $(CFLAGS) $^ -o $(NAME)
				@$(ECHO) -n "\r\e$(GREEN)$(LINE)$(DEF_COLOR)"
				@$(ECHO) "$(GREEN) \u2023 100% $(DEF_COLOR)"
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\t./$(NAME) \t$(GREEN)compiled \u2714$(DEF_COLOR)"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c $(HEADERS)
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(foreach dir_list,$(MAN_INC_DIR),-I$(dir_list)) -c $< -o $@
				@$(ECHO) -n "$(RED)\u2500$(DEF_COLOR)"

bonus_step_0:
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(BONUS_NAME)]\t./$(BONUS_NAME) \t$(WHITE)checking...$(DEF_COLOR)"
				@$(ECHO) -n "\e$(GRAY)$(LINE_BONUS)\r$(DEF_COLOR)"
				@make bonus_step_1

bonus_step_1:	$(BASIC_OBJS) $(BONUS_OBJS) $(LIB)
				@$(CC) $(CFLAGS) $^ -o $(BONUS_NAME)
				@$(ECHO) -n "\r\e$(GREEN)$(LINE_BONUS)$(DEF_COLOR)"
				@$(ECHO) "$(GREEN) \u2023 100% $(DEF_COLOR)"
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(BONUS_NAME)]\t./$(BONUS_NAME) \t$(GREEN)compiled \u2714$(DEF_COLOR)"

$(BONUS_OBJS_DIR)/%.o:$(BONUS_SRCS_DIR)/%.c $(BONUS_HEADERS)
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(foreach dir_list,$(BONUS_INC_DIR),-I$(dir_list)) -c $< -o $@

# other cmds
clean:
				@make clean -C $(LIB_DIR)
				@$(RM) $(OBJS_DIR)
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\tobject files \t$(GREEN)deleted \u2714$(DEF_COLOR)"
				@$(RM) $(BONUS_OBJS_DIR)
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(BONUS_NAME)]\tobject files \t$(GREEN)deleted \u2714$(DEF_COLOR)"

fclean:			
				@make clean
				@$(RM) $(NAME)
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\t./$(NAME) \t$(GREEN)deleted \u2714$(DEF_COLOR)"
				@$(RM) $(BONUS_NAME)
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(BONUS_NAME)]\t./$(BONUS_NAME) \t$(GREEN)deleted \u2714$(DEF_COLOR)"

re:				fclean
				@make
				@make bonus

norm:
				@norminette $(SRCS) $(HEADERS) | grep -v 'OK'; norminette -v

format_norm:
				@c_formatter_42 $(SRCS) $(HEADERS)
				@make norm

visual:			all
				@bash shell_script/pain.sh

.PHONY:			all clean fclean re bonus norm format_norm visual
