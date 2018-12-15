#pragma once
#ifndef HT_H
#define HT_H
#include<iostream>
#include<string>
#include"ListArr.h"
#include"MinHeap.h"
#include "F_list.h"
F_list *start = NULL;
int i = 0;
using namespace std;
class ht
{
public:
	char data;
	int freq;
	int code;
	ht *left;
	ht *right;
	ht(){}
	ht* createNode(char data_in,int freq_in)
	{
		ht *ptr;
		ptr = new(ht);
		ptr->data = data_in;
		ptr->freq = freq_in;
		ptr->code = 0;
		ptr->left = NULL;
		ptr->right = NULL;
		return ptr;
	}
	bool IsLeaf(ht *in)
	{
		if (in->left == NULL&&in->right == NULL)
		{
			return true;
		}
		return false;
	}
	void EnCode(ht *root,int arr[], int top)
	{
		if (root->left)
		{
			root->code = 0;
			arr[top] = 0;
			EnCode(root->left,arr, top + 1);
		}
		if (root->right)
		{
			root->code= 1;
			arr[top] = 1;
			EnCode(root->right,arr, top + 1);
		}
		if (IsLeaf(root))
		{
			savecode(root->data,arr, top);
		}
	}
	void savecode(char char_in,int arr[], int j)
	{
		start->insert(char_in, arr, j, &start);
	}
	void InlinePrint(char in)
	{
		start->searchR(in, &start);
	}
	void CodeSize()
	{
		cout<<"Size of codes:" << start->retCapital_i()/8 << endl;
	}
	void print()
	{
		start->printCodeArr();
	}
	void DeCode(ht *root,int itr)
	{
		ht *curr = root;
		int bit = 0;
		while (bit < 2 && !IsLeaf(curr))
		{
			bit = start->get_i(i);
			i++;
			if (bit == 0)
			{
				curr = curr->left;
			}
			if (bit == 1)
			{
				curr = curr->right;
			}
		}
		if (IsLeaf(curr))
		{
			cout << curr->data;
		}
	}
	int getCapital_i()
	{
		return start->retCapital_i();
	}
	void InOrder(ht *root)
	{
		if (root == NULL)
		{
			return;
		}
		InOrder(root->left);
		cout << root->code << endl;
		InOrder(root->right);
	}
};
#endif