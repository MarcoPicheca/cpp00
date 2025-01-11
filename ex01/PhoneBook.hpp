/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:05:22 by mapichec          #+#    #+#             */
/*   Updated: 2025/01/11 20:06:08 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

class Contact
{
	public:
		int	cont_num;
		int cont_old;
};

class PhoneBook
{
	public:
		Contact arr[8];
};

#endif