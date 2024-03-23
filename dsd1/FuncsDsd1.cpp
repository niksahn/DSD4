#include <iostream>
#include "Header.h"

Set::Set() {

}

bool Set::f2() {
	return data.empty();
}

bool Set::f3(int a) {
	if (f2()) return false;
	return find(data.begin(), data.end(), a) != data.end();
}

void Set::f4(int val)
{
	if (!f3(val)) data.push_front(val);
}

Set::Set(int count, int min,int max, int del)
{
	if (count > 0 && max - min > count)
	{
		while (data.size() < count + 1)
		{
			int minR = 0;
			int maxR = max / del - 1;
			int mult = del;
			f4(min + (rand() % (maxR - minR + 1) + minR) * mult);
		}
	}
}

int Set::f6() 
{
	return data.size();
}

string Set::f7(char divider)
{
	string rez = "";
	if (f2()) return "";
	for (const auto& i : data)
	{
		rez+= to_string(i);
		rez += divider;
	}
	return rez.substr(0,(rez.length() - 1));
}

Set::~Set()
{	
	data.clear();
}

bool Set::f9 (Set* B)
{
	if (f2()) return true;
	for (const auto& val : data) {
		if (!B->f3(val)) return false;
	}
	return true;
}

bool Set::f10(Set* B)
{
	return (f9(B) && B->f9(this));
}

Set Set::f11(Set* B)
{
	Set C = Set();
	for (const auto& val : data) {
		C.f4(val);
	}
	for (const auto& val : B->data) {
		C.f4(val);
	}
	return C;
}

Set Set::f12(Set* B)
{
	Set Crossinng = Set();
	if (f2() || B->f2() )return Crossinng;
	for (const auto& val : B->data) 
	{
		if(f3(val)) Crossinng.f4(val);
	}
	return Crossinng;
}

Set Set::f13(Set* B)
{	
	Set Diff = Set();
	if (f2()) return Diff;
	for (const auto& val : data) {
		if (!B->f3(val)) Diff.f4(val);
	}
	return Diff;
}

Set Set::f14(Set* B)
{
	return f13(B).f11(&B->f13(this));
}