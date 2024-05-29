# Compiler & Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = .

# Files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBPHILO = libphilo.a
PHILO = philo

# Rules & Recipes
all: $(PHILO)

$(PHILO): $(LIBPHILO)
	$(CC) $(CFLAGS) -o $@ main.c -L. -lphilo -lpthread

$(LIBPHILO): $(OBJ)
	ar rcs $@ $^
	ranlib $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBPHILO) $(PHILO)

re: fclean all

.PHONY: all clean fclean re