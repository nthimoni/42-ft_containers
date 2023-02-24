/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:05:24 by nthimoni          #+#    #+#             */
/*   Updated: 2023/02/24 02:02:59 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP 

template <typename T>
class vector;

namespace ft
{
	template <typename InputIt1, typename InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		for (; first1 != last1; first1++, first2++)
			if (!(*first1 == *first2))
				return false;
		return true;
	}

	template <typename InputIt1, typename InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		for (; first1 != last1 && first2 != last2; first1++, first2++)
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
		}
		return first1 == last1 && first2 != last2;
	}
}

#endif 
