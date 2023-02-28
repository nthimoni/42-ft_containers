/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exception.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:51:47 by nthimoni          #+#    #+#             */
/*   Updated: 2023/02/28 22:26:29 by nthimoni         ###   ########.fr       */
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
	public:
	static int max_a; //24
	static int a;
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
int A::max_a = 5500;

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
	NS::vector<A> dd(12, A(12));
	int max_loop = 100;
	// Size + default constructor
	for (int i = 0; i < max_loop; i++)
	{
		A::max_a = i;
		try {
			for (int j = 0; j < 110; j++)
			{
				A::a = 0;
				NS::vector<A> a(j);
			}
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	// Size + int constructor
	for (int i = 0; i < max_loop; i++)
	{
		A::max_a = i;
		try {
			for (int j = 0; j < 110; j++)
			{
				A::a = 0;
				NS::vector<A> a(j, A(55));
			}
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	//range constructor
	for (int i = 0; i < 20; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a(dd.begin(), dd.end());
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	//Copy constructor
	for (int i = 0; i < 20; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a(dd);
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	//Assignement operator (with reallocation)
	for (int i = 0; i < 20; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a;
			a = dd;
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	//Assignement operator (no realloc newSize > oldSize)
	for (int i = 0; i < 110; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a(4, A(12));
			a.reserve(100);
			a = dd;
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	//Assignement operator (no realloc newSize < oldSize)
	for (int i = 0; i < 120; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a(20, A(12));
			a.reserve(100);
			a = dd;
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	//Assign n (realloc)
	for (int i = 0; i < 30; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a;
			a.assign(12, A(3));
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	//Assign n (no realloc newSize > oldSize)
	for (int i = 0; i < 100; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a(4, A(7));
			a.reserve(20);
			a.assign(15, A(3));
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	//Assign n (no realloc newSize < oldSize)
	for (int i = 0; i < 100; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a(15, A(7));
			a.reserve(20);
			a.assign(4, A(3));
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	//Assign range (realloc)
	for (int i = 0; i < 100; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a(1, A(7));
			a.assign(dd.begin(), dd.end());
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}

	//Assign range (no realloc newSize > oldSize)
	for (int i = 0; i < 100; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a(3, A(7));
			a.reserve(200);
			a.assign(dd.begin(), dd.end());
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	//Assign range (no realloc newSize < oldSize)
	for (int i = 0; i < 100; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a(25, A(7));
			a.assign(dd.begin(), dd.end());
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	//Resize (realloc)
	for (int i = 0; i < 110; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a(3, A(7));
			a.resize(40, A(3));
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	//Resize (no realloc, new size > old size)
	for (int i = 0; i < 110; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a(3, A(7));
			a.reserve(40);
			a.resize(40, A(3));
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	//Resize (no realloc, new size < old size)
	for (int i = 0; i < 110; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a(15, A(7));
			a.resize(8, A(3));
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	// Reserve
	for (int i = 0; i < 110; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a(15, A(7));
			a.reserve(100);
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	// Push_back (realloc)
	for (int i = 0; i < 150; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a;
			a.push_back(5);
			a.push_back(7);
			a.push_back(11);
			a.push_back(3);
			a.push_back(27);
			a.push_back(5);
			a.push_back(7);
			a.push_back(11);
			a.push_back(3);
			a.push_back(27);
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	// Push_back (no realloc)
	for (int i = 0; i < 150; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a;
			a.reserve(150);
			a.push_back(5);
			a.push_back(7);
			a.push_back(11);
			a.push_back(3);
			a.push_back(27);
			a.push_back(5);
			a.push_back(7);
			a.push_back(11);
			a.push_back(3);
			a.push_back(27);
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	// insert 1 elem (realloc)
	for (int i = 0; i < 150; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a;
			a.insert(a.begin(), A(45));
			a.insert(a.begin(), A(75));
			a.insert(a.begin() + 1, A(21));
			a.insert(a.end() - 1, A(27));
			a.insert(a.end(), A(18));
			a.insert(a.begin(), A(45));
			a.insert(a.begin(), A(75));
			a.insert(a.begin(), A(21));
			a.insert(a.begin(), A(27));
			a.insert(a.begin(), A(18));
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	// insert 1 elem (no realloc)
	for (int i = 0; i < 15000; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a;
			a.reserve(150);
			a.insert(a.begin(), A(45));
			a.insert(a.begin(), A(75));
			a.insert(a.begin() + 1, A(21));
			a.insert(a.end() - 1, A(27));
			a.insert(a.end(), A(18));
			a.insert(a.begin(), A(45));
			a.insert(a.begin(), A(75));
			a.insert(a.begin(), A(21));
			a.insert(a.begin(), A(27));
			a.insert(a.begin(), A(18));
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}

	// insert n elem (realloc)
	for (int i = 0; i < 1500; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a;
			a.insert(a.begin(),1, A(45));
			a.insert(a.begin(),35, A(75));
			a.insert(a.begin() + 1,2, A(21));
			a.insert(a.end() - 1,4, A(27));
			a.insert(a.end(),8, A(18));
			a.insert(a.begin(),7, A(45));
			a.insert(a.begin(),4, A(27));
			a.insert(a.begin(),7, A(18));
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}

	// insert n elem (no realloc)
	for (int i = 0; i < 1500; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a;
			a.reserve(250);
			a.insert(a.begin(),1, A(45));
			a.insert(a.begin(),35, A(75));
			a.insert(a.begin() + 1,2, A(21));
			a.insert(a.end() - 1,4, A(27));
			a.insert(a.end(),8, A(18));
			a.insert(a.begin(),7, A(45));
			a.insert(a.begin(),4, A(27));
			a.insert(a.begin(),7, A(18));
		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}

	// insert range (realloc)
	for (int i = 0; i < 150; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a;
			a.insert(a.begin(), dd.begin(), dd.begin() + 2);
			a.insert(a.begin(), dd.begin(), dd.end());
			a.insert(a.begin() + 1, dd.begin(), dd.end());
			a.insert(a.end() - 1, dd.begin(), dd.end());
			a.insert(a.begin() + 3, dd.begin(), dd.begin() + 2);

		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
	// insert range (no realloc)
	for (int i = 0; i < 150; i++)
	{
		A::max_a = i;
		A::a = 0;
		try {
			NS::vector<A> a;
			a.reserve(350);
			a.insert(a.begin(), dd.begin(), dd.begin() + 2);
			a.insert(a.begin(), dd.begin(), dd.end());
			a.insert(a.begin() + 1, dd.begin(), dd.end());
			a.insert(a.end() - 1, dd.begin(), dd.end());
			a.insert(a.begin() + 3, dd.begin(), dd.begin() + 2);

		} catch (...) {
			std::cout << "exception" << std::endl;
		} 
	}
}
