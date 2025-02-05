#include "./PhoneBook.hpp"


int main()
{
	PhoneBook phonebook;
	std::string command;

	int i = 0;
	// phonebook.c_arr[i].get_contact();
	while (1)
	{
		if (i == 8)
			i = 0;
		std::cout << "Write a command between ADD, SEARCH and EXIT (UPPERCASE REQUIRED): ";
		std::cin >> command;

		if (command.compare("ADD") == 0)
		{
			std::cout << "Write name: ";
			std::cin >> phonebook.tmp_name;
			std::cout << "Write phone number: ";
			std::cin >> phonebook.tmp_num;
			std::cout << "Write last name: ";
			std::cin >> phonebook.tmp_lst;
			std::cout << "Write nickname: ";
			std::cin >> phonebook.tmp_nick;
			std::cout << "Write his/her darkest secret: ";
			std::cin >> phonebook.tmp_secret;
			phonebook.c_arr[i].add_cont(phonebook.tmp_name, phonebook.tmp_num,
				phonebook.tmp_lst, phonebook.tmp_nick, phonebook.tmp_secret, i);
			i++;
		}
		else if (command.compare("SEARCH") == 0)
		{
			phonebook.call_display();
		}
		else if (command.compare("EXIT") == 0)
			exit(0);
		else
			std::cout << "READ AGAIN" << std::endl;
	}
}
