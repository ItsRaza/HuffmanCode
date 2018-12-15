#pragma once
#ifndef MINHEAP_H
#define MINHEAP_H
#include<iostream>
#include<string>
#include"HuffmanTree.h"
using namespace std;
class MinHeap
{
public:
	ht **arr;
	int capacity;
	int count;
	MinHeap(){}
	MinHeap(int size_in)
	{
		arr = new ht*[size_in];
		this->capacity = size_in;
		this->count = 0;
	}
	MinHeap* createMinHeap(int size_in)
	{
		MinHeap *temp = new(MinHeap);
		temp->count = 0;
		temp->capacity = size_in;
		temp->arr = (ht**)(malloc(temp->capacity*sizeof(ht*)));
		return temp;
	}
	void swap(ht **a, ht **b)
	{
		ht *temp = *a;
		*a = *b;
		*b = temp;
	}
	void Insert(MinHeap *in,ht *obj)
	{
		in->count++;
		int i = in->count-1;
		while (i&&obj->freq<in->arr[(i-1)/2]->freq)
		{
			in->arr[i] = in->arr[(i - 1) / 2];
			i = (i - 1) / 2;
		}
		in->arr[i] = obj;
	}
	void BuildHeap(MinHeap* in)
	{
		int n = in->count - 1;
		int i;

		for (i = (n - 1) / 2; i >= 0; --i)
		{
			heapify(in, i);
		}
	}
	MinHeap* CreateNBuild(FreqTable table_in, int size_in)
	{
		MinHeap *tempHeap = createMinHeap(size_in);
		for (int i = 0; i < size_in; i++)
		{
			tempHeap->arr[i] = tempHeap->arr[i]->createNode(table_in.heap[i].getChar(), table_in.heap[i].getFreq());
		}
		tempHeap->count = size_in;
		BuildHeap(tempHeap);
		return tempHeap;
	}
	void PrintHeap()
	{
		for (int i = 0; i < count; i++)
		{
			cout << arr[i]->data << " Has Freq " << arr[i]->freq << endl;
		}
	}
	void heapify(MinHeap *in,int idx)
	{
		int smallest = idx;
		int left = 2 * idx + 1;
		int right = 2 * idx + 2;
		if (left < in->count&&in->arr[left]->freq<in->arr[smallest]->freq)
		{
			smallest = left;
		}
		if (right < in->count&&in->arr[right]->freq<in->arr[smallest]->freq)
		{
			smallest = right;
		}
		if (smallest != idx)
		{
			swap(&in->arr[smallest], &in->arr[idx]);
			heapify(in,smallest);
		}
	}
	bool IsSizeone()
	{
		if (this->count == 1)
		{
			return true;
		}
		return false;
	}
	ht* ExtractMin(MinHeap *in)
	{
		ht *temp = in->arr[0];
		in->arr[0] = in->arr[in->count - 1];
		--in->count;
		heapify(in,0);
		return temp;
	}
	ht* BuildHtree(FreqTable table_in)
	{
		ht *left;
		ht *right;
		ht *top = NULL;;
		MinHeap *minHeap = CreateNBuild(table_in, table_in.count);
		while (!minHeap->IsSizeone())
		{
			left = ExtractMin(minHeap);
			right = ExtractMin(minHeap);
			top = top->createNode('$', left->freq + right->freq);
			top->left = left;
			top->right = right;
			Insert(minHeap, top);
		}		
		return ExtractMin(minHeap);
	}
	ht* Huffman(FreqTable table_in)
	{
		ht *root = BuildHtree(table_in);
		ht *curr = root;
		int arr[size];
		int top = 0;
		root->EnCode(curr,arr, top);
		return root;
	}
};
#endif