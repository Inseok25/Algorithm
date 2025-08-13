#include <stack>
#include <queue>
using namespace std;
#include <thread>
#include <Windows.h>

vector<int> seq;
int cache[100];

int LIS(int pos)
{
	int& ret = cache[pos];
	if (ret != -1)
		return ret;

	ret = 1;

	for (int next = pos + 1; next < seq.size(); next++)
		if (seq[pos] < seq[next])
			ret = max(ret, 1 + LIS(next));

	return ret;
}

int main()
{
	::memset(cache, -1, sizeof(cache));
	seq = vector<int>{ 10, 1, 9, 2, 5, 7 };
	
	int ret = 0;
	for (int pos = 0; pos < seq.size(); pos++)
		ret = max(ret, LIS(pos));

	return 0;

}