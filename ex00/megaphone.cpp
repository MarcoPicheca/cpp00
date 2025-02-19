/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:33:09 by mapichec          #+#    #+#             */
/*   Updated: 2025/02/19 15:21:38 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int	i = 1;
	std::string arg;
	unsigned long j = 0;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (i < argc && argv[i])
	{
		arg = (std::string)argv[i];
		j = 0;
		while (j < arg.length())
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				argv[i][j] = std::toupper(argv[i][j]);
			j++;
		}
		i++;
	}    
	for (i = 1; i < argc - 1; ++i)
        std::cout << argv[i] << ' ';
	while (i < argc)
        std::cout << argv[i++];
	std::cout << std::endl;
    return 0;
}