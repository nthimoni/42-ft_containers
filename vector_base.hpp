/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_base.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:04:09 by nthimoni          #+#    #+#             */
/*   Updated: 2023/02/24 01:51:22 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORE_BASE_HPP
# define VECTORE_BASE_HPP 

#include <memory>
#include "reverse_iterator.hpp"

namespace ft
{
	template <typename T>
		class vector_base
		{
			public:

			typedef std::allocator<T> allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef T* iterator;
			typedef const T* const_iterator;
			typedef typename allocator_type::size_type size_type; // See 23.1
			typedef typename allocator_type::difference_type difference_type;// See 23.1
			typedef T value_type;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

			vector_base() : m_alloc(), m_data(), m_size(), m_capacity() {}
			vector_base(size_type n) : m_alloc(), m_data(), m_size(), m_capacity()
			{
				if (n > 0)
					m_data = m_alloc.allocate(n);
				m_capacity = n;
			}
			~vector_base()
			{
				if (m_capacity)
					m_alloc.deallocate(m_data, m_capacity);
			}

			allocator_type m_alloc;
			pointer m_data;
			size_type m_size;
			size_type m_capacity;
		};

		template<typename T>
		void swap(vector_base<T>& lhs, vector_base<T>& rhs)
		{
			typename vector_base<T>::pointer tmp_data = rhs.m_data;
			typename vector_base<T>::size_type tmp_size = rhs.m_capacity;
			rhs.m_data = lhs.m_data;
			rhs.m_capacity = lhs.m_capacity;
			lhs.m_data = tmp_data;
			lhs.m_capacity = tmp_size;
			tmp_size = rhs.m_size;
			rhs.m_size = lhs.m_size;
			lhs.m_size = tmp_size;
		}
}

#endif 
