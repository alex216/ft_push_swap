# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 12:04:47 by yliu              #+#    #+#              #
#    Updated: 2023/11/09 12:04:49 by yliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/zsh

# compiler option and etc
NAME			= push_swap
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf
ECHO			= echo -e

# directory
SRCS_DIR		= ./src
OBJS_DIR		= ./obj
INC_DIR			= ./inc

# files
SRCS 	   		= $(wildcard $(SRCS_DIR)/*/*.c)
OBJS			= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
HEADERS 	   	= $(wildcard $(INC_DIR)/*.h)
LIBFT_HEADERS 	= $(wildcard ./libft/$(INC_DIR)/*.h)

# make obj dir recursively
MAKE_OBJDIR		= $(shell mkdir -p $(subst $(SRCS_DIR), $(OBJS_DIR), $(dir $(SRCS))))

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
LINE			=  \u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500

all:
				cp ./libft/libft.a .
#@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\texec file \t$(GREEN)checking...$(DEF_COLOR)"
				@$(ECHO) -n "\e$(GRAY)$(LINE)\r$(DEF_COLOR)"
				make $(NAME)

$(NAME):		$(OBJS) $(HEADERS) $(LIBFT_HEADERS)
				$(CC) $(CFLAGS) -I $(INC_DIR) $(OBJS) $(LIBFT_HEADERS) $(HEADERS) ./libft/libft.a
#@$(ECHO) -n "\r\e$(GREEN)$(LINE)$(DEF_COLOR)"
#@$(ECHO) "$(GREEN) \u2023 100% $(DEF_COLOR)"
#@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\t$(NAME) \t$(GREEN)compiled \u2714$(DEF_COLOR)"

$(OBJS_DIR)/%.o:	$(MAKE_OBJDIR) $(SRCS_DIR)/%.c
				@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# other cmds
clean:
				@$(RM) $(OBJS_DIR)
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\tobject files \t$(GREEN)deleted \u2714$(DEF_COLOR)"

fclean:			clean
				@$(RM) $(NAME)
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\texec file \t$(GREEN)deleted \u2714$(DEF_COLOR)"

re:				fclean
				@make

norm:
				@norminette $(SRCS) $(HEADERS); norminette -v

format_norm:
				@c_formatter_42 $(SRCS) $(HEADERS)

debug:			$(CFLAGS) += -g -fsanitize=address -fsanitize=leaks\
				fsanitize=integer
print_SRCS:
				@echo $(SRCS)

print_OBJS:
				@echo $(OBJS)

print_LIBFT_HEADERS:
				@echo $(LIBFT_HEADERS)


.PHONY:			all clean fclean re bonus norm format_norm debug
