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

typedef struct node_s
{
    int id;
    vector<int> adj;
} node;

int *count_vec;
bool *visited;
node *graph;
node *res_graph;
map<int, vector<int>> transpose;

void dfs(int vertex)
{
    visited[vertex - 1] = true;
    count_vec[vertex - 1] += 1;
    int size = graph[vertex - 1].adj.size();
    for (int i = 0; i < size; i++)
        if (!visited[graph[vertex - 1].adj[i] - 1])
            dfs(graph[vertex - 1].adj[i]);
}

bool is_cyclic_aux(int vertex, int vertices)
{
    count_vec[vertex] = 1;

    int size_adj = graph[vertex].adj.size();
    for (int i = 0; i < size_adj; i++)
    {
        int v = graph[vertex].adj[i] - 1;

        if (count_vec[v] == 1)
            return true;

        if (count_vec[v] == 0 && is_cyclic_aux(v, vertices))
            return true;
    }

    count_vec[vertex] = 2;
    return false;
}

bool is_cyclic(int vertices)
{
    for (int i = 0; i < vertices; i++)
        if (count_vec[i] == 0)
            if (is_cyclic_aux(i, vertices))
                return true;

    return false;
}

void addEdge(int v1, int v2, node **graph_add)
{
    (*graph_add)[v1 - 1].adj.push_back(v2);
    (*graph_add)[v1 - 1].id = v1;
    (*graph_add)[v2 - 1].id = v2;
}

void printGraph(node *graph_print, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {

        cout << graph_print[i].id;
        for (auto x : graph_print[i].adj)
            cout << "-> " << x;
        cout << endl;
    }
    cout << endl;
}

void results(vector<int> vec, int vertices, int size)
{
    for (int i = 0; i < vertices; i++)
    {
        int size2 = graph[i].adj.size();
        if (size2 == 0 && count_vec[i] > 1)
            transpose[graph[i].id];

        for (int j = 0; j < size2; j++)
        {
            if (count_vec[i] > 1 && count_vec[graph[i].adj[j] - 1] > 1)
            {
                transpose[graph[i].adj[j]].push_back(graph[i].id);
                transpose[graph[i].id];
            }
        }
    }
    // printGraph(res_graph, size);
    map<int, vector<int>>::iterator it;
    for (it = transpose.begin(); it != transpose.end(); it++)
    {
        //if (it->second.empty())
          //  cout << it->first << " ";
    }
}

int main()
{
    int v1, v2, vertices, archs, b1, b2;
    vector<int> vec;

    if (scanf("%d %d ", &v1, &v2) == 0)
    {
        //cout << "0" << endl;
        return 0;
    }

    if (scanf("%d %d ", &vertices, &archs) == 0)
    {
        //cout << "0" << endl;
        return 0;
    }
    cout << vertices + archs;

    visited = new bool[vertices];
    graph = new node[vertices];
    memset(visited, 0, sizeof(bool) * vertices);
    // graph input
    for (int i = 0; i < archs; i++)
    {
        if (scanf("%d %d ", &b1, &b2) == 0)
        {
            //cout << "0" << endl;
            return 0;
        }
        addEdge(b2, b1, &graph);
    }

    count_vec = new int[vertices];
    memset(count_vec, 0, sizeof(int) * vertices);

    if (is_cyclic(vertices))
    {
        //cout << "0" << endl;
        return 0;
    }

    memset(count_vec, 0, sizeof(int) * vertices);

    dfs(v1);
    memset(visited, 0, sizeof(bool) * vertices);

    dfs(v2);
    memset(visited, 0, sizeof(bool) * vertices);

    for (int i = 0; i < vertices; i++)
    {
        if (count_vec[i] > 1)
        {
            vec.push_back(i);
        }
    }

    const int size = vec.size();
    if (size == 0)
    {
        //cout << "-" << endl;
        return 0;
    }
    res_graph = new node[size];

    results(vec, vertices, size);
    //cout << endl;
    return 0;
}
