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

int* count_vec;

void dfs_transpose(int vertex, int size, int** m, bool visited[]){
    visited[vertex-1] = true;
    count_vec[vertex-1] += 1;
    // cout << vertex << " ";
    for(int i = 0; i < size; i++){
        if(m[i][vertex-1] == 1 && !visited[i]){
            dfs_transpose(i+1, size, m, visited);
        }
    }
}

int main(){
    int v1,v2, vertices, archs, b1, b2;
    stack<int> stack;
    vector<int> vec;


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
    count_vec = new int[vertices];
    memset(count_vec, 0, sizeof(int)*vertices);

    for (int i = 0; i < archs; i++){
        if (scanf("%d %d", &b1, &b2) == 0){
            cout << "0";
            return 0;
        }
        m[b1-1][b2-1] = 1;
    }
    // cout << "dfs 1 ";
    dfs_transpose(v1, vertices, m, visited);
    // cout << "dfs 2 ";
    memset(visited, 0, sizeof(bool)*vertices);
    dfs_transpose(v2, vertices, m, visited);
    for (int i = 0; i < vertices; i++){
        if (count_vec[i] > 1){
            vec.push_back(i);
        }
    }
    const int size = vec.size();
    if (size == 0)
        cout << "-";
    for (int i = 0; i < size; i++){
        int sum = 0;
        for(int j = 0; j < size; j++){
            if (m[vec[i]][vec[j]] == 1){
                sum += 1;
                break;
            }
        }
        if (sum == 0){
            if(i == size-1)
                cout << vec[i]+1;
            else
                cout << vec[i]+1 << " ";
        }
        sum = 0;
    }

}