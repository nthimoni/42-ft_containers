/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pairtest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:54:53 by nthimoni          #+#    #+#             */
/*   Updated: 2023/03/02 17:06:46 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.hpp"
#include <string>
#include <iostream>

template <typename T>
void printPair(const T& toPrint)
{
	std::cout << toPrint.first << " - " << toPrint.second << std::endl;
}

int main()
{
	ft::pair<int, std::string> a;
	printPair(a);
	ft::pair<int, std::string> a2(5, "coucou");
	printPair(a2);
	ft::pair<int, std::string> a3(a2);
	printPair(a3);
	a = a2;
	printPair(a3);
	ft::pair<int, std::string> yes = ft::make_pair(5.556, "coucou");
	printPair(a3);
}
