# Compiler & Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

# Directories
SRCDIR = src
OBJDIR = obj

# Files
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
HEADERS = $(wildcard *.h)
LIBPHILO = libphilo.a
MAIN = main

# Rules & Recipes
all: $(MAIN)

$(MAIN): main.c $(LIBPHILO)
	$(CC) $(CFLAGS) -o $@ main.c -L. -lphilo -lpthread

$(LIBPHILO): $(OBJ)
	ar rcs $(LIBPHILO) $(OBJ)
	ranlib $(LIBPHILO)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBPHILO) $(MAIN)

re: fclean all

.PHONY: all clean fclean re
