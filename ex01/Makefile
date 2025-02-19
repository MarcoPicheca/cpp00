NAME = phonebook

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

CC = c++

SRC = PhoneBook.cpp Contact.cpp

all: $(NAME)

$(NAME): $(SRC)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@echo "Cleaning..."
	@rm $(NAME)

fclean: clean

re: clean all

.PHONY: re clean all fclean