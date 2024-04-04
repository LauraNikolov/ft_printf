NAME = libftprintf.a

SRC_DIR = src
FILES = ft_parse.c \
    ft_printchar.c \
    ft_printdeci.c \
    ft_printf.c \
    ft_printhexalow.c \
    ft_printhexaupp.c \
    ft_printstr.c \
    ft_printint.c \
    ft_printunsignedeci.c \
    ft_ptrisnull.c \
    ft_putchar.c

ARRC = ar rc
COMPIL = cc

FLAGS = -Wall -Wextra -Werror

OBJS = $(addprefix $(SRC_DIR)/, $(FILES:.c=.o))

GREEN = \033[0;32m
NC = \033[0m

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(COMPIL) $(FLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled $<$(NC)"

$(NAME): $(OBJS)
	$(ARRC) $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) has been created successfully$(NC)"

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
