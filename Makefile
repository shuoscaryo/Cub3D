NAME := cub3D

CC := cc
RM := rm -f
CFLAGS := -Wall -Wextra -Werror

# proyect directories
SRC_DIR := src
INCLUDE_DIR := include
OBJ_DIR := obj
LIB_DIR := lib

# Add math library
LIB += m

#add libft library
LIB += ft
LIB_PATH += $(LIB_DIR)/libft
INCLUDE_PATH += $(LIB_DIR)/libft/include
LOCAL_MAKE += $(LIB_DIR)/libft/libft.a

# Add mlx library differently depending on OS
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIB += mlx_Linux X11 Xext
    LIB_PATH += $(LIB_DIR)/mlx_linux
	INCLUDE_PATH += $(LIB_DIR)/mlx_linux
	CFLAGS += -fsanitize=leak
	LOCAL_MAKE += $(LIB_DIR)/mlx_linux/libmlx_Linux.a
else ifeq ($(UNAME_S),Darwin)
	LIB += mlx
    LIB_PATH += $(LIB_DIR)/mlx_mac
	INCLUDE_PATH += $(LIB_DIR)/mlx_mac
	FRAMEWORK += -framework OpenGL -framework AppKit
	LOCAL_MAKE += $(LIB_DIR)/mlx_mac/libmlx.a
endif

# Source files without SRC_DIR
SRC := game_exit.c\
	gnl/get_next_line.c\
	gnl/get_next_line_utils.c\
	main.c\
	manage_map/check_map.c\
	manage_map/get_map.c\
	manage_map/get_textures.c\
	manage_map/map_utils.c\
	manage_map/read_map.c\
	movement.c\
	pruebas/2d.c\
	pruebas/fps.c\
	t_img/img_cmp.c\
	t_img/img_free.c\
	t_img/img_get_pixel.c\
	t_img/img_new.c\
	t_img/img_new2.c\
	t_img/img_pixel_put.c\
	t_keys/key_cmp.c\
	t_keys/keys_free.c\
	t_keys/keys_get_status.c\
	t_keys/keys_init.c\
	t_keys/keys_update.c\
	t_player/player_init.c\
	t_player/player_move.c\
	t_player/player_on_key.c\
	t_textures/textures_add_texture.c\
	t_textures/textures_free.c\
	t_textures/textures_get_texture.c\
	t_textures/textures_init.c\
	t_walls/wall_cmp.c\
	t_walls/wall_init.c\
	t_walls/walls_add_wall.c\
	t_walls/walls_free.c\
	t_walls/walls_get_hash.c\
	t_walls/walls_get_wall.c\
	t_walls/walls_init.c

# Setup obj and src files and obj folders
SRC := $(addprefix $(SRC_DIR)/,$(SRC))
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_FOLDER := $(sort $(dir $(OBJ)))

# Add -l, -L and -I flags
LIB_FLAG := $(addprefix -l,$(LIB))
LIB_PATH_FLAG := $(addprefix -L,$(LIB_PATH))
INCLUDE_PATH_FLAG := $(addprefix -I,$(INCLUDE_PATH)) -I$(INCLUDE_DIR) $(addprefix -I,$(sort $(dir $(SRC))))

all: $(NAME)

$(NAME): $(OBJ) $(LOCAL_MAKE)
	$(CC) $(CFLAGS) $(INCLUDE_PATH_FLAG) $(LIB_PATH_FLAG) $(OBJ) $(LIB_FLAG) $(FRAMEWORK) -o $@

%.a:
	@make -C $(dir $@)

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
	git status -s
	@$(eval date=$(shell date +"%Y-%m-%d-%H:%M"))
	@$(eval curr_branch=$(shell git branch | grep "\*" | cut -d ' ' -f2 ))
	@$(eval MSG=$(shell read -p "Commit message: " MSG; echo $$MSG))
	@git commit -m "[$(curr_branch)]<$(date)> $(MSG)"; true
	@git push origin $(curr_branch)

.PHONY: clean fclean all re $(LIB_PATH) commit
