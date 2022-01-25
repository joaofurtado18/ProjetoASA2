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

void dfs(int vertex, map<int, vector<int>> graph)
{
    visited[vertex - 1] = true;
    count_vec[vertex - 1] += 1;
    int size = graph[vertex].size();
    for (int i = 0; i < size; i++)
        if (!visited[graph[vertex][i] - 1])
            dfs(graph[vertex][i], graph);
}

bool is_cyclic_aux(int u, int *count_vec, int vertices, map<int, vector<int>> graph)
{
    count_vec[u] = 1;

    int size = graph[u].size();
    for (int i = 0; i < size; i++)
    {
        int v = graph[u][i];

        if (count_vec[v] == 1)
            return true;

        if (count_vec[v] == 0 && is_cyclic_aux(v, count_vec, vertices, graph))
            return true;
    }

    count_vec[u] = 2;
    return false;
}

bool is_cyclic(int *count_vec, int vertices, map<int, vector<int>> graph)
{
    for (int i = 0; i < vertices; i++)
        if (count_vec[i] == 0)
            if (is_cyclic_aux(i, count_vec, vertices, graph))
                return true;

    return false;
}

// v1 -> v2
// v1 = origin, v2 = destination
map<int, vector<int>> addEdge(int v1, int v2, map<int, vector<int>> graph)
{
    graph[v1].push_back(v2);
    graph[v2];
    return graph;
}

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

map<int, vector<int>> transpose_graph(map<int, vector<int>> graph, map<int, vector<int>> transpose){
    map<int, vector<int>>::iterator it;

    for (it = graph.begin(); it != graph.end(); it++){
        int size = it->second.size();
        for (int i = 0; i < size; i++){
            transpose = addEdge(it->second[i], it->first, transpose);
        }
    }
    return transpose;
}

void results(map<int, vector<int>> graph, vector<int> vec){
    map<int, vector<int>> transpose;
    map<int, vector<int>>::iterator it;
    for (it = graph.begin(); it != graph.end(); it++){
        int size = it->second.size();
        if (size == 0 && count_vec[it->first-1] > 1){
            transpose[it->first];
        }
        for (int i = 0; i < size; i++){
            if (count_vec[it->first-1] > 1 && count_vec[it->second[i]-1]>1){
                transpose = addEdge(it->second[i], it->first, transpose);
                transpose[vec[i]+1];
            }
        }
    }
    for (it = transpose.begin(); it != transpose.end(); it++){
        if (it->second.empty())
            cout << it->first << " ";
    }
}


int main()
{
    int v1, v2, vertices, archs, b1, b2;
    vector<int> vec;
    map<int, vector<int>> graph;

    if (scanf("%d %d ", &v1, &v2) == 0)
    {
        cout << "0" << endl;
        return 0;
    }

    if (scanf("%d %d ", &vertices, &archs) == 0)
    {
        cout << "0" << endl;
        return 0;
    }

    visited = new bool[vertices];
    memset(visited, 0, sizeof(bool) * vertices);
    // graph input
    for (int i = 0; i < archs; i++)
    {
        if (scanf("%d %d ", &b1, &b2) == 0)
        {
            cout << "0" << endl;
            return 0;
        }
        graph = addEdge(b2, b1, graph);
    }

    count_vec = new int[vertices];
    memset(count_vec, 0, sizeof(int) * vertices);

    if (is_cyclic(count_vec, vertices, graph))
    {
        cout << "0" << endl;
        return 0;
    }

    memset(count_vec, 0, sizeof(int) * vertices);

    //reseting visited
    dfs(v1, graph);
    memset(visited, 0, sizeof(bool) * vertices);

    dfs(v2, graph);
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

    results(graph, vec);
    cout << endl;
    return 0;
}