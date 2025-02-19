NAME = megaphone

CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

SRC = megaphone.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm $(NAME)

fclean: clean

re: clean all

.PHONY: re clean all fclean