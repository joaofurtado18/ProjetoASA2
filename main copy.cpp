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

int *count_vec;
bool *visited;

void dfs(int vertex,  map<int, vector<int>> graph){
    visited[vertex - 1] = true;
    count_vec[vertex - 1] += 1;
    int size = graph[vertex].size();
    for (int i = 0; i < size; i++)
        if (!visited[graph[vertex][i]-1])
            dfs(graph[vertex][i], graph);
}

// v1 -> v2
// v1 = origin, v2 = destination
 map<int, vector<int>> addEdge(int v1, int v2, map<int, vector<int>> graph){
    graph[v1].push_back(v2);
    return graph;
}

void printGraph(map<int, vector<int>> graph)
{
    map<int, vector<int>>::iterator it;

    for (it = graph.begin(); it != graph.end(); it++){

        cout << it->first;
        for (auto x : it->second)
            cout << "-> " << x;
        cout << endl;
    }
    cout << endl;
}

void deliver_results(vector<int> vec, map<int, vector<int>> graph){
    vector<int> aux_vec(vec);
    vector<int>::iterator ptr;
    vector<int>::iterator ptr2;
    for (ptr = vec.begin(); ptr < vec.end(); ptr++){
        // cout <<"i: " << *ptr+1 <<"{ "<<endl;
        for (ptr2 = vec.begin(); ptr2 < vec.end();ptr2++){
            // cout << i;
            // cout <<"\tj: " << *ptr2+1 << endl;
            if (find(graph[*ptr+1].begin(), graph[*ptr+1].end(), *ptr2+1) != graph[*ptr+1].end()){
                // cout << endl<< "achou " << *ptr2+1 << " em " << *ptr+1;
                aux_vec.erase(std::remove(aux_vec.begin(), aux_vec.end(), *ptr2), aux_vec.end());
            }
        }
        // cout << "}"<< endl;
    }
    // cout << endl;
    for(int i = 0; i < (int)aux_vec.size(); i++){
        cout << aux_vec[i] + 1 << " ";
    }
}


int main()
{
    int v1, v2, vertices, archs, b1, b2;
    vector<int> vec;
    map<int, vector<int>> graph;

    if (scanf("%d %d ", &v1, &v2) == 0){
        cout << "0" << endl;
        return 0;
    }

    if (scanf("%d %d ", &vertices, &archs) == 0){
        cout << "0" << endl;
        return 0;
    }

    visited = new bool[vertices];
    memset(visited, 0, sizeof(bool) * vertices);

    // graph input
    for (int i = 0; i < archs; i++){
        if (scanf("%d %d ", &b1, &b2) == 0){
            cout << "0" << endl;
            return 0;
        }
        graph = addEdge(b2, b1, graph);
    }

    count_vec = new int[vertices];
    memset(count_vec, 0, sizeof(int) * vertices);
    
    //reseting visited
    dfs(v1, graph);
    memset(visited, 0, sizeof(bool) * vertices);

    dfs(v2, graph);
    memset(visited, 0, sizeof(bool) * vertices);

    delete visited;

    for (int i = 0; i < vertices; i++){
        // cout << count_vec[i] << " ";
        if (count_vec[i] > 1)
            vec.push_back(i);
    }
    // cout << endl;

    if (vec.size() == 0){
        cout << "-" << endl;
        return 0;
    }

    deliver_results(vec, graph);
    cout << endl;
    printGraph(graph);
    return 0;
}