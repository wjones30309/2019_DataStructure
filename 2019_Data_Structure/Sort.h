#pragma once
#include <iostream>
#include <vector>

using namespace std;
class sorting
{
public:
	vector<int> mergeSort(vector<int> data);
	vector<int> bubbleSort(vector<int> data);
	vector<int> selectionSort(vector<int> data);
	vector<int> quickSort(vector<int> data);
};

