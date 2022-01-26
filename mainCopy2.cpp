#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

//compilation: g++ -std=c++11 -O3 -Wall main.cpp -lm
// teste1 = 2 4
// teste2 = 2
// teste3 = -

int *count_vec;
bool *visited;
int v1, v2, vertices, archs, b1, b2;
vector<int> vec;

struct Vertex
{
    vector<int> adj;
};

vector<Vertex> graph;

void dfs(int vertex)
{
    visited[vertex - 1] = true;
    count_vec[vertex - 1] += 1;
    int size = graph[vertex].adj.size();
    for (int i = 0; i < size; i++)
        if (!visited[graph[vertex].adj[i] - 1])
            dfs(graph[vertex].adj[i]);
}

bool is_cyclic_aux(int u)
{
    count_vec[u] = 1;

    int size = graph[u].adj.size();
    for (int i = 0; i < size; i++)
    {
        int v = graph[u].adj[i];

        if (count_vec[v] == 1)
            return true;

        if (count_vec[v] == 0 && is_cyclic_aux(v))
            return true;
    }

    count_vec[u] = 2;
    return false;
}

bool is_cyclic()
{
    for (int i = 0; i < vertices; i++)
        if (count_vec[i] == 0)
            if (is_cyclic_aux(i))
                return true;

    return false;
}

// v1 -> v2
// v1 = origin, v2 = destination
void addEdge(int v1, int v2)
{
    cout << "jsjs" << endl;
    graph[v1].adj.push_back(v2);
}

/*
void printGraph(map<int, vector<int>> graph)
{
    map<int, vector<int>>::iterator it;

    for (it = graph.begin(); it != graph.end(); it++)
    {

        cout << it->first;
        for (auto x : it->second)
            cout << "-> " << x;
        cout << endl;
    }
    cout << endl;
}

map<int, vector<int>> transpose_graph(map<int, vector<int>> graph, map<int, vector<int>> transpose)
{
    map<int, vector<int>>::iterator it;

    for (it = graph.begin(); it != graph.end(); it++)
    {
        int size = it->second.size();
        for (int i = 0; i < size; i++)
        {
            transpose = addEdge(it->second[i], it->first, transpose);
        }
    }
    return transpose;
}
*/

/*
void results()
{
    map<int, vector<int>> transpose;
    map<int, vector<int>>::iterator it;
    for (it = graph.begin(); it != graph.end(); it++)
    {
        int size = it->second.size();
        if (size == 0 && count_vec[it->first - 1] > 1)
        {
            transpose[it->first];
        }
        for (int i = 0; i < size; i++)
        {
            if (count_vec[it->first - 1] > 1 && count_vec[it->second[i] - 1] > 1)
            {
                transpose = addEdge(it->second[i], it->first, transpose);
                transpose[vec[i] + 1];
            }
        }
    }
    for (it = transpose.begin(); it != transpose.end(); it++)
    {
        if (it->second.empty())
            cout << it->first << " ";
    }
}
*/

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> v1 >> v2;
    cin >> vertices >> archs;

    visited = new bool[vertices];
    memset(visited, 0, sizeof(bool) * vertices);
    // graph input
    while (cin >> b1 >> b2)
    {
        addEdge(b2, b1);
    }
    cout << "aqui" << endl;

    count_vec = new int[vertices];
    memset(count_vec, 0, sizeof(int) * vertices);

    if (is_cyclic())
    {
        cout << "0" << endl;
        return 0;
    }

    memset(count_vec, 0, sizeof(int) * vertices);

    //reseting visited
    dfs(v1);
    memset(visited, 0, sizeof(bool) * vertices);

    dfs(v2);
    memset(visited, 0, sizeof(bool) * vertices);

    delete visited;

    for (int i = 0; i < vertices; i++)
    {
        // cout << count_vec[i] << " ";
        if (count_vec[i] > 1)
            vec.push_back(i);
    }
    // cout << endl;

    if (vec.size() == 0)
    {
        cout << "-" << endl;
        return 0;
    }

    //results();
    cout << endl;
    return 0;
}