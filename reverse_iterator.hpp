/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:38:49 by nthimoni          #+#    #+#             */
/*   Updated: 2023/02/22 20:16:51 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include <cstddef>
#include <iterator>
#include <iostream>

namespace ft
{
	template<class Iter>
		struct iterator_traits
		{
			typedef typename Iter::difference_type difference_type;
			typedef	typename Iter::value_type value_type;
			typedef typename Iter::pointer pointer;
			typedef typename Iter::reference reference;
			typedef typename Iter::iterator_category iterator_category;
		};
	template<class T>
		struct iterator_traits<T*>
		{
			typedef std::ptrdiff_t difference_type;
			typedef	T value_type;
			typedef T* pointer;
			typedef T& reference;
			typedef std::random_access_iterator_tag iterator_category;
		};
	template<class T>
		struct iterator_traits<const T*>
		{
			typedef std::ptrdiff_t difference_type;
			typedef	const T value_type;
			typedef const T* pointer;
			typedef const T& reference;
			typedef std::random_access_iterator_tag iterator_category;
		};

	template <typename T>
		class VectorIterator
		{
			public:
				typedef std::random_access_iterator_tag iterator_category;
				typedef T value_type;
				typedef std::ptrdiff_t difference_type;
				typedef T* pointer;
				typedef T& reference;
			private:
				pointer m_current;
			public:
				VectorIterator() : m_current(NULL) {}
				VectorIterator(const VectorIterator& ent) : m_current(ent.m_current) {}
				VectorIterator(pointer elem) : m_current(elem) {}
				VectorIterator& operator=(const VectorIterator& ent) { m_current = ent.m_current; }
				~VectorIterator();

				VectorIterator& operator++() { ++m_current; return *this; }
				VectorIterator& operator--() { --m_current; return *this; }
				VectorIterator operator++(int)
				{
					VectorIterator tmp(*this);
					++m_current;
					return tmp;
				}
				VectorIterator operator--(int)
				{
					VectorIterator tmp(*this);
					--m_current;
					return tmp;
				}
				VectorIterator& operator+(int a) { m_current += a; return *this; }
				VectorIterator& operator-(int a) { m_current -= a; return *this; }
				difference_type operator-(const VectorIterator& a) { return m_current - a.m_current; }
		};
	template <typename T>
		class reverse_iterator
		{
			public:
				typedef typename iterator_traits<T>::iterator_category iterator_category;
				typedef typename iterator_traits<T>::value_type value_type;
				typedef typename iterator_traits<T>::difference_type difference_type;
				typedef typename iterator_traits<T>::pointer pointer;
				typedef typename iterator_traits<T>::reference reference;
				typedef T iterator_type;
			private:
				T m_base;
			public:
				reverse_iterator(const T& ent) : m_base(ent) {}
				reverse_iterator(const reverse_iterator<T>& ent) : m_base(ent.m_base) {}
				reverse_iterator& operator=(const reverse_iterator& ent) { m_base = ent.m_base; return *this; }
				~reverse_iterator() {}

				reverse_iterator& operator++() { --m_base; return *this; }
				reverse_iterator& operator--() { ++m_base; return *this; }
				reverse_iterator<T> operator++(int)
				{
					return m_base--;
				}
				reverse_iterator<T> operator--(int)
				{
					return m_base++;
				}
				iterator_type base() const { return m_base; };
				reverse_iterator operator+(difference_type a) { return m_base - a; }
				reverse_iterator operator-(difference_type a) { return m_base + a; }
				difference_type operator-(const reverse_iterator& a) { return a.m_base - m_base; }
				bool operator!=(const reverse_iterator& i) const { return this->m_base != i.m_base; }
				bool operator==(const reverse_iterator& i) const { return this->m_base == i.m_base; }
				bool operator>=(const reverse_iterator& i) const { return this->m_base <= i.m_base; }
				bool operator<=(const reverse_iterator& i) const { return this->m_base >= i.m_base; }
				bool operator>(const reverse_iterator& i) const { return this->m_base < i.m_base; }
				bool operator<(const reverse_iterator& i) const { return this->m_base > i.m_base; }
				reference operator*() const { return *(m_base - 1); }
				pointer operator->() const { return &(*(m_base - 1)); }
				reference operator[](difference_type n) const { return *(m_base - 1 - n); };
		};
}
#endif 
