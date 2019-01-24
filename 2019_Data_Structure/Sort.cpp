#include "Sort.h"

vector<int> sorting :: mergeSort(vector<int> data)
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
