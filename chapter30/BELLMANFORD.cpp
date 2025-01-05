#include <iostream>
#include <vector>
#define MAX_V 1000;
using namespace std;

int V;
int INF;
vector<pair<int,int>> adj[1000];

vector<int> bellmanford(int src) {
    // INT_MAX로 하면 overflow 나니깐 다른 수로 해야 한다.
    vector<int> upper(V, INF);
    upper[src] = 0;
    bool updated;
    for(int iter = 0; iter < V; iter++) {
        updated = false;
        for(int here = 0; here < V; here++) {
            for(int i = 0; i < adj[here].size(); i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;

                if(upper[there] > upper[here] + cost) {
                    updated = true;
                    upper[there] = upper[here] + cost;
                }
            }
        }
        if(!updated) break;
    }
    if(updated) upper.clear();
    return upper;
}

