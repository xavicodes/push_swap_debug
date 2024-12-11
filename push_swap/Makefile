# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Directories
SRC_DIR = .
MOVEMENTS_DIR = movements
ALGORITMO_DIR = algoritmo
EXTRAS_DIR = extras

# Source files
SRC_FILES = $(SRC_DIR)/push_swap.c \
            $(MOVEMENTS_DIR)/movements.c \
            $(MOVEMENTS_DIR)/extras_movement.c \
            $(ALGORITMO_DIR)/algoritmo.c \
            $(ALGORITMO_DIR)/extras_algoritmo.c \
            $(EXTRAS_DIR)/error_handle.c \
            $(EXTRAS_DIR)/split.c \
            $(EXTRAS_DIR)/extras.c \
            $(EXTRAS_DIR)/stack_manipulation.c

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Output file
NAME = push_swap

# Rules
all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

# Generic rule for creating .o files from .c files
%.o: %.c include/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

