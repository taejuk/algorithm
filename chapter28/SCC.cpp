#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<vector<int>> adj;
vector<int> sccId;
vector<int> discovered;

stack<int> st;
int sccCounter, vertexCounter;
// 정점 중 최소 발견 순서를 반환한다?
int scc(int here) {
    int ret = discovered[here] = vertexCounter++;

    st.push(here);
    for(int i = 0; i < adj[here].size(); ++i) {
        int there = adj[here][i];
        // 왜 scc(there)를 호출하는가?
        if(discovered[there] == -1) ret = min(ret, scc(there));
        else if(sccId[there] == -1) ret = min(ret, discovered[there]);
    }

    if(ret == discovered[here]) {
        while(true) {
            int t = st.top();
            st.pop();
            sccId[t] = sccCounter;
            if(t == here) break;
        }
        sccCounter++;
    }
    return ret;
}

vector<int> targanSCC() {
    sccId = discovered = vector<int>(adj.size(),-1);

    sccCounter = vertexCounter = 0;

    for(int i = 0; i < adj.size(); i++) if(discovered[i] == -1) scc(i);
    return sccId;
}
// spanning tree이니깐 root를 잡고 dfs로 가면서 부모 자식을 계속 비교하면서 하면 된다.
// 자식에 연결된 선의 수가 더 많으면 자식에 추가하고 부모에 연결된 수가 더 많으면 부모에 추가하면 된다. 
// spanning tree가 끝에 도달했다는 것은 어떻게 알 수 있는가?

int main() {
    ios::sync_with_stdio(false);
    int testcase = 0;
    cin >> testcase;
    int h,g;
    for(int i = 0; i < testcase; i++) {
        cin >> h >> g;
    }
}