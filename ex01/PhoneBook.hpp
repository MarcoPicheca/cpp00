/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:05:22 by mapichec          #+#    #+#             */
/*   Updated: 2025/02/05 11:13:41 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
# include <iostream>
# include <cstring>

class Contact
{
	public:
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
		void	display(int i)
		{
			/**
			 * da capire se esiste una maniera per troncare
			 * gli argomenti mandati a cout senza allocare
			 * e senza dover scorrere carattere per carattere.
			 * 
			 * Abbiamo problemi con l'allineamento, per cui
			 * pensavamo di creare un limite max (12 chars) di char presenti
			 * in una colonna con una minimo di spaziatura per
			 * rendere più friendly le visual.
			 * 
			 * ADD funzione e sostituisce i vari contatti
			 * quando raggiunge il limite di otto.
			 *
			*/ 
			std::cout << i + 1 << " | ";
			if (this->name.length() > 10)
			{
				int i = 0;
				std::cout.
			}
			else
				std::cout << this->name << " | ";
			std::cout << this->last_name << " | ";
			std::cout << this->nickname << " | " << std::endl;
		}
		
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
			std::cout << std::endl;
		}
		// funzioni per modificare dal main
};

#endif