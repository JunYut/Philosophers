CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic -g

SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INC = -I.
LIB = -lpthread

all: $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJ) main.c -o philo

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

fsan:
	$(CC) $(CFLAGS) $(INC) $(LIB) -fsanitize=address main.c -o philo $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f philo

re: fclean all

.PHONY: all clean fclean re
