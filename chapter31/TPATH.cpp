#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;


const int MAX_V = 100;
int V=0;
// 점과 cost이다.
vector<pair<int,int>> adj[MAX_V];
int MIN = -1;
int INF = 987654321;

struct Disjoint {
    vector<int> parent, rank;

    Disjoint(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n,1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        if(parent[u] == u) return u;
        parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return ;
        if(rank[u] < rank[v]) swap(u,v);
        parent[v] = u;
        if(rank[u] == rank[v]) rank[u]++;
    }
};

pair<int,int> make_new(pair<int,int> base, int path) {
    if(path < base.first) return make_pair(path, base.second);
    else if(path > base.second) return make_pair(base.first, path);
    else return make_pair(base.first, base.second);
} 

int tpath() {
    int res = INF;
    bool visited[V][V];
    for(int i = 0; i < V; i++) 
        for(int j = 0; j < V; j++) visited[i][j] = false;
    // 현재 점과 이때까지 온 점들의 pair 값
    queue<pair<int, pair<int,int>>> q;
    // 0부터 시작하니깐 0과 연결된 점들을 다 넣자
    for(int i = 0; i < adj[0].size(); i++) {
        q.push(make_pair(adj[0][i].first,make_pair(adj[0][i].second,adj[0][i].second)));
        visited[0][adj[0][i].first] = true;
        visited[adj[0][i].first][0] = true;
    }

    while(!q.empty()) {
        pair<int, pair<int,int>> cur = q.front();
        // 매번 s를 넣는 대신에 동적계획법으로 풀 수 있는 방법이 없을까?
        int src = cur.first;
        pair<int, int> prev = cur.second;
        q.pop();
        if((cur.second.second - cur.second.first) >= res) continue;
        if(src == V-1) {
            res = cur.second.second - cur.second.first;
            continue;
        }
        for(int i = 0; i < adj[src].size(); i++) {
            int dest = adj[src][i].first;
            int cost = adj[src][i].second;
            if(!visited[src][dest]) q.push(make_pair(dest, make_new(cur.second,cost)));
            visited[src][dest] = true;
            visited[dest][src] = true;
        }
    }
    return res;
}

void init() {
    for(int i = 0; i < V; i++) adj[i].clear();
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        init();
        int E;
        int a,b,c;
        cin >> V >> E;
        for(int j = 0; j < E; j++) {
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(b,c));
            adj[b].push_back(make_pair(a,c));
        }
        cout << tpath() << endl;
    }

}