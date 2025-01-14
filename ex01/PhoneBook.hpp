/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:05:22 by mapichec          #+#    #+#             */
/*   Updated: 2025/01/12 18:42:21 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
# include <iostream>
# include <cstring>

class Contact
{
	public:
		Contact(){std::memset(this, 0, sizeof(*this));}
	// funzioni per modificare da phonebook
		void add_cont(std::string nm, std::string num,
			std::string lst_nm, std::string nk_nm, std::string scrt, 
			int num_cont)
		{
			this->name.replace(0, nm.length(), nm);
			this->number.replace(0, num.length(), num);
			this->last_name.replace(0, lst_nm.length(), lst_nm);
			this->nickname.replace(0, nk_nm.length(), nk_nm);
			this->secret.replace(0, scrt.length(), scrt);
			this->cont_old = num_cont;
		};
		
		//TODO funzione per il search con regole per la lista settata
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
		std::string tmp_name;
		std::string tmp_num;
		std::string tmp_lst;
		std::string tmp_nick;
		std::string tmp_secret;
		// funzioni per modificare dal main
};

#endif