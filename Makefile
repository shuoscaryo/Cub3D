NAME := cub3D

CC := cc
RM := rm -f
CFLAGS := -Wall -Wextra -Werror

# proyect directories
SRC_DIR := src
INCLUDE_DIR := include
OBJ_DIR := obj
LIB_DIR := lib

#add libft library
LIB += ft
LIB_PATH += $(LIB_DIR)/libft
INCLUDE_PATH += $(LIB_DIR)/libft/include

# Add mlx library differently depending on OS
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIB += mlx_Linux X11 Xext
    LIB_PATH += $(LIB_DIR)/mlx_linux
	INCLUDE_PATH += $(LIB_DIR)/mlx_linux
else ifeq ($(UNAME_S),Darwin)
	LIB += mlx
    LIB_PATH += $(LIB_DIR)/mlx_mac
	INCLUDE_PATH += $(LIB_DIR)/mlx_mac
	CFLAGS += -framework OpenGL -framework AppKit
endif

# Source files without SRC_DIR
SRC := render/nacho.c\
	movement.c\
	main.c\
	check_params.c

# Setup obj and src files and obj folders
SRC := $(addprefix $(SRC_DIR)/,$(SRC))
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_FOLDER := $(sort $(dir $(OBJ)))

# Add -l, -L and -I flags
LIB := $(addprefix -l,$(LIB))
LIB_PATH := $(addprefix -L,$(LIB_PATH))
INCLUDE_PATH := $(addprefix -I,$(INCLUDE_PATH)) -I$(INCLUDE_DIR) $(addprefix -I,$(sort $(dir $(SRC))))

all: $(info $(INCLUDE_PATH)) $(NAME)

$(NAME): $(OBJ) $(LIB_PATH)
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(LIB_PATH) $(LIB) $(OBJ) -o $@

$(LIB_PATH):
	@make -C $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_FOLDER)
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c -o $@ $<

clean:
	@$(RM) -r $(OBJ_DIR)
	@make -C $(LIBFT_DIR) fclean
	@echo "Deleted obj files"
	@echo "Deleted $(LIBFT_NAME)"

fclean: clean
	@$(RM) $(NAME)
	@echo "Deleted $(NAME) executable"
	
re: fclean all

.PHONY: clean fclean all re $(LIB_PATH)
