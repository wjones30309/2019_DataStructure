#include "Sort.h"
#include <stdlib.h>
#include <time.h>

vector<int> sorting::mergeSort(vector<int> data)
{
	vector<int> left;
	vector<int> right;

	for (register int i = 0; i < data.size() / 2; i++)
		left.push_back(data[i]);
	for (register int i = data.size() / 2; i < data.size(); i++)
		right.push_back(data[i]);

	if (data.size() != 1)
	{
		left = mergeSort(left);
		right = mergeSort(right);
	}

	if (data.size() != 1)
	{
		int l = 0, r = 0;
		data.clear();
		while (1)
		{
			if (l == left.size() && r == right.size())
			{
				cout << "----------------after doing mergesort----------------" << endl;

				for (int i = 0; i < data.size(); i++)
					cout << data[i] << endl;
				return data;
			}
			if (left.size() == l)
			{
				data.push_back(right[r]);
				r++;
			}
			else if (right.size() == r)
			{
				data.push_back(left[l]);
				l++;
			}
			else if (left[l] <= right[r])
			{
				data.push_back(left[l]);
				l++;
			}
			else
			{
				data.push_back(right[r]);
				r++;
			}
		}
	}
	else
		return data;
}

vector<int> sorting::bubbleSort(vector<int> data)
{
	for (int i = data.size() - 1; i > 1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (data[j] > data[j + 1])
			{
				int tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
	return data;
}

vector<int> sorting::selectionSort(vector<int> data)
{
	for (int i = 0; i < data.size(); i++)
	{
		int min = data[data.size() - 1];
		int tmp_order = data.size() - 1;

		for (int j = i; j < data.size(); j++)
		{
			if (data[j] < min)
			{
				min = data[j];
				tmp_order = j;
			}

		}

		data[tmp_order] = data[i];
		data[i] = min;
	}

	return data;
}

vector<int> sorting::quickSort(vector<int> data)
{
	//set the pivot
	srand(time(NULL));

	int pivot_num = rand() % data.size();
	int pivot = data[pivot_num];

	vector<int> left;
	vector<int> right;

	for (int i = 0; i < data.size(); i++)
	{
		if (i != pivot_num)
		{
			if (data[i] <= pivot)
				left.push_back(data[i]);
			else
				right.push_back(data[i]);
		}
	}

	if(left.size() != 0)
		left = quickSort(left);
	if (right.size() != 0)
	right = quickSort(right);


	data.clear();

	data = left;
	data.push_back(pivot);

	//push 'right' into 'data'
	vector<int>::iterator iter = data.end();
	vector<int>::iterator begin_iter = right.begin();
	vector<int>::iterator end_iter = right.end();

	data.insert(iter, begin_iter, end_iter);

	return data;
}