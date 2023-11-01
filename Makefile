NAME := minishell

CC := gcc
STANDARD_FLAGS := -Wall -Wextra -Werror -I . -L minilibx -lmlx_Linux -lXext -lX11
RM := rm -f

SRC_DIR := src
INCLUDE_DIR := include
OBJ_DIR := obj

LIBFT_DIR := libft
LIBFT_NAME := libft.a

LIB := readline

SRC_FILES := main.c

SRC := $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_FOLDER := $(sort $(dir $(OBJ)))
LIB_FLAG := $(addprefix -l,$(LIB))
INCLUDE_PATH := -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME)
	$(CC) $(STANDARD_FLAGS)  $(INCLUDE_PATH) $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME) $(LIB_FLAG) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_FOLDER)
	$(CC) $(STANDARD_FLAGS) $(INCLUDE_PATH) -c -o $@ $<

$(LIBFT_DIR)/$(LIBFT_NAME):
	@make -C $(LIBFT_DIR) all

clean:
	@$(RM) -r $(OBJ_DIR)
	@make -C $(LIBFT_DIR) fclean
	@echo "Deleted obj files"
	@echo "Deleted $(LIBFT_NAME)"

fclean: clean
	@$(RM) $(NAME)
	@echo "Deleted $(NAME) executable"
	
re: fclean all

.PHONY: clean fclean all re