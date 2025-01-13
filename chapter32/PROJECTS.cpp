// 제품을 최대 m개 선택한다고 할 때로 보면 되는가?
#include <queue>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

const int MAX_V = 100;
const int INF = 987654321;
int V;

int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

int networkFlow(int source, int sink) {
    memset(flow, 0, sizeof(flow));
    int totalFlow = 0;
    while(true) {
        vector<int> parent(MAX_V,-1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        while(!q.empty() && parent[sink]==-1) {
            int here = q.front(); q.pop();
            for(int there = 0; there < V; there++) {
                if(capacity[here][there] - flow[here][there] > 0 && parent[there]==-1) {
                    parent[there] = here;
                    q.push(there);
                }
            }
        }
        if(parent[sink]==-1) break;
        int amount = INF;
        for(int p = sink; p != source; p = parent[p]) {
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }
        for(int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow+=amount;
    }

    return totalFlow;
}