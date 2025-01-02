#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;

void bfs2(int start, vector<int>& distance, vector<int>& parent) {
    distance = vector<int>(adj.size(),-1);
    parent = vector<int>(adj.size(),-1);
    queue<int> q;
    distance[start] = 0;
    parent[start] = start;
    q.push(start);

    while(!q.empty()) {
        int here = q.front();
        q.pop();
        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i];
            if(distance[there] == -1){
                distance[there] = distance[here]+1;
                q.push(there);
                parent[there] = here;
            }
        }
    }
}