# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 20:09:37 by mporras-          #+#    #+#              #
#    Updated: 2023/12/12 13:21:52 by rbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
MANDATORY		=	mandatory
SRC_DIR			=	srcs/
OBJS_DIR		=	obj/
SRCS			=	ft_printf.c \
					ft_print_str.c \
					ft_print_hex.c \
					ft_print_int.c \
					ft_strdup.c \
					ft_print_ptr.c
OBJS 			=	$(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

CC			 	= 	cc
RM			 	= 	rm	-rf
CFLAGS		 	= 	-Wall -Wextra -Werror -c
INCLUDES	 	= 	-I.	ft_printf.h

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@ar	rcs	$(NAME)	$(OBJS)
	@echo $(NAME) "\033[0;32mCompiled\033[0m"

$(OBJS_DIR)%.o: $(SRC_DIR)%.c ft_printf.h Makefile
	@$(CC) -Iinc $(CFLAGS) -g -c $< -o $@
	@echo Compiling $< ...

$(OBJS_DIR):
	-@mkdir $(OBJS_DIR)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_DIR)
	@echo "\033[0;31mCleaning\033[0m" ft_printf objects

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31mCleaning\033[0m" $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re bonus