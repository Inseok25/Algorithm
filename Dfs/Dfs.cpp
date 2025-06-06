﻿#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
using namespace std;

struct Vertex
{
    // data;
};

vector<Vertex*> verticis;
vector<vector<int>> adj;
vector<bool> visited;
void CreateGraph()
{
    verticis.resize(6);
    //adj = vector<vector<int>>(6);
    /*adj[0].push_back(1);
    adj[0].push_back(3);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[5].push_back(4);*/

    adj = vector<vector<int>>
    {
        { 0, 1, 0, 1, 0, 0 },
        { 1, 0, 1, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 0 },
    };
}

void Dfs(int here)
{
    visited[here] = true;

    cout << "visited : " << here << endl;
    /*for (int i = 0; i < adj[here].size(); i++)
    {
        int there = adj[here][i];
        if (visited[there] == false)
            Dfs(there);
    }*/

    for (int i = 0; i < verticis.size(); i++)
    {
        if (adj[here][i] == 0)
            continue;
        if (visited[i] == false)
            Dfs(i);
    }
}
void DfsAll()
{
    for (int i = 0; i < verticis.size(); i++)
        if (visited[i] == false)
            Dfs(i);
}
int main()
{
    CreateGraph();
    visited = vector<bool>(6, false);
    DfsAll();
}