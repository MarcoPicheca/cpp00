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
		std::cout << "Write a command between ADD, SEARCH and EXIT (UPPERCASE REQUIRED): \0";
		std::cin >> command;

		std::cin.ignore();
		if (command.compare("ADD") == 0)
		{
			while (phonebook.tmp_name.empty())
			{
				std::cout << "Write name: ";
				std::getline(std::cin, phonebook.tmp_name);
				if (phonebook.tmp_name.empty()
					|| phonebook.tmp_name.find_first_not_of(" \t") == std::string::npos)
				{
					phonebook.tmp_name.clear();
					std::cout << "CONTACTS CAN'T HAVE EMPTY FIELDS" << std::endl;
				}
			}
			while (phonebook.tmp_num.empty())
			{
				std::cout << "Write number: ";
				std::getline(std::cin, phonebook.tmp_num);
				if (phonebook.tmp_num.empty()
					|| phonebook.tmp_num.find_first_not_of(" \t") == std::string::npos)
				{
					phonebook.tmp_num.clear();
					std::cout << "CONTACTS CAN'T HAVE EMPTY FIELDS" << std::endl;
				}
			}
			while (phonebook.tmp_lst.empty())
			{
				std::cout << "Write last name: ";
				std::getline(std::cin, phonebook.tmp_lst);
				if (phonebook.tmp_lst.empty()
					|| phonebook.tmp_lst.find_first_not_of(" \t") == std::string::npos)
				{
					phonebook.tmp_lst.clear();
					std::cout << "CONTACTS CAN'T HAVE EMPTY FIELDS" << std::endl;
				}
			}
			while (phonebook.tmp_nick.empty())
			{
				std::cout << "Write nickname: ";
				std::getline(std::cin, phonebook.tmp_nick);
				if (phonebook.tmp_nick.empty()
					|| phonebook.tmp_nick.find_first_not_of(" \t") == std::string::npos)
				{
					phonebook.tmp_nick.clear();
					std::cout << "CONTACTS CAN'T HAVE EMPTY FIELDS" << std::endl;
				}
			}
			while (phonebook.tmp_secret.empty())
			{
				std::cout << "Write darkest secret: ";
				std::getline(std::cin, phonebook.tmp_secret);
				if (phonebook.tmp_secret.empty()
					|| phonebook.tmp_secret.find_first_not_of(" \t") == std::string::npos)
				{
					phonebook.tmp_secret.clear();
					std::cout << "CONTACTS CAN'T HAVE EMPTY FIELDS" << std::endl;
				}
			}
			phonebook.c_arr[i].add_cont(phonebook.tmp_name, phonebook.tmp_num,
				phonebook.tmp_lst, phonebook.tmp_nick, phonebook.tmp_secret, i);
			phonebook.tmp_name.clear();
			phonebook.tmp_num.clear();
			phonebook.tmp_lst.clear();
			phonebook.tmp_nick.clear();
			phonebook.tmp_secret.clear();
			i++;
		}
		else if (command.compare("SEARCH") == 0)
		{
			phonebook.call_display();
		}
		else if (command.compare("EXIT") == 0)
			exit(0);
		else if (command.empty() || command.compare("\n"))
			std::cout << "READ AGAIN" << std::endl;
	}
}
