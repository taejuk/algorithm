#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

int graph[26][26];

vector<int> first_start;
// a = is, b = iss인 경우에는 -1을 반환한다.
int findDifPos(string a, string b) {
    int len = a.length() < b.length() ? a.length() : b.length();
    int ret = -1;
    for(int i = 0; i < len; i++) {
        if(a[i] != b[i]) {
            ret = i;
            break;
        }
    }
    return ret;
}
// d->s로 가는 경로가 있으면 false를 반환한다.


void dfs(int s, bool visited[26]) {
    visited[s] = true;
    for(int i = 0; i < 26; i++) {
        if(graph[s][i]) {
            dfs(i, visited);
        }
    }
}

void dfsprint(int s, bool visited[26]) {
    visited[s] = true;
    for(int i = 0; i < 26; i++) {
        if(graph[s][i] && !visited[i]) {
            dfsprint(i, visited);
        }
    }
    cout << static_cast<char>(s+'a');
}

bool isPossible(int s, int d) {
    bool visited[26];
    for(int i = 0; i < 26; i++) visited[i] = false;
    dfs(d, visited);
    if(visited[s]) return false;
    else return true;
}

void makeGraph(vector<string> words) {
    int len = words.size();
    for(int i = 1; i < len; i++) {
        string a = words[i-1];
        string b = words[i];
        int pos = findDifPos(a, b);
        if(pos == -1) continue;
        if(!isPossible(a[pos]-'a', b[pos]-'a')) {
            cout << "INVALID" << endl;
            exit(0);
        }
        first_start.push_back(a[pos]-'a');
        graph[a[pos]-'a'][b[pos]-'a'] = 1;
    }
}

void printGraph() {
    bool visited[26];
    for(int i = 0; i < 26; i++) visited[i] = false;
    for(int i = 0; i < first_start.size(); i++) {
        if(!visited[first_start[i]]) dfsprint(first_start[i], visited);
    }
    for(int i = 0; i < 26; i++) {
        if(!visited[i]) {
            dfsprint(i,visited);
        }
    }
}


int main() {
    memset(graph, 0, sizeof(graph));
    vector<string> words = {"gg", "kia", "lotte", "lg", "hanwha"};
    makeGraph(words);
    printGraph();
}