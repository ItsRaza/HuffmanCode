#include<iostream>
#include<string>
#include<fstream>
#define size 200
#include"F_list.h"
#include"FreqTable.h"
#include"MinHeap.h"
#include"HuffmanTree.h"
#include"F_list.h"
using namespace std;
int FindFreq(char input, char arr_in[])
{
	char checkCharacter = input;
	int count = 0;

	for (int i = 0; arr_in[i]; i++)
	{
		if (arr_in[i] == checkCharacter)
		{
			++count;
		}
	}
	return count;
}
void main()
{
	char *arr;
	arr = new char[size];
	string bla;
	int i = 0;
	ifstream file;
	file.open("Try.txt");
	while (!file.eof())
	{
		file.get(arr[i]);
		i++;
	}
	arr[--i] = '\0';
	int freq = 0;
	int size_n = sizeof(file);
	cout << "Input string :" << endl;
	for (int i = 0; arr[i]; i++)
	{
		cout << arr[i];
	}
	cout << endl;
	cout << "Size:" << size_n << endl;
	cout << endl;
	FreqTable FreqTabl(size_n);
	for (int i = 0; arr[i]; i++)
	{
		freq = 0;
		freq = FindFreq(arr[i], arr);
		FreqTabl.insert(arr[i], freq);
	}
	cout << "Huffman Codes Generated are:" << endl;
	MinHeap heap;
	ht *root = heap.Huffman(FreqTabl);
	for (int i = 0; arr[i]; i++)
	{
		root->InlinePrint(arr[i]);
	}
	cout << endl;
	root->CodeSize();
	cout << endl;
	cout << "Decoded Output" << endl;
	for (int i = 0; i < root->getCapital_i(); i++)
	{
		root->DeCode(root, i);
	}
	cout << endl;
	delete[] arr;
	system("pause");
}