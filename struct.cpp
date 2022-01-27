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

typedef struct node_s{
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
    // cout << vertex << " ";
    int size = graph[vertex-1].adj.size();
    for (int i = 0; i < size; i++)
        if (!visited[graph[vertex-1].adj[i] - 1])
            dfs(graph[vertex-1].adj[i]);
}

bool is_cyclic_aux(int u, int *count_vec, int vertices)
{
    count_vec[u] = 1;

    int size = graph[u].adj.size();
    for (int i = 0; i < size; i++)
    {
        int v = graph[u].adj[i];

        if (count_vec[v] == 1)
            return true;

        if (count_vec[v] == 0 && is_cyclic_aux(v, count_vec, vertices))
            return true;
    }

    count_vec[u] = 2;
    return false;
}

bool is_cyclic(int *count_vec, int vertices)
{
    for (int i = 0; i < vertices; i++)
        if (count_vec[i] == 0)
            if (is_cyclic_aux(i, count_vec, vertices))
                return true;

    return false;
}

// v1 -> v2
// v1 = origin, v2 = destination
void addEdge(int v1, int v2, node** graph_add)
{
    (*graph_add)[v1-1].adj.push_back(v2);
    (*graph_add)[v1-1].id = v1;
    (*graph_add)[v2-1].id = v2;
}

void printGraph(node* graph_print, int vertices){
    for (int i = 0; i < vertices; i++)
    {

        cout << graph_print[i].id;
        for (auto x : graph_print[i].adj)
            cout << "-> " << x;
        cout << endl;
    }
    cout << endl;
}

void results(vector<int> vec, int vertices, int size){
    for (int i = 0; i < vertices; i++){
        int size2 = graph[i].adj.size();
        if (size2 == 0 && count_vec[i] > 1){
            // cout << "size: "  << size << " i: " << i << " id dos adj = 0: " << graph[i].id << endl;
            transpose[graph[i].id];
        }
        // cout << "res: " << endl;
        // printGraph(res_graph, size);
        // cout << endl;
        for (int j = 0; j < size2; j++){
            if (count_vec[i] > 1 && count_vec[graph[i].adj[j]-1]>1){
                // cout << "i: " << i<< " adicionou " << graph[i].adj[j] << " -> " << graph[i].id <<  "e: " << vec[j]+1<< endl;
                transpose[graph[i].adj[j]].push_back(graph[i].id);
                transpose[graph[i].id];
            }
        }
    }
    // printGraph(res_graph, size);
    map<int, vector<int>>::iterator it;
    for (it = transpose.begin(); it != transpose.end(); it++){
        if (it->second.empty())
            cout << it->first << " ";
    }
}

void printGraph2(map<int, vector<int>> graph)
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
int main()
{
    int v1, v2, vertices, archs, b1, b2;
    vector<int> vec;

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
    graph = new node[vertices];
    memset(visited, 0, sizeof(bool) * vertices);
    // graph input
    for (int i = 0; i < archs; i++)
    {
        if (scanf("%d %d ", &b1, &b2) == 0)
        {
            cout << "0" << endl;
            return 0;
        }
        addEdge(b2, b1, &graph);
    }

    count_vec = new int[vertices];
    memset(count_vec, 0, sizeof(int) * vertices);

    // if (is_cyclic(count_vec, vertices))
    // {
    //     cout << "0" << endl;
    //     return 0;
    // }

    memset(count_vec, 0, sizeof(int) * vertices);

    //reseting visited
    // cout << "dfs1 ";
    dfs(v1);
    // cout << endl;
    memset(visited, 0, sizeof(bool) * vertices);
    // cout << "dfs2 ";
    dfs(v2);
    // cout << endl;
    memset(visited, 0, sizeof(bool) * vertices);

    // delete visited;

    // cout << "count_vec ";
    for (int i = 0; i < vertices; i++)
    {
        // cout << count_vec[i] << " " << endl << "i: " << i << endl;
        if (count_vec[i] > 1){
            vec.push_back(i);
        }
    }
    // cout << endl;
    // for (int i = 0; i < (int) vec.size(); i++){
    // cout << "pushback: " << vec[i] << endl;
        
    // }

    const int size = vec.size();
    if (size == 0){
        cout << "-" << endl;
        return 0;
    }
    res_graph = new node[size];
    // printGraph(res_graph, size);

    // printGraph(graph, vertices);
    results(vec, vertices, size);
    // printGraph2(transpose);
    cout << endl;
    return 0;
}