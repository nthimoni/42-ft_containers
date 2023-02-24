/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cla.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:35:05 by nthimoni          #+#    #+#             */
/*   Updated: 2023/02/24 01:00:03 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

int main()
{
	std::vector<int> a(15, 15);
	std::cout << (&a) << std::endl;
	std::cout << std::addressof(a) << std::endl;
	std::cout << (&a.front()) << std::endl;
	a = a;
	std::cout << ((std::vector<int>::size_type)std::distance(a.end(), a.begin())) << std::endl;
	std::cout << a.max_size() << std::endl;
	std::vector<int> b(a.end(), a.begin());
}
