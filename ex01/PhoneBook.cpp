#include "./PhoneBook.hpp"

void PhoneBook::call_display()
{
	for (int i = 0; i < 8; i++)
	{
		tmpContact = contactArr + i;
		tmpContact->display(i);
	}
	int pos_ws = tmp_num.find_first_not_of(" \t");
	if (pos_ws)
		tmp_num.erase(0, pos_ws);
	while (tmp_num.find_first_of("012345678") == std::string::npos)
	{
		std::cout << "Select a contact (just one number beetween the ones in the Phone Book index): ";
		std::getline(std::cin, tmp_num);
		if (tmp_num.find_first_not_of("012345678") != std::string::npos || tmp_num.length() > 1)
			tmp_num.clear();
	}
	if (tmp_num.compare("0") == 0)
	{
		tmp_num.clear();
		return ;
	}
	else if (tmp_num.compare("1") == 0)
	{
		contactArr[0].display_one();
		tmp_num.clear();
		return ;
	}
	else if (tmp_num.compare("2") == 0)
	{
		contactArr[1].display_one();
		tmp_num.clear();
		return ;
	}
	else if (tmp_num.compare("3") == 0)
	{
		contactArr[2].display_one();
		tmp_num.clear();
		return ;
	}
	else if (tmp_num.compare("4") == 0)
	{
		contactArr[3].display_one();
		tmp_num.clear();
		return ;
	}
	else if (tmp_num.compare("5") == 0)
	{
		contactArr[4].display_one();
		tmp_num.clear();
		return ;
	}
	if (tmp_num.compare("6") == 0)
	{
		contactArr[5].display_one();
		tmp_num.clear();
		return ;
	}
	if (tmp_num.compare("7") == 0)
	{
		contactArr[6].display_one();
		tmp_num.clear();
		return ;
	}
	if (tmp_num.compare("8") == 0)
	{
		contactArr[7].display_one();
		tmp_num.clear();
		return ;
	}
	std::cout << std::endl;
}

int main()
{
	PhoneBook phoneBook;
	std::string command;

	int i = 0;
	while (1)
	{
		if (i == 8)
			i = 0;
		std::cout << "Write a command between ADD, SEARCH and EXIT (UPPERCASE REQUIRED): \0";
		std::cin >> command;

		std::cin.ignore();
		if (command.compare("ADD") == 0)
		{
			while (phoneBook.tmp_name.empty())
			{
				std::cout << "Write name: ";
				std::getline(std::cin, phoneBook.tmp_name);
				if (phoneBook.tmp_name.empty()
					|| phoneBook.tmp_name.find_first_not_of(" \t") == std::string::npos)
				{
					phoneBook.tmp_name.clear();
					std::cout << "CONTACTS CAN'T HAVE EMPTY FIELDS" << std::endl;
				}
			}
			while (phoneBook.tmp_num.empty())
			{
				std::cout << "Write number: ";
				std::getline(std::cin, phoneBook.tmp_num);
				if (phoneBook.tmp_num.empty()
					|| phoneBook.tmp_num.find_first_not_of(" \t") == std::string::npos)
				{
					phoneBook.tmp_num.clear();
					std::cout << "CONTACTS CAN'T HAVE EMPTY FIELDS" << std::endl;
				}
			}
			while (phoneBook.tmp_lst.empty())
			{
				std::cout << "Write last name: ";
				std::getline(std::cin, phoneBook.tmp_lst);
				if (phoneBook.tmp_lst.empty()
					|| phoneBook.tmp_lst.find_first_not_of(" \t") == std::string::npos)
				{
					phoneBook.tmp_lst.clear();
					std::cout << "CONTACTS CAN'T HAVE EMPTY FIELDS" << std::endl;
				}
			}
			while (phoneBook.tmp_nick.empty())
			{
				std::cout << "Write nickname: ";
				std::getline(std::cin, phoneBook.tmp_nick);
				if (phoneBook.tmp_nick.empty()
					|| phoneBook.tmp_nick.find_first_not_of(" \t") == std::string::npos)
				{
					phoneBook.tmp_nick.clear();
					std::cout << "CONTACTS CAN'T HAVE EMPTY FIELDS" << std::endl;
				}
			}
			while (phoneBook.tmp_secret.empty())
			{
				std::cout << "Write darkest secret: ";
				std::getline(std::cin, phoneBook.tmp_secret);
				if (phoneBook.tmp_secret.empty()
					|| phoneBook.tmp_secret.find_first_not_of(" \t") == std::string::npos)
				{
					phoneBook.tmp_secret.clear();
					std::cout << "CONTACTS CAN'T HAVE EMPTY FIELDS" << std::endl;
				}
			}
			phoneBook.contactArr[i].add_cont(phoneBook.tmp_name, phoneBook.tmp_num,
				phoneBook.tmp_lst, phoneBook.tmp_nick, phoneBook.tmp_secret, i);
			phoneBook.tmp_name.clear();
			phoneBook.tmp_num.clear();
			phoneBook.tmp_lst.clear();
			phoneBook.tmp_nick.clear();
			phoneBook.tmp_secret.clear();
			i++;
		}
		else if (command.compare("SEARCH") == 0)
			phoneBook.call_display();
		else if (command.compare("EXIT") == 0)
			return (0);
		else if (command.empty() || command.compare("\n"))
			std::cout << "READ AGAIN" << std::endl;
	}
}
