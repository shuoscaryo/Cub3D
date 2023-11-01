NAME := cub3D

CC := gcc
CFLAGS := -Wall -Wextra -Werror -I . -L minilibx
RM := rm -f

SRC_DIR := src
INCLUDE_DIR := include
OBJ_DIR := obj

LIBFT_DIR := libft
LIBFT_NAME := libft.a

LIB := lmlx_Linux\
	Xext\
	X11

SRC := render/nacho.c\
	main.c

SRC := $(addprefix $(SRC_DIR)/,$(SRC))
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_FOLDER := $(sort $(dir $(OBJ)))
LIB_FLAG := $(addprefix -l,$(LIB))
INCLUDE_PATH := -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME)
	$(CC) $(CFLAGS)  $(INCLUDE_PATH) $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME) $(LIB_FLAG) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_FOLDER)
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c -o $@ $<

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
