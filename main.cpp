#include <iostream> 
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

//compilation: g++ -std=c++11 -O3 -Wall main.cpp -lm
// teste1 = 2 4
// teste2 = 2 
// teste3 = -
stack<int> s;

void dfs(int vertex, int size, int** m, bool visited[], stack<int> stack){
    visited[vertex-1] = true;
    cout << vertex << " ";
    for(int i = 0; i < size; i++){
        if(m[vertex-1][i] == 1 && !visited[i]){
            dfs(i+1, size, m, visited, stack);
        }
    }
    s.push(vertex);
    //return stack;
}

void dfs_transpose(int vertex, int size, int** m, bool visited[]){
    visited[vertex-1] = true;
    cout << "transpose "<<vertex << " ";
    for(int i = 0; i < size; i++){
        if(m[i][vertex-1] == 1 && !visited[i]){
            dfs_transpose(i+1, size, m, visited);
        }
    }
}

int main(){
    int v1,v2, vertices, archs, b1, b2;
    stack<int> stack;


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

    dfs(1, vertices, m, visited, stack);
    s.push(1);
    cout << endl;
    memset(visited, 0, sizeof(bool)*vertices);
    int numComponents = 0;

    while (!s.empty()){
        int vertex2 = s.top();
        cout << "stack" << vertex2 << endl;
        s.pop();
        if (!visited[vertex2-1]){
            printf("Component %d: ", numComponents);
            dfs_transpose(vertex2, vertices, m, visited);
            numComponents++;
            printf("\n");
        }
    }

    cout << endl;


}