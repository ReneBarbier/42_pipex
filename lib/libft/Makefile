# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 16:49:11 by rbarbier          #+#    #+#              #
#    Updated: 2023/12/12 13:21:59 by rbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = srcs/
OBJS_DIR = obj/

SOURCES =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
			ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
			ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(addprefix $(OBJS_DIR), $(SOURCES:.c=.o))

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@ar	rcs	$(NAME)	$(OBJS_DIR)*.o
	@echo $(NAME) "\033[0;32mCompiled\033[0m"

$(OBJS_DIR)%.o: $(SRC_DIR)%.c libft.h Makefile
	@cc -Iinc $(CFLAGS) -g -c $< -o $@
	@echo Compiling $< ...

$(OBJS_DIR):
	-@mkdir $(OBJS_DIR)

clean:
	@rm -fr $(OBJS)
	@rm -fr $(OBJS_DIR)
	@echo "\033[0;31mCleaning\033[0m" libft objects

fclean: clean
	@rm -fr $(NAME)
	@echo "\033[0;31mCleaning\033[0m" $(NAME)

re: fclean all

.PHONY: all clean fclean re
