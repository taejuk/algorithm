#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct DisjointSet {
    vector<int> parent, rank, prefer;
    DisjointSet(int n): parent(n), rank(n,1), prefer(n,0) {
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return true;
        if(prefer[u] && prefer[v] && prefer[u] != prefer[v]) return false;
        if(rank[u] > rank[v]) swap(u,v);
        parent[u] = v;
        if(prefer[v] == 0 && prefer[u] != 0) prefer[v] = prefer[u];
        if(rank[u] ==  rank[v]) rank[v]++;
        return true;
    }
    bool dis(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return false;
        if(prefer[u] && prefer[v] && prefer[u] != prefer[v]) return false;
        if(!prefer[u] && !prefer[v]) {
            prefer[u] = 1;
            prefer[v] = -1;
        } else {
            if(prefer[u]) prefer[v] = -1 * prefer[u];
            else prefer[u] = -1 * prefer[v];
        }
        return true;
    }
    int findmax() {
        int l = 0,m = 0,r = 0;
        for(int i = 0; i < prefer.size(); i++) {
            if(prefer[i] == -1) l++;
            else if(prefer[i] == 0) m++;
            else r++;
        }
        return l > r ? l+m : r+m;
    }
};


int main() {
    int c;
    cin >> c;
    for(int i = 0; i < c; i++) {
        int n, m;
        cin >> n >> m;
        
        string a;
        int b,c;
        DisjointSet sets(n);
        int contra = -1;
        for(int j = 0; j < m; j++) {
            cin >> a >> b >> c;
            if(contra == -1) {
                if(a.compare("ACK") == 0) {
                    bool ret = sets.merge(b,c);
                    if(!ret) contra = j+1;
                } else {
                    bool ret = sets.dis(b,c);
                    if(!ret) contra = j+1;
                }
            }
        }

        if(contra == -1) cout << "MAX PARTY SIZE IS " << sets.findmax() << endl;
        else cout << "CONTRADICTION AT " << contra << endl;
    }
}