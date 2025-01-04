#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int INF = INT_MAX;
int best = INF;

int max_m = 500;
vector<pair<int,int>> adj;
map<pair<int,int>,int> cache;
int NTHLON() {
    // 일단 pair에 대해 다 같은 방향이면 false를 반환해야 한다.
    bool pos = false;
    int sgn = adj[0].first - adj[0].second;
    for(int i = 1; i < adj.size(); i++) {
        if(sgn * (adj[i].first - adj[i].second) <= 0) pos = true;
    }
    if(!pos) return -1;
    priority_queue<pair<int,int>> pq;

    for(int i = 0; i < adj.size(); i++) {
        pq.push(make_pair(adj[i].first, adj[i].second));
    }

    while(!pq.empty()) {
        pair<int, int> here = pq.top();
        pq.pop();
        if(-here.first >= best || -here.second >= best) continue;
        if(here.first == here.second) {
            best = -here.first;
            continue;
        }
        if(cache.count(here)) continue;
        cache[here] = 1;
        for(int i = 0; i < adj.size(); i++) {
            if((here.first-here.second)*(adj[i].first - adj[i].second) < 0)
            pq.push(make_pair(here.first + adj[i].first,here.second + adj[i].second));
        }
    }


    return best;
}

int main() {
    int c;
    cin >> c;
    for(int i = 0; i < c ; i++) {
        int m;
        cin >> m;
        int a,b;
        for(int j = 0; j < m; j++) {
            cin >> a >> b;
            adj.push_back(make_pair(-a,-b));
        }
        int ret = NTHLON();
        if(ret == -1) cout << "IMPOSSIBLE" << endl;
        else cout << ret << endl;
    }
}