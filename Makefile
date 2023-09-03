NAME := libftprintf.a
LIB := ar -rcs
CC := gcc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

SRC_DIR := src
OBJ_DIR := obj
LIBFT_DIR := libft
LIBFT := libft.a
INCLUDE_DIR := include $(LIBFT_DIR)/include

SRC_FILES := ft_print_char.c\
	ft_print_hex.c\
	ft_print_int.c\
	ft_print_percentage.c\
	ft_print_ptr.c\
	ft_print_str.c\
	ft_print_uint.c\
	ft_printf.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
INCLUDE_PATH := $(addprefix -I, $(INCLUDE_DIR))
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT)
	@cp $(LIBFT_DIR)/$(LIBFT) .
	@mv $(LIBFT) $(NAME)
	@$(LIB) $@ $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE_PATH) -c -o $@ $<

$(LIBFT_DIR)/$(LIBFT):
	@make -C $(LIBFT_DIR) all

clean:
	@$(RM) -r $(OBJ_DIR)
	@make -C $(LIBFT_DIR) fclean

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re