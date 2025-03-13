#include "./PhoneBook.hpp"

void Contact::add_cont(std::string nm, std::string num,
		std::string lst_nm, std::string nk_nm, std::string scrt, 
		int num_cont)
{
	int	pos_ws = 0;
	pos_ws = nm.find_first_not_of(" \t");
	if (pos_ws)
		nm.erase(0, pos_ws);
	pos_ws = num.find_first_not_of(" \t");
	if (pos_ws)
		num.erase(0, pos_ws);
	pos_ws = lst_nm.find_first_not_of(" \t");
	if (pos_ws)
		lst_nm.erase(0, pos_ws);
	pos_ws = nk_nm.find_first_not_of(" \t");
	if (pos_ws)
		nk_nm.erase(0, pos_ws);
	pos_ws = scrt.find_first_not_of(" \t");
	if (pos_ws)
		scrt.erase(0, pos_ws);
	if (!this->name.empty())
		this->name.clear();
	if (!this->number.empty())
		this->number.clear();
	if (!this->last_name.empty())
		this->last_name.clear();
	if (!this->nickname.empty())
		this->nickname.clear();
	if (!this->secret.empty())
		this->secret.clear();
	this->name.replace(0, nm.size(), nm);	
	this->number.replace(0, num.size(), num);
	this->last_name.replace(0, lst_nm.size(), lst_nm);
	this->nickname.replace(0, nk_nm.size(), nk_nm);
	this->secret.replace(0, scrt.size(), scrt);
	this->cont_old = num_cont;
}

void	Contact::display_one()
{
	std::cout << "NAME: " << this->name << std::endl;
	std::cout << "PHONE NUMBER: " << this->number << std::endl;
	std::cout << "LAST NAME: " << this->last_name << std::endl;
	std::cout << "NICKNAME: " << this->nickname << std::endl;
	std::cout << "DARKEST SECRET: " << this->secret << std::endl;
}

void	Contact::display(int i)
{
	std::cout << i + 1 << " |";
	int	cont = 0;
	int	shift = 0;
	int	col = 1;
	while (col < 4)
	{
		if (cont == 0)
		{
			std::cout << ' ' << std::flush;
			cont++;
		}
		while (cont < 12)
		{
			if (col == 1)
			{
				if (shift < 10 && shift < (int)this->name.length())
					std::cout << this->name.at(shift++) << std::flush;
				else if (shift == 10)
				{
					std::cout << '.' << std::flush;
					shift = 0;
					break;
				}
				else if (shift == (int)this->name.length() && shift < 11)
				{
					while(shift < 11)
					{
						cont++;
						shift++;
						std::cout << ' ' << std::flush;
					}
					break;
				}
			}
			if (col == 2)
			{
				if (shift < 10 && shift < (int)this->last_name.length())
					std::cout << this->last_name.at(shift++) << std::flush;
				else if (shift == 10)
				{
					std::cout << '.' << std::flush;
					shift = 0;
					break;
				}
				else if (shift == (int)this->last_name.length() && shift < 11)
				{
					while(shift < 11)
					{
						cont++;
						shift++;
						std::cout << ' ' << std::flush;
					}
					break;														
				}
			}
			if (col == 3)
			{
				if (shift < 10 && shift < (int)this->nickname.length())
					std::cout << this->nickname.at(shift++) << std::flush;
				else if (shift == 10)
				{
					std::cout << '.' << std::flush;
					shift = 0;
					break;
				}
				else if (shift == (int)this->nickname.length() && shift < 11)
				{
					while(shift < 11)
					{
						cont++;
						shift++;
						std::cout << ' ' << std::flush;
					}
					break;														
				}
			}
			cont++;
		}
		std::cout << " |" << std::flush;
		cont = 0;
		shift = 0;
		col++;
	}
	std::cout << std::endl;
}

