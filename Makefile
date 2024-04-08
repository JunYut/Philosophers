# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g

# Sources
SRCS = main.c

# Targets
MAIN = main

all: $(MAIN)
	./$<

$(MAIN): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(MAIN) -lpthread

clean:
	rm -rf $(MAIN)
