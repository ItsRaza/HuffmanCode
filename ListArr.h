#include<iostream>
#pragma once
using namespace std;
class ListArr
{
private:
	char character;
	int freq;
public:
	ListArr()
	{
		this->character = NULL;
		this->freq = 0;
	}
	int getFreq()
	{
		return this->freq;
	}
	char getChar()
	{
		return this->character;
 	}
	void setChar(char in)
	{
		this->character = in;
	}
	void setFreq(int in)
	{
		this->freq = in;
	}
	void setObj(char char_in, int freq_in)
	{
		this->character = char_in;
		this->freq = freq_in;
	}
	void print()
	{
		cout << this->character << " Has Freq " << this->freq << endl;
	}
};