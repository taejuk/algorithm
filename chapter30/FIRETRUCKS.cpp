#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int V=0;
const int MAX_V = 10000;
const int INF = INT_MAX;
vector<pair<int,int>> adj[MAX_V];
vector<int> dijkstr(vector<int> src) {
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < src.size(); i++) {
        pq.push(make_pair(0, src[i]));
    }

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if(nextDist < dist[there]) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            } 
        } 
    }
    return dist;
}

int main() {
    int c;
    cin >> c;
    for(int i = 0; i < c; i++) {
        vector<int> src;
        vector<int> fire;
        int VL,E,n,m;
        cin >> VL >> E >> n >> m;
        V = VL + 1;
        for(int j = 0; j < E; j++) {
            int a,b,c;
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(b,c));
            adj[b].push_back(make_pair(a,c));
        }
        for(int j = 0; j < n; j++) {
            int a;
            cin >> a;
            fire.push_back(a);
        }
        for(int j = 0; j < m; j++) {
            int a;
            cin >> a;
            src.push_back(a);
        }

        vector<int> dist;
        dist = dijkstr(src);
        int ret = 0;
        for(int j = 0; j < fire.size(); j++) {
            ret += dist[fire[j]];
        }
        cout << ret << endl;
    }
}