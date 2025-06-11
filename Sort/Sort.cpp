#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <chrono>

using namespace std;

void BubbleSort(vector<int>& v)
{
	const int n = (int)v.size();

	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
		}
	}
}

void SelectionSort(vector<int>& v)
{
	const int n = (int)v.size();

	for (int i = 0; i < n - 1; i++)
	{
		int bestIndex = i;
		for (int j = i+1; j < n; j++)
		{
			if (v[j] < v[bestIndex])
				bestIndex = j;
		}
		swap(v[i], v[bestIndex]);
	}
}

void InsertionSort(vector<int>& v)
{
	const int n = static_cast<int>(v.size());

	for (int i = 1; i < n; i++)
	{
		int insertData = v[i];

		int j;

		for (j = i - 1; j >= 0; j--)
		{
			if (v[j] > insertData)
				v[j + 1] = v[j];
			else
				break;
		}

		v[j + 1] = insertData;
	}
}
int main()
{
	vector<int> v{ 5, 4};

	//BubbleSort(v);
	//SelectionSort(v);
	InsertionSort(v);

	for(int i = 0;i < v.size() ; i ++)
	{
		cout << v[i] << endl;
	}
}