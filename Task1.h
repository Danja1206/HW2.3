#pragma once

#include <list>

using namespace std;


template<typename T>
void average_push_back(list<T>& _lst)
{
	T average = 0;
	for (auto& element : _lst)
		average += element;
	_lst.push_back(average / static_cast<T>(_lst.size()));
}