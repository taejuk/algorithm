#include <vector>
#include <iostream>
using namespace std;
const int MAX_N = 200, MAX_M = 200,MAX_SIZE = 10;
int s;
int n,m;
int board[MAX_SIZE][MAX_SIZE];
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

int getNum(int i, int j) {return i*s+j;}

void makeAdj() {
    n = s*s;
    m = s*s;
    int num;
    int dx, dy;
    int dir[4][2] = {{-1,-1},{1,-1}, {-1,1}, {1,1}};
    for(int i = 0; i < s; i++) {
        for(int j = 0; j < s; j++) {
            if(board[i][j] == 0) {
                adj[getNum(i,j)][getNum(i,j)] = true; 
                for(int k = 0; k < 4; k++) {

                }
            }
        }
    }
}

int main() {
    int c;
    cin >> c;
    string status;
    for(int i = 0; i < c; i++) {
        cin >> s;
        memset(adj, false, sizeof(adj));
        for(int j = 0; j < s; j++) {
            cin >> status;
            for(int k = 0; k < s; k++) {
                if(status[k]=='.') board[j+1][k+1] = 0;
                else board[j+1][k+1] = 1;
            }
        }
        for(int j = 0; j < s+2; j++) {
            board[0][j] = 1;
            board[s+1][j] = 1;
            board[j][0] = 1;
            board[j][s+1] = 1;
        }
        // for(int j = 0; j < s+2; j++) {
        //     for(int k=0; k<s+2; k++) {
        //         cout << board[j][k];
        //     }
        //     cout<<endl;
        // }
        makeAdj();
        cout << bipartiteMatch() << endl;
    }
}