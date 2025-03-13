	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:05:22 by mapichec          #+#    #+#             */
/*   Updated: 2025/02/19 16:10:50 by mapichec         ###   ########.fr       */
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
		// modifies contacts in the phoneBook
		void add_cont(std::string nm, std::string num,
			std::string lst_nm, std::string nk_nm, std::string scrt, 
			int num_cont);

		// Shows the phonebook contacts
		void	display(int i);
		
		// displays the selected contact
		void	display_one();

	private:
		std::string name;
		std::string nickname;
		std::string last_name;
		std::string number;
		std::string secret;
		int cont_old;
};

class PhoneBook
{
	public:
		Contact contactArr[8];
		Contact *tmpContact;
		std::string tmp_name;
		std::string tmp_num;
		std::string tmp_lst;
		std::string tmp_nick;
		std::string tmp_secret;
		void	call_display();
};

#endif