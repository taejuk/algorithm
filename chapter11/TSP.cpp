#include <vector>
#include <algorithm>
using namespace std;

const double INF = 1e200;
const int MAX = 30;
int n;
double dist[MAX][MAX];

double best;

void search(vector<int>& path, vector<bool>& visited, double curLength) {
    if(curLength >= best) return;
    int here = path.back();
    if(path.size() == n) {
        best = min(best, curLength + dist[here][0]);
        return;
    }

    for(int i = 0; i < n; i++) {
        if(visited[i]) continue;
        path.push_back(i);
        visited[i] = true;
        search(path, visited, curLength + dist[here][i]);
        visited[i] = false;
        path.pop_back();
    }
}
