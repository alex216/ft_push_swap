# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yliu <yliu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 14:56:08 by yliu              #+#    #+#              #
#    Updated: 2023/11/09 11:57:37 by yliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/zsh

# compiler option and etc
NAME			= libft.a
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf
ECHO			= echo -e

# directory
SRCS_DIR		= ./src/
OBJS_DIR		= ./obj/
INCLUDE			= ./inc/

# files
SRCS 	   		= $(wildcard $(SRCS_DIR)ft_*/*.c)
OBJS			= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
HEADERS 	   	= $(wildcard $(INCLUDE)/*.h)

# make obj dir recursively
MAKE_OBJDIR		= $(shell mkdir -p $(subst $(SRCS_DIR), $(OBJS_DIR), $(dir $(SRCS))))

DROW_GRAY		= $(shell $(ECHO) -n "$(GRAY)$(LINE)")

LINE			=  \u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500

# color
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


all:
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[LIBFT]\tlibft.a \t$(GREEN)checking...$(DEF_COLOR)"
				@$(ECHO) -n "\e$(GRAY)$(LINE)\r$(DEF_COLOR)"
				@make $(NAME)

$(NAME):		$(OBJS) $(HEADERS)
				@$(AR) crs $@ $?
				@$(ECHO) -n "\r\e$(GREEN)$(LINE)$(DEF_COLOR)"
				@$(ECHO) "$(GREEN) \u2023 100% $(DEF_COLOR)"
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[LIBFT]\tlibft.a \t$(GREEN)compiled \u2714$(DEF_COLOR)"

counter			:= 0
# # ifeq ($(shell test $(counter) -gt 0 && echo "true"), true)

$(OBJS_DIR)%.o:	$(MAKE_OBJDIR) $(DROW_GRA) $(SRCS_DIR)%.c

				@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
				@$(ECHO) -n "$(RED)\u2500$(DEF_COLOR)"
				$(eval counter := $(shell echo $$(($(counter) + 1))))
#@echo -n "$(counter)"

# other cmds
clean:
				@$(RM) $(OBJS_DIR)
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[LIBFT]\tobject files \t$(GREEN)deleted \u2714$(DEF_COLOR)"

fclean:			clean
				@$(RM) $(NAME)
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[LIBFT]\tlibft.a \t$(GREEN)deleted \u2714$(DEF_COLOR)"

re:				fclean
				@make

norm:
				@norminette $(SRCS) $(HEADERS); norminette -v

format_norm:
				@c_formatter_42 $(SRCS) $(HEADERS)

debug:			$(CFLAGS) += -g -fsanitize=address -fsanitize=leaks\
				fsanitize=integer

.PHONY:			all clean fclean re bonus norm format_norm debug

print:
