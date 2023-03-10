/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:59:55 by nthimoni          #+#    #+#             */
/*   Updated: 2023/03/03 22:02:51 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP 

#include "pair.hpp"
#include <cstdlib>
#include <functional>
#include <memory>

namespace ft
{
	template<typename Key, typename T, typename Compare = std::less<Key>>
	class map
	{
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const Key, T> value_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef std::allocator<value_type> allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		//typedef iterator
		//typedef const_iterator
		//typedef reverse_iterator
		//typedef const_reverse_iterator
	};
};

#endif 
