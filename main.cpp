#include <iostream> 
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;

//compilation: g++ -std=c++11 -O3 -Wall main.cpp -lm

void dfs(int vertex, int size, int** m, bool* visited){
    visited[vertex-1] = true;
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
        m[b1-1][b2-1] = 1;
    }

    dfs(m[0][0], vertices, m, visited);




}