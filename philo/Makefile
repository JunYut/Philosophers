CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic -g

SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.c) main.c
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(OBJ)
	$(CC) $(CFLAGS) -o philo $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

fsan:
	$(CC) $(CFLAGS) -fsanitize=address -o philo $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f philo

re: fclean all

.PHONY: all clean fclean re
