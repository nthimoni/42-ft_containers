/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:18:47 by nthimoni          #+#    #+#             */
/*   Updated: 2023/02/24 02:17:15 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iostream>
# include <exception>
# include <stdexcept>
# include "reverse_iterator.hpp"
# include "algorithm.hpp"
# include "vector_base.hpp"

namespace ft
{
	template <class T>
		class vector : protected vector_base<T> {
			public:
				// types:
				typedef typename vector_base<T>::allocator_type allocator_type;
				typedef typename vector_base<T>::reference reference;
				typedef typename vector_base<T>::const_reference const_reference;
				typedef typename vector_base<T>::iterator iterator;
				typedef typename vector_base<T>::const_iterator const_iterator;
				typedef typename vector_base<T>::size_type size_type;
				typedef typename vector_base<T>::difference_type difference_type;// See 23.1
				typedef typename vector_base<T>::value_type value_type;// See 23.1
				typedef typename vector_base<T>::pointer pointer;// See 23.1
				typedef typename vector_base<T>::const_pointer const_pointer;// See 23.1
				typedef typename vector_base<T>::reverse_iterator reverse_iterator;// See 23.1
				typedef typename vector_base<T>::const_reverse_iterator const_reverse_iterator;// See 23.1

				using vector_base<T>::m_size;
				using vector_base<T>::m_capacity;
				using vector_base<T>::m_data;
				using vector_base<T>::m_alloc;

				// 23.2.4.1 construct/copy/destroy:
				explicit vector() : vector_base<T>() {}

				explicit vector(size_type n, const T& value = T()) : vector_base<T>(n)
				{
					std::uninitialized_fill(m_data, m_data + n, value);
					m_size = n;
				}

				template <class InputIterator>
					vector(InputIterator first, InputIterator last) : vector_base<T>(std::distance(first, last))
					{
						std::uninitialized_copy(first, last, m_data);
						m_size = m_capacity;
					}

				vector(const vector<T>& x) : vector_base<T>(x.size())
				{
						std::uninitialized_copy(x.begin(), x.end(), m_data);
						m_size = m_capacity;
				}

				~vector()
				{
					this->destroy_elements(this->begin(), this->end());
				}

				vector<T>& operator=(const vector<T>& x)
				{
					if (this == &x)
						return *this;
					if (m_capacity < x.m_size)
					{
						vector tmp(x);
						this->swap(tmp);
					}
					else
					{
						difference_type toCopy = m_size < x.size() ? m_size : x.size();
						std::copy(x.begin(), x.begin() + toCopy, m_data);
						this->destroy_elements(this->begin() + toCopy, this->end());
						std::uninitialized_copy(x.begin() + toCopy, x.end(), m_data + toCopy);
						m_size = x.size();
					}
					return *this;
				}

				template <class InputIterator>
					void assign(InputIterator first, InputIterator last)
					{
						difference_type len = std::distance(first, last);
						if (static_cast<difference_type>(m_capacity) < len)
						{
							vector<T> tmp(first, last);
							ft::swap(*this, tmp);
						}
						else
						{
							size_type toCopy = static_cast<difference_type>(m_size) > len ? len : m_size;
							std::copy(first, first + toCopy, m_data);
							std::uninitialized_copy(first + toCopy, last, m_data + toCopy);
							this->destroy_elements(m_data + toCopy, this->end());
							m_size = len;
						}
					}
				void assign(size_type count, const T& u)
				{
						if (m_capacity < count)
						{
							vector<T> tmp(count, u);
							ft::swap(*this, tmp);
						}
						else
						{
							size_type toCopy = m_size > count ? count : m_size;
							std::fill_n(m_data, toCopy, u);
							std::uninitialized_fill_n(m_data + toCopy, count - toCopy, u);
							this->destroy_elements(m_data + toCopy, this->end());
							m_size = count;
						}
				}
				allocator_type get_allocator() const { return m_alloc; };

				// iterators:
				iterator begin() { return m_data; }
				const_iterator begin() const { return m_data; }
				iterator end() { return m_data + m_size; }
				const_iterator end() const { return m_data + m_size; }
				reverse_iterator rbegin() { return m_data + m_size; };
				const_reverse_iterator rbegin() const { return m_data + m_size; };
				reverse_iterator rend() { return m_data; };
				const_reverse_iterator rend() const { return m_data; };

				// 23.2.4.2 capacity:
				size_type size() const { return m_size; }
				size_type max_size() const { return m_alloc.max_size(); }
				void resize(size_type sz, T c = T())
				{
					// HEEEERRREEEEE
					if (sz > m_capacity)
					{
						vector_base<T> tmp = m_alloc.allocate(sz);
						std::uninitialized_copy(this->begin(), this->end(), newStorage);
						std::uninitialized_fill_n(newStorage + m_size, sz - m_size, c);
						this->clear();
						m_alloc.deallocate(m_data, m_capacity);
						m_data = newStorage;
						m_capacity = sz;
						m_size = sz;
					}
					else if (sz < m_size)
					{
						for (; m_size > sz; m_size--)
							m_alloc.destroy(m_data + m_size - 1);
					}
					else
					{
						for (; m_size < sz; m_size++)
							m_alloc.construct(m_data + m_size, c);
					}
				}
				size_type capacity() const { return m_capacity; }
				bool empty() const { return m_size == 0; }
				void reserve(size_type n)
				{
					if (n > m_alloc.max_size())
						throw std::length_error("Call to ft::vector::resize with (size > max_size)");
					if (n <= m_capacity)
						return ;
					pointer tmp = m_alloc.allocate(n);
					std::uninitialized_copy(m_data, m_data + m_size, tmp);
					for (iterator it = this->begin(); it != this->end(); it++)
						m_alloc.destroy(it);
					m_alloc.deallocate(m_data, m_capacity);
					m_data = tmp;
					m_capacity = n;
				}

				// element access:
				reference operator[](size_type n) { return m_data[n]; };
				const_reference operator[](size_type n) const { return m_data[n]; };
				const_reference at(size_type n) const
				{
					if (n < 0 || n >= m_size)
						throw std::out_of_range("Call to ft::vector::at() with out of bound parameter");
					return m_data[n];
				}
				reference at(size_type n)
				{
					if (n < 0 || n >= m_size)
						throw std::out_of_range("Call to ft::vector::at() with out of bound parameter");
					return m_data[n];
				}
				reference front() { return m_data[0]; }
				const_reference front() const { return m_data[0]; }
				reference back() { return m_data[m_size - 1]; }
				const_reference back() const { return m_data[m_size - 1]; }

				// 23.2.4.3 modifiers:
				void push_back(const T& x)
				{
					if (m_capacity == 0)
					{
						if (m_data)
							m_alloc.deallocate(m_data, m_capacity);
						m_data = m_alloc.allocate(++m_capacity);
					}
					else if (m_capacity == m_size)
					{
						pointer newStorage = m_alloc.allocate(m_capacity * 2);

						try {
						std::uninitialized_copy(this->begin(), this->end(), newStorage);
						} catch (...) {
							m_alloc.deallocate(newStorage, m_capacity * 2);
							throw;
						}
						for (unsigned i = 0; i < m_size; i++)
							m_alloc.destroy(m_data + i);
						m_alloc.deallocate(m_data, m_capacity);
						m_capacity *= 2;
						m_data = newStorage;
					}
					m_alloc.construct(m_data + m_size, x);
					m_size++;
				}

				void pop_back()
				{
					--m_size;
					m_alloc.destroy(m_data + m_size);
				}

				iterator insert(iterator position, const T& x)
				{
					this->insert(position, 1lu, x);
					return position;
				}	

				void insert(iterator position, size_type n, const T& x)
				{
					difference_type before = std::distance(m_data, position);
					if (m_capacity < (m_size + n))
					{
						size_type newCapa = m_capacity * 2 > m_size + n ? m_capacity * 2 : m_size + n;
						pointer tmp = m_alloc.allocate(newCapa);	
						try {
						std::uninitialized_copy(this->begin(), position, tmp);
						std::uninitialized_fill_n(tmp + before, n, x);
						std::uninitialized_copy(position, this->end(), tmp + before + n);
						} catch (...) {
							m_alloc.deallocate(tmp, newCapa);
							throw;
						}
						for (iterator it = this->begin(); it != this->end(); it++)
							m_alloc.destroy(it);
						m_alloc.deallocate(m_data, m_capacity);
						m_data = tmp;
						m_capacity = newCapa;
					}
					else
					{
						iterator toCopy = this->end() - n - position > 0 ? this->end() - n : position;
						std::uninitialized_copy(toCopy, this->end(), toCopy + n);
						std::copy_backward(position, toCopy, n + toCopy);
						iterator toAssign = position + n > this->end() ? this->end() : (position + n);
						std::fill(position, toAssign, x);
						std::uninitialized_fill(toAssign, position + n, x);
					}
					m_size += n;
				}

				template <class InputIterator>
					void insert(iterator position, InputIterator first, InputIterator last)
					{
						difference_type before = std::distance(m_data, position);
						difference_type n = std::distance(first, last);
						if (m_capacity < (m_size + n))
						{
							size_type newCapa = m_capacity * 2 > m_size + n ? m_capacity * 2 : m_size + n;
							pointer tmp = m_alloc.allocate(newCapa);	
						try {
							std::uninitialized_copy(this->begin(), position, tmp);
							std::uninitialized_copy(first, last, tmp + before);
							std::uninitialized_copy(position, this->end(), tmp + before + n);
						} catch (...) {
							m_alloc.deallocate(tmp, newCapa);
							throw;
						}
							for (iterator it = this->begin(); it != this->end(); it++)
								m_alloc.destroy(it);
							m_alloc.deallocate(m_data, m_capacity);
							m_data = tmp;
							m_capacity = newCapa;
						}
						else
						{
							iterator toCopy = this->end() - n - position > 0 ? this->end() - n : position;
							std::uninitialized_copy(toCopy, this->end(), toCopy + n);
							std::copy_backward(position, toCopy, n + toCopy);
							size_type initCopy = static_cast<difference_type>(m_size) - before > n ? n : m_size - before;
							std::copy(first, first + initCopy, position);
							std::uninitialized_copy(first + initCopy, last, position + initCopy);
						}
						m_size += n;
					}
				iterator erase(iterator position)
				{
					return (this->erase(position, position + 1));
				}
				iterator erase(iterator first, iterator last)
				{
					difference_type len = std::distance(first, last);

					for (iterator it = std::copy(last, this->end(), first); it != this->end(); it++)
						m_alloc.destroy(it);

					m_size -= len;
					return first;
				}
				void swap(vector<T>& ent)
				{
					ft::swap(*this, ent);
				}
				void clear()
				{
					this->destroy_elements(this->begin(), this->end());
					m_size = 0;
				}
			private:
				inline void destroy_elements(iterator first, iterator last)
				{
					for (;first != last; first++)
						m_alloc.destroy(first);
				}
		};

		template<typename T>
		bool operator==(const vector<T>& lhs, const vector<T>& rhs)
		{
			return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}
		template<typename T>
		bool operator!=(const vector<T>& lhs, const vector<T>& rhs)
		{
			return !(lhs == rhs);
		}
		template<typename T>
		bool operator<(const vector<T>& lhs, const vector<T>& rhs)
		{
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
		template<typename T>
		bool operator<=(const vector<T>& lhs, const vector<T>& rhs)
		{
			return lhs < rhs || lhs == rhs;
		}
		template<typename T>
		bool operator>=(const vector<T>& lhs, const vector<T>& rhs)
		{
			return !(lhs < rhs);
		}
		template<typename T>
		bool operator>(const vector<T>& lhs, const vector<T>& rhs)
		{
			return !(lhs <= rhs);
		}
		template <typename T>
			void swap(vector<T>& lhs, vector<T>& rhs)
			{
				lhs.swap(rhs);
			}
}

#endif 
