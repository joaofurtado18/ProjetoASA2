#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include<map>

using namespace std;

//compilation: g++ -std=c++11 -O3 -Wall main.cpp -lm
// teste1 = 2 4
// teste2 = 2
// teste3 = -

typedef struct graph{
    int num;
    vector<int> adj;
} node;

int *count_vec;
bool *visited, *recStack;
map<int, vector<int>> graph;
// bool isCyclicAux(int j, int vertices, bool visited[], bool recStack[], int **m)
// {
//     if (visited[j] == false)
//     {
//         visited[j] = true;
//         recStack[j] = true;

//         for (int i = 0; i < vertices; i++)
//         {
//             if (m[j][i] == 1 && !visited[m[j][i]] && isCyclicAux(i, vertices, visited, recStack, m))
//                 return true;
//             else if (recStack[i])
//                 return true;
//         }
//     }
//     recStack[j] = false;
//     return false;
// }

// bool is_cyclic(bool visited[], bool recStack[], int vertices, int **m)
// {
//     for (int i = 0; i < vertices; i++)
//     {
//         visited[i] = false;
//         recStack[i] = false;
//     }

//     for (int i = 0; i < vertices; i++)
//         if (isCyclicAux(i, vertices, visited, recStack, m))
//             return true;
            
//     return false;
// }


void dfs_transpose(int vertex,  map<int, vector<int>> graph, bool visited[])
{
    visited[vertex - 1] = true;
    count_vec[vertex - 1] += 1;
    vector<int>::iterator i;
    for (i = graph[vertex].begin(); i != graph[vertex].end(); i++)
        if (!visited[*i-1])
            dfs_transpose(*i, graph, visited);
}

// v1 -> v2
// v1 = origin, v2 = destination
void addEdge(int v1, int v2){
    graph[v1].push_back(v2);
}

void printGraph(map<int, vector<int>> graph)
{
    map<int, vector<int>>::iterator it;
    for (it = graph.begin(); it != graph.end(); it++){

        for(int i = 0; i < (int) it->second.size();i++){
        }
    }
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



    // visited and recStack
    visited = new bool[vertices];
    recStack = new bool[vertices];
    memset(visited, 0, sizeof(bool) * vertices);

    for (int i = 0; i < archs; i++)
    {
        if (scanf("%d %d ", &b1, &b2) == 0)
        {
            cout << "0" << endl;
            return 0;
        }

        addEdge(b2, b1);
    }
    // if (is_cyclic(visited, recStack, vertices, m)){
    //     cout << "0" << endl;
    //     return 0;
    // }

    // freeing memory;
    // delete recStack;

    count_vec = new int[vertices];
    memset(count_vec, 0, sizeof(int) * vertices);
    
    //reseting visited
    
    memset(visited, 0, sizeof(bool) * vertices);
    dfs_transpose(v1, graph, visited);
    //reseting visited again

    memset(visited, 0, sizeof(bool) * vertices);
    dfs_transpose(v2, graph, visited);

    delete visited;
    

    for (int i = 0; i < vertices; i++)
    {
        if (count_vec[i] > 1)
            vec.push_back(i);
    }
    const int size = vec.size();

    if (size == 0){
        cout << "-" << endl;
        return 0;
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (find(graph[vec[i]+1].begin(), graph[vec[i]+1].end(), j+1) != graph[vec[i+1]].end())
            {
                vec.erase(vec.begin() + j);
                break;
            }
        }
    }
    for(int i = 0; i < (int)vec.size(); i++){
        if (i == (int)vec.size() - 1)
            cout << vec[i] + 1;
        else
            cout << vec[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}