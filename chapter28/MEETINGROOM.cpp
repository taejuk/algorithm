#include <vector>

using namespace std;

vector<vector<int>> adj;

bool disjoint(const pair<int,int>& a, const pair<int, int>& b) {
    return a.second <= b.first || b.second <= a.first;
}
void makeGraph(const vector<pair<int,int>>& meetings) {
    int vars = meetings.size();
    adj.clear();
    adj.resize(vars*2);
    for(int i = 0; i < vars; i+=2) {
        int j = i + 1;
        adj[2*i + 1].push_back(2*j);
        adj[2*j+1].push_back(2*i);
    }
    for(int i = 0; i < vars; i++) {
        for(int j = 0; j < i; j++) {
            if(!disjoint(meetings[i], meetings[j])) {
                adj[2*i].push_back(2*j+1);
                adj[2*j].push_back(2*i+1);
            }
        }
    }
}