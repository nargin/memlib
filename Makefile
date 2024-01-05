CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = main
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

.PHONY: all clean

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)