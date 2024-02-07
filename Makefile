NAME = pipex

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -fr

OBJS_DIR		= obj/
SRCS_DIR		= srcs/

LIBFT_PATH		= lib/libft/
LIBFT_LIB		= $(LIBFT_PATH)libft.a

FT_PRINTF_PATH 	= lib/ft_printf/
FT_PRINTF_LIB	= $(FT_PRINTF_PATH)libftprintf.a

SOURCES			= main.c \
				input_check.c \
				error_msg.c \
				childs.c \

OBJECTS			= $(addprefix $(OBJS_DIR), $(SOURCES:.c=.o))


$(OBJS_DIR)%.o : $(SRCS_DIR)%.c pipex.h Makefile
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo Compiling $< ...

all: subsystems print $(OBJS_DIR) $(NAME)

print:
	@echo "\033[1;34mPipex:\033[0m"

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(FT_PRINTF_LIB) $(LIBFT_LIB) -o $(NAME)
	@echo pipex "\033[0;32mCompiled\033[0m"

$(OBJS_DIR):
	-@mkdir -p $(OBJS_DIR)

subsystems:
	@echo "\033[1;34mLibft:\033[0m"
	@make -C $(LIBFT_PATH) all --no-print-directory
	@echo "\n\033[1;34mft_printf:\033[0m"
	@make -C $(FT_PRINTF_PATH) all --no-print-directory
	@echo ""

clean:
	@echo "\033[1;34mLibft:\033[0m"
	@make -C $(LIBFT_PATH) clean --no-print-directory
	@echo "\n\033[1;34mft_printf:\033[0m"
	@make -C $(FT_PRINTF_PATH) clean --no-print-directory
	@echo ""
	@$(RM) $(OBJS_DIR)
	@echo "\033[1;34mPipex:\033[0m"
	@echo Deleting objects

fclean:
	@echo "\033[1;34mLibft:\033[0m"
	@make -C $(LIBFT_PATH) fclean --no-print-directory
	@echo "\n\033[1;34mft_printf:\033[0m"
	@make -C $(FT_PRINTF_PATH) fclean --no-print-directory
	@echo ""
	@$(RM) $(OBJS_DIR)
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "\033[1;34mPipex:\033[0m"
	@echo Deleting all

re: fclean all

.PHONY: all clean fclean re