#include <iostream> 
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;

//compilation: g++ -std=c++11 -O3 -Wall main.cpp -lm
/*1 2
  5 7
  1 0
  1 4
  1 3
  1 2
  0 4
  4 3
  3 2*/

void dfs(int vertex, int size, int** m, bool* visited){
    visited[vertex] = true;
    cout << vertex << " ";
    for(int i = 0; i < size; i++){
        if(m[vertex][i] == 1 && !visited[i]){
            dfs(i, size, m, visited);
        }
    }
}




int main(){
    int v1,v2, vertices, archs, b1, b2;


    if (scanf("%d %d", &v1,&v2) == 0){
        cout << "0";
        return 0;
    }
    if (scanf("%d %d", &vertices,&archs) == 0){
        cout << "0";
        return 0;
    }
    bool visited[vertices];
    int** m = new int*[vertices];
    for (int i = 0; i < vertices; i++){
        m[i] = new int[vertices];
        memset(m[i], 0, sizeof(int)*vertices);
    }
    memset(visited, 0, sizeof(bool)*vertices);


    for (int i = 0; i < archs; i++){
        if (scanf("%d %d", &b1, &b2) == 0){
            cout << "0";
            return 0;
        }
        m[b1][b2] = 1;
    }

    dfs(1, vertices, m, visited);

    cout << endl;


}