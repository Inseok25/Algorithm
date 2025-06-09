#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;

struct Vertex
{
	// data
};

vector<Vertex> verticis;
vector<vector<int>> adj;

void CreateGraph()
{
	verticis.resize(6);
	adj = vector<vector<int>>(6, vector<int>(6, -1));

	adj[0][1] = 15;
	adj[0][3] = 35;
	adj[1][0] = 15;
	adj[1][2] = 5;
	adj[1][3] = 10;
	adj[1][3] = 10;
	adj[3][4] = 5;
	adj[5][4] = 5;
}

void Dijstra(int here)
{
	struct VertexCost
	{
		int vertex;
		int cost;
	};

	list<VertexCost> discovered;
	vector<int> best(6, INT32_MAX);
	vector<int> parant(6, -1);

	discovered.push_back(VertexCost{ here, 0 });
	best[here] = 0;
	parant[here] = here;

	while (discovered.empty() == false)
	{
		list<VertexCost>::iterator bestIt;
		int bestCost = INT32_MAX;
		for (auto it = discovered.begin(); it != discovered.end();it++)
		{
			if (it->cost < bestCost)
			{
				bestCost = it->cost;
				bestIt = it;
			}
		}

		int cost = bestIt->cost;
		here = bestIt->vertex;
		discovered.erase(bestIt);

		if (best[here] < cost)
			continue;

		for (int there = 0; there < 6; there++)
		{
			if (adj[here][there] == -1)
				continue;

			int nextCost = best[here] + adj[here][there];
			if (nextCost >= best[there])
				continue;

			discovered.push_back(VertexCost{ there, nextCost });

			best[there] = nextCost;
			parant[there] = here;

		}
	}
}
int main()
{
	CreateGraph();
	return 0;
}