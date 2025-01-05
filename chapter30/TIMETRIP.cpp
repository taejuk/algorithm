#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int v;
const int MAX_V = 1000;
const int INF = 10000000;
vector<pair<int, int>> adj[MAX_V];

// src는 항상 0이다.
bool isReachable(int src, int dst) {
    vector<bool> reachable(v, false);
    reachable[src] = true;
    queue<int> q;
    q.push(src);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            if(there == dst) return true;
            if(!reachable[there]) {
                reachable[there] = true;
                q.push(there);
            }
        }
    }
    return false;
}
void timetrip(int src, int dst) {
    if(!isReachable(src,dst)) {
        cout << "UNREACHABLE" << endl;
        return;
    }
    vector<int> upper(v, INF);
    vector<int> lower(v, -INF);
    bool updatedUpper, updatedLower;
    upper[src] = 0;
    lower[src] = 0;

    for(int iter = 0; iter < v; iter++) {
        updatedUpper = false;
        updatedLower = false;
        for(int here = 0; here < v; here++) {
            for(int i = 0; i < adj[here].size(); i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                if(upper[there] > cost + upper[here]) {
                    updatedUpper = true;
                    upper[there] = cost + upper[here];
                }
                if(lower[there] < cost + lower[here]) {
                    updatedLower = true;
                    lower[there] = cost + lower[here];
                }
            }
        }
        if(!updatedLower && !updatedUpper) break;
    }
    if(updatedUpper) cout << "INF";
    else cout << upper[dst];
    cout << " ";
    if(updatedLower) cout << "INF";
    else cout << lower[dst];
    cout << endl;
    return;
}

int main() {
    int c;
    cin >> c;
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < MAX_V; j++) adj[j].clear();
        int e,a,b,c;
        cin >> v >> e;
        for(int j = 0; j < e; j++) {
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(b,c));
        }
        timetrip(0,1);
    }
}