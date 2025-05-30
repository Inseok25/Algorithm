#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Vertex
{
	// data;
};
vector<Vertex> verticis;
vector<vector<int>> adj;
vector<bool> discovered;

void CreateGraph()
{
	/*adj = vector<vector<int>>
	{

	};*/

	adj = vector<vector<int>>(6);
	adj[0].push_back(1);
	adj[0].push_back(3);
	adj[1].push_back(0);
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[3].push_back(4);
	adj[5].push_back(4);
}

void Bfs(int here)
{
	queue<int> q;

	q.push(here);
	discovered[here] = true;
	while (q.empty() == false)
	{
		here = q.front();
		q.pop();
		cout << "visited : " << here << endl;
		for (int there : adj[here])
		{
			if (discovered[there] == true)
				continue;
			discovered[there] = true;
			q.push(there);
		}
	}
}

void BfsAll()
{
	for (int i = 0; i < verticis.size(); i++)
	{
		if (discovered[i] == false)
			Bfs(i);
	}
}
int main()
{
	CreateGraph();

	discovered = vector<bool>(6, false);

	Bfs(0);
	return 0;
}