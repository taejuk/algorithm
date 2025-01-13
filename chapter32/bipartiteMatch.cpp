#include <vector>
using namespace std;
const int MAX_N = 100, MAX_M = 100;

int n,m;
bool adj[MAX_N][MAX_M];

vector<int> aMatch, bMatch;

vector<bool> visited;

bool dfs(int a) {
    if(visited[a]) return false;
    visited[a] = true;

    for(int b = 0; b<m;b++) {
        if(adj[a][b]) {
            if(bMatch[b] == -1 || dfs(bMatch[b])) {
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
        }
    }
    return false;
}

int bipartiteMatch() {
    aMatch = vector<int>(n,-1);
    bMatch = vector<int>(m,-1);
    int size = 0;
    for(int start = 0; start < n; start++) {
        visited = vector<bool>(n, false);
        if(dfs(start)) size++;
    }
    return size;
}