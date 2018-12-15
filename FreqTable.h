#include<iostream>
#include<string>
#include"ListArr.h"
#pragma once
using namespace std;
class FreqTable
{
public:
	ListArr *heap;
	int count;
	FreqTable(int size_in)
	{
		heap = new ListArr[size_in];
		this->count = 0;
	}
	void insert(char char_in, int freq_in)
	{
		if (ifExist(char_in))
		{
			return;
		}
		heap[count].setObj(char_in, freq_in);
		count++;
	}
	bool ifExist(char char_in)
	{
		int flag = 0;
		for (int i = 0; i <= count; i++)
		{
			if (heap[i].getChar() == char_in)
			{
				flag++;
			}
		}
		if (flag != 0)
		{
			return true;
		}
		return false;
	}
	ListArr& get(int i)
	{
		return heap[i];
	}
	void print()
	{
		for (int i = 0; i < count; i++)
		{
			get(i).print();
		}
	}
};