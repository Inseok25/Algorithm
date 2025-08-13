#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <windows.h>

using namespace std;
#include <thread>

int cache[50][50];

int Combination(int n, int r)
{
	if (r == 0 || n == r)
		return 1;

	int& ret = cache[n][r];
	if (ret != -1)
		return ret;

	return ret = Combination(n - 1, r - 1) + Combination(n - 1, r);
}

int main()
{
	__int64 start = GetTickCount64();

	int lotto = Combination(45, 6);

	__int64 end = GetTickCount64();

	cout << end - start << endl;
	return 0;
}