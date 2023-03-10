/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:17:34 by nthimoni          #+#    #+#             */
/*   Updated: 2023/03/02 16:29:18 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP 

namespace ft 
{
	template <typename T1, typename T2>
		struct pair
		{
			typedef T1 first_type;
			typedef T2 second_type;
			T1 first;
			T2 second;

			pair() : first(), second() {}
			pair(const T1& a, const T2& b) : first(a), second(b) {}
			template <typename U1, typename U2>
				pair(const pair<U1, U2>& other) : first(other.first), second(other.second) {}
			pair& operator=(const pair& other)
			{
				first = other.first;
				second = other.second;
				return *this;
			}
			~pair() {}
		};
	
	template <typename T1, typename T2>
	pair<T1, T2> make_pair(T1 t, T2 u)
	{
		return (pair<T1, T2>(t , u));
	}

}

#endif 
