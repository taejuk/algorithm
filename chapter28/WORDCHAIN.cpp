#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <string>
using namespace std;


int adj[100][100];
vector<string> words;
vector<int> ordered;


// graph를 만들었으면 

// dfs로 방문하면서 
// dfs: 이 노드로부터 시작해서 한번만에 방문할 수 있는 점들의 집합
void dfs(int curPos, bool visited[100], vector<int>& ordered) {
    visited[curPos] = true;
    ordered.push_back(curPos);\
    vector<int> ret = ordered;
    for(int i = 0; i < words.size(); i++) {
        if(!visited[i] && adj[curPos][i]) {
            vector<int> newordered = ordered;
            bool newvisited[100];
            for(int i = 0; i < 100; i++) newvisited[i] = visited[i];
            dfs(i, newvisited,newordered);
            if(newordered.size() < ret.size()) ret = newordered; 
        }
    }
    if(ret.size() == words.size())
    for(int i = 0; i < ret.size(); i++) {
        cout << words[ret[i]] << " ";
    }
}


void makeGraph() {
    int len = words.size();
    for(int i = 0 ; i < len ; i++) {
        for(int j = i+1; j < len; j++) {
            // i번째 마지막 글자와 j번째 첫번째 글자가 같으면 그래프를 추가하고
            if(words[i][0] == words[j][words[j].length()-1]) adj[j][i] = 1;
            // j번째 마지막 글자와 i번째 첫번째 글자가 같으면 그래프를 추가한다.
            if(words[j][0] == words[i][words[i].length()-1]) adj[i][j] = 1;
        }
    }
}



int main() {
    memset(adj, 0, sizeof(adj));
    words.push_back("dog");
    words.push_back("god");
    words.push_back("dragon");
    words.push_back("need");
    makeGraph();
    bool visited[100];
    for(int i = 0; i < 100; i++) visited[i] = false;
    vector<int> ordered;
    dfs(0, visited, ordered);
}   