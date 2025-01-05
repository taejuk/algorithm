#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
using namespace std;
int v;
int adj[500][500];
int drunken[500];
int W[500][500];
int INF = 100000;
// 그냥 floyd 알고리즘을 한 번 실행하고 나서 
// k에 대한 경우를 다 고려하면 되는가?
// 도착했을 때, 
void solve() {
    vector<pair<int,int>> order;
    for(int i = 0; i < v; i++) {
        order.push_back(make_pair(drunken[i],i));
    }
    sort(order.begin(), order.end());
    for(int i = 0; i < v ; i++) {
        for(int j = 0; j < v; j++) {
            W[i][j] = adj[i][j];
        }
    }
    for(int k = 0; k < v; k++) {
        int w = order[k].second;
        for(int i = 0; i < v ; i++) {
            for(int j = 0; j < v; j++) {
                adj[i][j] = min(adj[i][j], adj[i][w]+adj[w][j]);
                W[i][j] = min(W[i][j], adj[i][w]+adj[w][j]+drunken[w]);
            }
        }
    }
}

int main() {
    int e;
    for(int i = 0; i < 501; i++) {
        for(int j = 0; j < 501; j++) adj[i][j] = INF;
    }
    cin >> v >> e;
    for(int i = 0; i < v; i++) adj[i][i] = 0;
    
    for(int i = 0; i < v; i++) {
        int n;
        cin >> n;
        drunken[i] = n;    
    }
    int a,b,c;
    for(int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        adj[a-1][b-1] = c;
        adj[b-1][a-1] = c;
    }
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> a >> b;
        cout << W[a-1][b-1] << endl;
    }
    
}

// 8 12
// 8 6 5 8 3 5 8 4
// 1 6 9
// 1 2 3
// 2 8 3
// 6 8 5
// 6 7 3
// 8 7 3
// 6 5 5
// 4 5 7
// 3 4 4
// 3 5 2
// 2 3 6
// 7 5 1