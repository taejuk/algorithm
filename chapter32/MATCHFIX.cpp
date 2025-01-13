int n,m;
int wins[20], match[200][2];
#include "networkFlow.cpp"
bool canWinWith(int totalWins) {
    if(*max_element(wins+1, wins+n) >= totalWins) return false;
    V = n + m + 2;
    memset(capacity, 0 , sizeof(capacity));
    for(int i = 0; i < m; i++) {
        capacity[0][2+m] = 1;
        for(int j = 0; j < 2; j++) {
            capacity[2+i][2+m+match[i][j]]=1;
        }
    }

    for(int i = 0; i < n; i++) {
        int maxWin = (i==0 ? totalWins : totalWins-1);
        capacity[2+m+i][1] = maxWin - wins[i];
    }

    return networkFlow(0,1) == m;
}

int main() {

    return 0;
}