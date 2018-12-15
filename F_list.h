#include<iostream>
#include<string>
#define codes 200
int CodeArr[codes];
int capital_i = 0;
#pragma once
using namespace std;

class F_list
{
public:
	char character;
	int arr[6];
	int size_i = 0;
	F_list *next;
	F_list(){}
	void insert(char char_in,int arr_in[],int iter,F_list** head)
	{
		F_list *ptr;
		ptr = new(F_list);
		ptr->character = char_in;
		ptr->size_i = iter;
		for (int i = 0; i < iter; i++)
		{
			ptr->arr[i] = arr_in[i];
		}
		ptr->next = NULL;
		if (*head == NULL)
		{
			*head = ptr;
		}
		else
		{
			F_list *curr = *head;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = ptr;
		}
	}
	void print(F_list *head)
	{
		if (head == NULL)
		{
			//cout << "No students Exists in the list" << endl;
		}
		else
		{
			F_list *curr = head;
			while (curr != NULL)
			{
				cout << "Charater " << curr->character << " ";
				printArr(curr->arr, curr->size_i);
				curr = curr->next;
			}
		}
	}
	void printArr(int arr[], int itr)
	{
		for (int i = 0; i < itr; i++)
		{
			CodeArr[capital_i] = arr[i];
			capital_i++;
			cout << arr[i];
		}
		//capital_i = capital_i + itr;
	}
	void printCodeArr()
	{
		for (int i = 0; i < capital_i; i++)
		{
			cout << CodeArr[i];
		}
	}
	int getCodeSize()
	{
		return sizeof(CodeArr[capital_i]);
	}
	int get_i(int i)
	{
		if (i > capital_i)
		{
			return 2;
		}
		else
		return CodeArr[i];
	}
	int retCapital_i()
	{
		return capital_i;
	}
	bool callDecode(int i)
	{
		if (i > capital_i)
		{
			return false;
		}
		return true;
	}
	void searchR(char char_in, F_list **head)
	{
		if (*head == NULL)
		{
			return;
		}
		else
		{
			int flag = 0;
			F_list *curr = *head;
			while (curr->next != NULL)
			{
				if (curr->character == char_in)
				{
					printArr(curr->arr, curr->size_i);
					flag++;
					break;
				}
				curr = curr->next;
			}
			if ((curr->next == NULL) && curr->character == char_in)
			{
				printArr(curr->arr, curr->size_i);
				flag++;
			}
			if (flag == 0)
			{
				return;
			}
		}
	}

};