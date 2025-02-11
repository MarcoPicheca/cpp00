/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:05:22 by mapichec          #+#    #+#             */
/*   Updated: 2025/02/11 19:51:13 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
# include <iostream>
# include <cstring>
# include <unistd.h>
# include <string.h>
# include <sstream>

class Contact
{
	public:
	// funzioni per modificare da phonebook
		void add_cont(std::string nm, std::string num,
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
			this->name.replace(0, nm.size(), nm);
			this->number.replace(0, num.size(), num);
			this->last_name.replace(0, lst_nm.size(), lst_nm);
			this->nickname.replace(0, nk_nm.size(), nk_nm);
			this->secret.replace(0, scrt.size(), scrt);
			this->cont_old = num_cont;
		};

		// Shows the phonebook contacts
		void	display(int i)
		{
			/**
			 * 
			 * //TODO
			 * 
			 * display ancora non del tutto funzionante
			 * ma ancora non si è cpaito come mai in alcuni
			 * casi faccia le colonne da 12 invece che da 13
			 * per cui: 
			 * - da capire i casi in cui lo fa e risolvere
			 * 
			 * ERRORE AL MOMENTO NON RIPRODUCIBILE
			 * 
			 *
			*/ 
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
		
		// displays the selected contact
		void	display_one(int i)
		{
			std::cout << "NAME: " << this->name << std::endl;
			std::cout << "PHONE NUMBER: " << this->number << std::endl;
			std::cout << "LAST NAME: " << this->last_name << std::endl;
			std::cout << "NICKNAME: " << this->nickname << std::endl;
			std::cout << "DARKEST SECRET: " << this->secret << std::endl;
		}

	private:
		std::string name;
		std::string nickname;
		std::string last_name;
		std::string number;
		std::string secret;
		int cont_old;
	/** 
	 * utile per visual
	 * void get_contact()
	 * {
	 * 	std::cout << this->name << std::endl;
	 * 	std::cout << this->number << std::endl;
	 * 	std::cout << this->last_name << std::endl;
	 * 	std::cout << this->nickname << std::endl;
	 * 	std::cout << this->secret << std::endl;
	 * 	std::cout << this->cont_old << std::endl;
	 * }
	 * 
	 * */ 
};

class PhoneBook
{
	public:
		Contact c_arr[8];
		Contact *tmp_c;
		std::string tmp_name;
		std::string tmp_num;
		std::string tmp_lst;
		std::string tmp_nick;
		std::string tmp_secret;
		void	call_display()
		{
			for (int i = 0; i < 8; i++)
			{
				tmp_c = c_arr + i;
				tmp_c->display(i);
			}
			
			int pos_ws = tmp_num.find_first_not_of(" \t");
			if (pos_ws)
				tmp_num.erase(0, pos_ws);
			while (tmp_num.find_first_of("12345678") == std::string::npos)
			{
				std::cout << "Select a contact (just one number beetween the ones in the Phone Book index): ";
				std::cin.ignore();
				std::getline(std::cin, tmp_num);
				if (tmp_num.find_first_not_of("12345678") || tmp_num.length() > 1)
					tmp_num.clear();
			}
			// TODO da aggiungere la parte di display
			std::cout << std::endl;
		}
};

#endif