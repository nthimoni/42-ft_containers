/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:21:58 by nthimoni          #+#    #+#             */
/*   Updated: 2023/02/21 18:27:04 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"vector.hpp"
#include	<vector>
#include	<iostream>
#include	<algorithm>

class A
{
	int* data;
	const static int max_a = 35000; //24
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
bool operator<(const A& val) const { std::cout << " --------------- <<<<<< --------------- " << this << " " << &val << std::endl;return *data < *(val.data); }
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

int main()
{
	std::vector<A> a;
	ft::vector<A> b;
	a.push_back(1);
	a.push_back(6);
	a.push_back(3);
	a.push_back(5);
	a.push_back(4);
	a.push_back(2);
	b.push_back(1);
	b.push_back(6);
	b.push_back(3);
	b.push_back(5);
	b.push_back(4);
	b.push_back(2);
	for (int i = 0; i < b.size(); i++) std::cout << b.at(i) << std::endl;
	for(std::vector<A>::reverse_iterator i = a.rbegin(); i != a.rend(); i++) std::cout << "num : " << *i << std::endl;
	std::cout << " ----------------------------------------------------------------------" << std::endl;
	for(ft::vector<A>::reverse_iterator i = b.rbegin(); i != b.rend(); i++) std::cout << "num : " << *i << std::endl;
	std::cout << " ----------------------------------------------------------------------" << std::endl;
	std::sort(a.rbegin(), a.rend());
	std::sort(b.rbegin(), b.rend());
	for(std::vector<A>::reverse_iterator i = a.rbegin(); i != a.rend(); i++) std::cout << "num : " << *i << std::endl;
	std::cout << " ----------------------------------------------------------------------" << std::endl;
	for(ft::vector<A>::reverse_iterator i = b.rbegin(); i != b.rend(); i++) std::cout << "num : " << *i << std::endl;
	return 0;
	ft::vector<A> vec;
	vec.reserve(15);
	for (int i = 0; i < 10; i++)
	{
		A::log();
		vec.push_back(i);
	}
	try {
	vec.erase(vec.begin() + 1, vec.end() - 6);
	} catch (std::exception& e) {
		std::cout << "exception : " << e.what() << std::endl;
	}
	A::log();
	std::cout << vec.size() << " " << vec.capacity() << std::endl;
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << std::endl;
	std::cout << "--------------STD CONTAINER------------------" << std::endl;
	{
		std::vector<A> a;
		std::vector<A> b;
		//a.insert(a.end() - 2, 60lu, 10);
		a.push_back(5);
		a.push_back(6);
		a.push_back(7);
		a.push_back(8);
		a.push_back(9);
		std::sort(a.rbegin(), a.rend());
		for(std::vector<A>::iterator i = a.begin(); i != a.end(); i++) std::cout << *i << std::endl;
		a.erase(a.begin() + 1, a.end() - 1);
		std::cout << "--------------------------------" << std::endl;
		for(std::vector<A>::iterator i = a.begin(); i != a.end(); i++) std::cout << *i << std::endl;
		std::cout << a.size() << " " << a.capacity() << " " << a[0] << std::endl;
		a.reserve(100);
		std::cout << a.size() << " " << a.capacity() << " " << a[0] << std::endl;
		a.push_back(2);
		std::vector<A> c(a.begin(), a.end());
		for(std::vector<A>::iterator i = c.begin(); i != c.end(); i++) std::cout << *i << std::endl;
		a = b;
		a.push_back(1);
		std::cout << "--------------------------------" << std::endl;
		std::cout << a.size() << " " << a.capacity() << std::endl;
		for(std::vector<A>::iterator i = c.begin(); i != c.end(); i++) std::cout << *i << std::endl;
	}
	std::cout << "--------------MY CONTAINER------------------" << std::endl;
	{
		ft::vector<A> a;
		ft::vector<A> b;
		a.push_back(5);
		a.push_back(6);
		a.push_back(7);
		a.push_back(8);
		a.push_back(9);
		std::sort(a.rbegin(), a.rend());
		for(ft::vector<A>::reverse_iterator i = a.rbegin(); i != a.rend(); i++) std::cout << "num : " << *i << std::endl;
		for(ft::vector<A>::iterator i = a.begin(); i != a.end(); i++) std::cout << *i << std::endl;
		a.erase(a.begin() + 1, a.end() - 1);
		std::cout << "--------------------------------" << std::endl;
		for(ft::vector<A>::iterator i = a.begin(); i != a.end(); i++) std::cout << *i << std::endl;
		std::cout << a.size() << " " << a.capacity() << " " << a[0] << std::endl;
		a.reserve(100);
		std::cout << a.size() << " " << a.capacity() << " " << a[0] << std::endl;
		a.push_back(2);
		ft::vector<A> c(a.begin(), a.end());
		for(ft::vector<A>::iterator i = c.begin(); i != c.end(); i++) std::cout << *i << std::endl;
		a = b;
		c.push_back(1);
		c.push_back(2);
		c.push_back(3);
		c.push_back(4);
		std::cout << "--------------------------------" << std::endl;
		std::cout << c.size() << " " << c.capacity() << std::endl;
		for(ft::vector<A>::iterator i = c.begin(); i != c.end(); i++) std::cout << *i << std::endl;
		c.reserve(c.size() + 60);
		c.insert(c.end() - 2, 60lu, 10);
		std::cout << "--------------------------------" << std::endl;
		std::cout << c.size() << " " << c.capacity() << std::endl;
		for(ft::vector<A>::iterator i = c.begin(); i != c.end(); i++) std::cout << *i << std::endl;
	}
}
