/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:16:06 by nthimoni          #+#    #+#             */
/*   Updated: 2023/02/20 14:43:05 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>

#define NAMESPACE ft
//#define NAMESPACE std

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
	std::vector<A> p;
	p.push_back(1);
	p.push_back(2);
	p.push_back(3);
	p.push_back(4);
	p.push_back(5);
	p.push_back(6);
	{
		std::cout << "\n########## INSERT2  ##########\n\n";
		NAMESPACE::vector<A> y;

		y.reserve(8);
		y.push_back(1);
		y.push_back(2);
		y.push_back(3);
		y.push_back(4);    
		NAMESPACE::vector<A> w;
		NAMESPACE::vector<A> x;
		NAMESPACE::vector<A> z;
		w.reserve(8);
		x.reserve(8);
		z.reserve(8);
		w = y;
		x = y;
		z = y;
		w.push_back(5);
		std::cout << "w : cap = " << w.capacity() << ", size = " << w.size() << std::endl;
		std::cout << "x : cap = " << x.capacity() << ", size = " << x.size() << std::endl;
		std::cout << "y : cap = " << y.capacity() << ", size = " << y.size() << std::endl;
		std::cout << "z : cap = " << z.capacity() << ", size = " << z.size() << std::endl;
		w.insert(w.begin(), 2lu, 7);
		//w.insert(w.begin(), p.begin(), p.begin() + 2);
		x.insert(x.begin() + 2, 4lu, 7);
		//x.insert(x.begin() + 2, p.begin(), p.begin() + 4);
		y.insert(y.end(), 4lu, 7);
		//y.insert(y.end(), p.begin(), p.begin() + 4); // ICI
		z.insert(z.begin(), 4lu, 7);
		//z.insert(z.begin(), p.begin(), p.begin() + 4);
	}
}
