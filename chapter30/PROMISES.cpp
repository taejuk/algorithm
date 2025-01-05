#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
using namespace std;

int adj[200][200];
int V;
const int INF = 1000000;

void init() { 
    for(int i = 0; i < 200; i++)
        for(int j = 0; j < 200; j++){
            adj[j][i] = INF;
            adj[i][j] = INF;
        }
    for(int i = 0; i < 200; i++) adj[i][i] = 0;
}

void floyd() {
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
}

bool update(int a, int b, int c) {
    if(adj[a][b] <= c) return false;
    adj[a][b] = c;
    adj[b][a] = c;
    for(int i = 0 ; i < V; i++) {
        for(int j = 0; j < V; j++) {
            adj[i][j] = min(adj[i][j], adj[i][a] + c + adj[b][j]);
            adj[i][j] = min(adj[i][j], adj[i][b] + c + adj[a][j
            ]);
        }
    }
}

int main() {
    int c;
    cin >> c;
    for(int i = 0; i < c; i++) {
        int ret = 0;
        int m,n,a,b,c;
        cin >> V >> m >> n;
        init();
        for(int j = 0; j < m; j++) {
            cin >> a >> b >> c;
            adj[a][b] = c;
            adj[b][a] = c;
        }
        // floyd 알고리즘 한 번 실행하고
        floyd();
        for(int j = 0; j < m; j++) {
            cin >> a >> b >> c;
            if(!update(a,b,c)) ret++;
        }
        cout << ret << endl;
    }
}