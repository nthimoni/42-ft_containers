/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:15:35 by nthimoni          #+#    #+#             */
/*   Updated: 2023/02/20 17:30:45 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "vector"


#define NAMESPACE ft

int main()
{
	std::cout << "\n########## INSERT ##########\n\n";
	NAMESPACE::vector<int> x;

	x.push_back(1);
	x.push_back(2);
	x.push_back(3);
	x.push_back(4);
	x.push_back(5);
	x.erase(x.begin());
	x.erase(x.begin());
	x.erase(x.begin());
	std::cout << "cap = " << x.capacity() << ", size = " << x.size() << std::endl;
	//x.insert(x.begin(), 1lu, 9);
	x.insert(x.begin(), 9);
}
