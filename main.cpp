#include <iostream> 
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;

//compilation: g++ -std=c++11 -O3 -Wall main.cpp -lm

int main(){
    int v1,v2, vertices, archs, b1, b2;

    vector<int> v;
    if (scanf("%d %d", &v1,&v2) == 0){
        cout << "0";
        return 0;
    }
    if (scanf("%d %d", &vertices,&archs) == 0){
        cout << "0";
        return 0;
    }
    int** m = new int*[vertices];

    for (int i = 0; i < vertices; i++){
        m[i] = new int[vertices];
        memset(m[i], 0, vertices);
    }

    for (int i = 0; i < archs; i++){
        if (scanf("%d %d", &b1, &b2) == 0){
            cout << "0";
            return 0;
        }
        m[b1-1][b2-1] = 1;
    }
    cout << endl;
    cout << v1 << endl << v2 << endl << vertices << endl << archs << endl << endl;
    for (int i = 0; i < 2*archs; i++){
        cout << v[i] << endl;
    }
}