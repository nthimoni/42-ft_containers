/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realtest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:00:51 by nthimoni          #+#    #+#             */
/*   Updated: 2023/03/03 22:08:51 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NS
# define NS ft
#endif

#if NS == ft
# include "vector.hpp"
# include "algorithm.hpp"
#endif
#if NS == std
# include <vector>
#endif

#include <iostream>
#include <algorithm>


class A
{
	int* data;
	const static int max_a = 5500; //24
	static int a;
	public:
	A()
	{
		if (a++ > max_a)
			throw std::runtime_error("oupsi");
		data = new int(0);
	}
	A(int r)
	{
		if (a++ > max_a)
			throw std::runtime_error("oupsi");
		data = new int(r);
	}
	A(const A& val)
	{
		if (a++ > max_a)
			throw std::runtime_error("oupsi");
		data = new int(val.getData());
	}
	static void log()
	{
		std::cout << "stat : " << a << std::endl;
	}
	int getData() const
	{
		return *data;
	}
	A* operator&() { return NULL; }
	A& operator=(const A& val)
	{
		if (a++ > max_a)
			throw std::runtime_error("oupsi");
		*data = val.getData();
		return *this;
	}
	bool operator==(const A& val) const { return *data == *(val.data); }
	bool operator<=(const A& val) const { return *data <= *(val.data); }
	bool operator>=(const A& val) const { return *data >= *(val.data); }
	bool operator>(const A& val) const { return *data > *(val.data); }
	bool operator<(const A& val) const { return *data < *(val.data); }
	~A()
	{
		delete data;
	}
};

int A::a = 0;

std::ostream& operator<<(std::ostream& out, const A& val)
{
	out << val.getData();
	return out;
}

template <typename T>
void printVector(const T& a)
{
	std::cout << "size : " << a.size() << " - empty : " << a.empty() << std::endl;
	std::cout << "{ ";
	for (unsigned int i = 0; i < a.size(); i++) std::cout << a[i] << " ";
	std::cout << "}" << std::endl;;
	std::cout << "{ ";
	for (NS::vector<A>::const_iterator i = a.begin(); i != a.end(); i++) std::cout << *i << " ";
	std::cout << "}" << std::endl;;
	std::cout << "{ ";
	for (NS::vector<A>::const_reverse_iterator i = a.rbegin(); i != a.rend(); i++) std::cout << *i << " ";
	std::cout << "}" << std::endl;;
	std::cout << "----------------------------------------" << std::endl;
}

template <typename T>
void compareVector(const NS::vector<T>& a, const NS::vector<T>& b)
{
	std::cout << (a == b) << (a !=b ) << (a <= b) << (a >= b) << (a < b) << (a > b) << std::endl;
	std::cout << "----------------------------------------" << std::endl;
}

int main()
{
	NS::vector<A> y;
	y.push_back(5);
	y.push_back(49);
	y.push_back(7);
	y.push_back(1);
	y.push_back(3);
	y.push_back(9);
	y.push_back(3);
	y.push_back(17);
	printVector(y);
	{
		NS::vector<A> a;
		printVector(a);
	}
	{
		NS::vector<A> a(0);
		printVector(a);
	}
	{
		NS::vector<A> a(7);
		printVector(a);
	}
	{
		NS::vector<A> a(7, A(16));
		printVector(a);
	}
	{
		NS::vector<A> a(y.begin(), y.end());
		printVector(a);
	}
	{
		NS::vector<A> a(y);
		printVector(a);
		NS::vector<A> b;
		b.push_back(14758599);
		b.push_back(22131335);
		b.push_back(55242225);
		b.push_back(55545555);
		b = a;
	}
	{
		NS::vector<A> a;
		a.push_back(15757538);
		a.push_back(22131335);
		a.push_back(55242225);
		a.push_back(55545555);
		a.assign(3, A(7));
		printVector(a);
		a.assign(y.begin() + 1, y.end()-1);
		printVector(a);
	}
	{
		NS::vector<A> a;
		std::cout << "----------------------------------------" << std::endl;
		std::cout << a.get_allocator().max_size() << std::endl;
		std::cout << "----------------------------------------" << std::endl;
	}
	{
		std::cout << "----------------------------------------" << std::endl;
		for (NS::vector<A>::iterator i = y.begin(); i != y.end(); i++)
			std::cout << *i << " ";
		std::cout << std::endl;
		for (NS::vector<A>::reverse_iterator i = y.rbegin(); i != y.rend(); i++)
			std::cout << *i << " ";
		std::cout << std::endl;
		*(y.begin()) = 55;
		*(y.begin() + 2) = 55;
		*(y.end() - 2) = 55;
		printVector(y);
		std::cout << "----------------------------------------" << std::endl;
	}
	{
		NS::vector<A> a = y;
		a.push_back(456);
		a.push_back(487);
		a.resize(5, A(8));
		printVector(a);
		a.resize(150, A(8));
		printVector(a);
		a.resize(150, A(8));
		printVector(a);
		a.resize(8, A(6));
		printVector(a);
		a.resize(1, A(6));
		printVector(a);
		a.resize(150, A(8));
		printVector(a);
		a.resize(a.size(), A(8));
		printVector(a);
	}
	{
		NS::vector<A> a;
		printVector(a);
		a.reserve(5);
		a = y;
		printVector(a);
		a.reserve(5236);
		printVector(a);
		a.reserve(5);
		printVector(a);
	}
	{
		std::cout << "-------------------------------------------------" << std::endl;
		const NS::vector<A> a(y.begin(), y.end());
		NS::vector<A> b(y.begin(), y.end());
		printVector(a);
		printVector(b);
		b[0] = 5;
		b[1] = 8;
		std::cout << a[0] << a[5] << std::endl;
		printVector(a);
		printVector(b);
		for (unsigned int i = 0; i < a.size(); i++) std::cout << a.at(i) << " ";
		b.at(0) = 26;
		b.at(5) = 12;
		b.at(4) = 6;
		b.at(2) = 7;
		printVector(b);
		std::cout << std::endl <<"-------------------------------------------------" << std::endl;
		NS::vector<A> u;
		try {
			std::cout << u.at(0);
		} catch (std::out_of_range& e) {
			std::cout << "exception : " << e.what() << std::endl;
		}
		try {
			std::cout << u.at(1);
		} catch (std::out_of_range& e) {
			std::cout << "exception : " << e.what() << std::endl;
		}
		try {
			std::cout << u.at(-1);
		} catch (std::out_of_range& e) {
			std::cout << "exception : " << e.what() << std::endl;
		}
		u.push_back(55);
		try {
			std::cout << u.at(1);
		} catch (std::out_of_range& e) {
			std::cout << "exception : " << e.what() << std::endl;
		}
		u.push_back(55);
		try {
			std::cout << u.at(1);
		} catch (std::out_of_range& e) {
			std::cout << "exception : " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl <<"-------------------------------------------------" << std::endl;
		const NS::vector<A> a(y.begin(), y.end());
		NS::vector<A> b(y.begin(), y.end());
		NS::vector<A> c(1lu, 1);
		std::cout << a.front() << " " << a.back() << std::endl;
		std::cout << b.front() << " " << b.back() << std::endl;
		std::cout << c.front() << " " << c.back() << std::endl;
		printVector(a);
		printVector(b);
		printVector(c);
		b.front() = 5;
		compareVector(a, y);
		b.back() = 5266;
		compareVector(a, y);
		printVector(b);
		c.front() = 5;
		compareVector(a, y);
		c.back() = 5266;
		compareVector(a, y);
		printVector(c);
		std::cout << std::endl <<"-------------------------------------------------" << std::endl;
	}
	{
		NS::vector<A> a(y.begin(), y.end());
		printVector(a);
		a.push_back(65464);
		printVector(a);
		a.push_back(65);
		printVector(a);
		a.push_back(136);
		printVector(a);
		a.push_back(158);
		printVector(a);
		a.clear();
		printVector(a);
		a.push_back(185);
		a.push_back(225);
		printVector(a);
		a.push_back(283);
		a.push_back(251);
		a.push_back(253);
		a.push_back(253);
		a.push_back(428);
		a.push_back(313);
		a.push_back(274);
		a.push_back(246);
		printVector(a);
		a.pop_back();
		a.pop_back();
		printVector(a);
		a.pop_back();
		a.pop_back();
		a.pop_back();
		printVector(a);
		a.clear();
		printVector(a);
		a.push_back(246);
		printVector(a);
		a.pop_back();
		printVector(a);
	}
	{
		NS::vector<A> a(y.begin(), y.end());
		printVector(a);
		compareVector(a, y);
		a.insert(a.begin(), 55);
		std::cout << "zouzou" << std::endl;
		compareVector(a, y);
		printVector(a);
		printVector(y);
		a.insert(a.begin(), 68);
		compareVector(a, y);
		printVector(a);
		a.clear();
		compareVector(a, y);
		printVector(a);
		a.insert(a.end(), 68);
		compareVector(a, y);
		printVector(a);
		a.insert(a.end(), 88);
		compareVector(a, y);
		printVector(a);
		a.insert(a.end(), 94);
		compareVector(a, y);
		printVector(a);
		a.insert(a.end() - 1, 112);
		compareVector(a, y);
		printVector(a);
		a.insert(a.end() - 2, 356lu, 112);
		compareVector(a, y);
		printVector(a);
		a.insert(a.end() - 22, 383lu, 145);
		compareVector(a, y);
		printVector(a);
		a.erase(a.begin());
		compareVector(a, y);
		printVector(a);
		a.erase(a.begin() + 7);
		compareVector(a, y);
		printVector(a);
		a.erase(a.end() - 3);
		compareVector(a, y);
		printVector(a);
		a.erase(a.begin());
		compareVector(a, y);
		printVector(a);
		a.insert(a.begin() + 15, y.begin(), y.end());
		compareVector(a, y);
		printVector(a);
		a.insert(a.begin() + 153, y.begin() + 1, y.end() - 1);
		compareVector(a, y);
		printVector(a);
		a.clear();
		compareVector(a, y);
		printVector(a);
		a.insert(a.begin(), y.begin(), y.end());
		compareVector(a, y);
		printVector(a);
		a.insert(a.end(), y.begin(), y.end());
		compareVector(a, y);
		printVector(a);
		a.clear();
		compareVector(a, y);
		printVector(a);
		a.insert(a.begin(), y.begin(), y.end());
		compareVector(a, y);
		printVector(a);
		a.clear();
		compareVector(a, y);
		printVector(a);
		a.insert(a.end(), y.begin(), y.end());
		compareVector(a, y);
		printVector(a);
	}
	{
		NS::vector<A> a(y);
		NS::vector<A> b(a.begin() + 1, a.end() - 1);
		compareVector(a, b);
		printVector(a);
		printVector(b);
		a.swap(b);
		compareVector(a, b);
		printVector(a);
		printVector(b);
		NS::swap(a, b);
		compareVector(a, b);
		printVector(a);
		printVector(b);
		NS::swap(a, b);
		compareVector(a, b);
		printVector(a);
		printVector(b);
		b.swap(a);
		compareVector(a, b);
		printVector(a);
		printVector(b);
		a.push_back(54654);
		compareVector(a, b);
		a.push_back(54);
		compareVector(a, b);
		b.pop_back();
		compareVector(a, b);
		printVector(a);
		printVector(b);
		a.swap(b);
		compareVector(a, b);
		printVector(a);
		printVector(b);
		NS::swap(a, b);
		compareVector(a, b);
		printVector(a);
		printVector(b);
		b.swap(a);
		compareVector(a, b);
		printVector(a);
		printVector(b);
		NS::swap(a, b);
		compareVector(a, b);
		printVector(a);
		printVector(b);
	}
	{
		NS::vector<A> a;
		printVector(a);
		a.clear();
		printVector(a);
		NS::vector<A> b = y;
		compareVector(a, b);
		printVector(b);
		a.clear();
		compareVector(a, b);
		printVector(b);
	}
	{
		NS::vector<A> a(y);
		printVector(a);
		std::sort(a.begin(), a.end());
		printVector(a);
		a = y;
		printVector(a);
		std::sort(a.rbegin(), a.rend());
		printVector(a);
		NS::vector<A>::reverse_iterator::difference_type t;
		NS::iterator_traits<NS::vector<A>::iterator>::difference_type u;
		(void)t;
		(void)u;
	}
	{
		NS::vector<A> a;
		NS::vector<A> b;
		compareVector(a, b);
		a = y;
		compareVector(a, b);
		b = y;
		compareVector(a, b);
		a.pop_back();
		compareVector(a, b);
		b.pop_back();
		compareVector(a, b);
		a.push_back(5);
		compareVector(a, b);
		b.push_back(6);
		compareVector(a, b);
		b.pop_back();
		compareVector(a, b);
		b.push_back(4);
		compareVector(a, b);
		b.pop_back();
		compareVector(a, b);
		b.push_back(5);
		compareVector(a, b);
	}
	try {
		for (int i = 0; i < 222225000; i++)
			y.push_back(5);
	}
	catch (std::exception& e) {
		std::cout << "exception : " << e.what() << std::endl;
	}
	return 0;
}
