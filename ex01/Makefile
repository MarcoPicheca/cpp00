NAME = phonebook

CFLAGS = -Wall -Wextra -Werror -g

CC = c++

SRC = PhoneBook.cpp

all: $(NAME)

$(NAME): $(SRC)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@echo "Cleaning..."
	@rm $(NAME)

re: clean all

.PHONY: re clean all