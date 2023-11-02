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
SRC := check_params.c\
	main.c\
	movement.c

# Setup obj and src files and obj folders
SRC := $(addprefix $(SRC_DIR)/,$(SRC))
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_FOLDER := $(sort $(dir $(OBJ)))

# Add -l, -L and -I flags
LIB_FLAG := $(addprefix -l,$(LIB))
LIB_PATH_FLAG := $(addprefix -L,$(LIB_PATH))
INCLUDE_PATH_FLAG := $(addprefix -I,$(INCLUDE_PATH)) -I$(INCLUDE_DIR) $(addprefix -I,$(sort $(dir $(SRC))))

all: $(NAME)

$(NAME): $(OBJ) $(LIB_PATH)
	$(CC) $(CFLAGS) $(INCLUDE_PATH_FLAG) $(LIB_PATH_FLAG) $(OBJ) $(LIB_FLAG) -o $@

$(LIB_PATH):
	@make -C $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_FOLDER)
	$(CC) $(CFLAGS) $(INCLUDE_PATH_FLAG) -c -o $@ $<

clean:
	@for i in $(LIB_PATH); do \
		echo "Cleaning $$i"; \
		make -C $$i fclean; \
	done
	@if [ -f $(OBJ_DIR) ]; then \
		echo "Deleted $(OBJ_DIR) folder"; \
	fi
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@if [ -f $(NAME) ]; then \
		echo "Deleted $(NAME) executable";\
	fi
	@$(RM) $(NAME)

re: fclean all

commit:
	git add --all
	date="$(shell date +"%a %b %_d %H:%M")"
	curr_branch="$(shell git branch | grep "\*" | cut -d ' ' -f2 )"
	read -p "Commit message: " MSG
	echo "[$$curr_branch] $$date - $$MSG"
	git commit -m "[$$curr_branch] $$date - $$MSG"
	git push

.PHONY: clean fclean all re $(LIB_PATH) commit
