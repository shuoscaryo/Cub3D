#modificable variables
NAME := libft.a

LIB := ar rcs
RM := rm -f
CC := gcc
CFLAGS := -Wall -Wextra -Werror

OBJ_DIR := obj
SRC_DIR := src
INCLUDE_DIR := include

SRC := ft_lstfree.c\
	ft_striteri.c\
	ft_array_cp.c\
	ft_msg_err.c\
	ft_calloc.c\
	ft_toupper.c\
	ft_strchr.c\
	ft_msg_perror.c\
	ft_split.c\
	ft_putstr_fd.c\
	ft_strmapi.c\
	ft_itoa.c\
	ft_lstfind.c\
	ft_lstadd_front.c\
	ft_memchr.c\
	ft_memmove.c\
	ft_lstnew.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_lstdelone.c\
	ft_substr.c\
	ft_lstget_val.c\
	ft_putnbr_fd.c\
	ft_memset.c\
	ft_strlcat.c\
	ft_putchar_fd.c\
	ft_strnstr.c\
	ft_strncmp.c\
	ft_strdup.c\
	ft_strlcpy.c\
	ft_lstadd_back.c\
	ft_lstget_index.c\
	ft_lstadd_back_content.c\
	ft_lstsize.c\
	ft_putendl_fd.c\
	ft_lstiter.c\
	ft_tolower.c\
	ft_strtrim.c\
	ft_strlen.c\
	ft_memcpy.c\
	ft_strcmp.c\
	ft_isprint.c\
	ft_strjoin.c\
	ft_lstpop.c\
	ft_strrchr.c\
	ft_memcmp.c\
	ft_atoi.c\
	ft_array_free.c\
	ft_isdigit.c\
	ft_bzero.c\
	ft_lstmap.c\
	ft_isalnum.c\
	ft_lstlast.c
#Here begin the rules
INCLUDE_PATH := $(addprefix -I, $(INCLUDE_DIR))
SRC := $(addprefix $(SRC_DIR)/, $(SRC))
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(LIB) $@ $(OBJ)

#compile the .o files and create the obj file if it doesn't exist
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE_PATH) -c -o $@ $<

#delete the object files and remove the obj folder
clean:
	@$(RM) -r $(OBJ_DIR)

#remove libft.a and the obj
fclean: clean
	@$(RM) $(NAME)

#removes everything and does make again
re: fclean all

.PHONY: clean fclean all re
