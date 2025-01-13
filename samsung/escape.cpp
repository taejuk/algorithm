#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
const int MAX_TRY = 11;

struct RESULT {
    int times;
    char board[10][10];
    RESULT(int n, char b[10][10]) {
        times = n;
        for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) board[i][j] = b[i][j];
    }
};

int direction[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
// 성공이면 1, 실패면 0, 성공도 실패도 아니면 2
int move(char curboard[10][10], char (*newboard)[10], int dir) {
    for(int i = 0 ; i < N ; i++)
        for(int j = 0; j < M ; j++) newboard[i][j] = curboard[i][j];
    // R부터 움직이고 
    int rx,ry;
    int bx,by;
    int dx = direction[dir][0], dy = direction[dir][1];
    bool isMoved = false;
    bool holeinR = false;
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < M; j++) 
            if(newboard[i][j] == 'R') {
                rx = i;
                ry = j;
            } else if(newboard[i][j] == 'B') {
                bx = i;
                by = j;
            }
    // R부터 움직이고
    while(1) {
        if(newboard[rx+dx][ry+dy] == 'O') {
            isMoved = true;
            holeinR = true;
            newboard[rx][ry] = '.';
            break;
        }
        else if(newboard[rx+dx][ry+dy] == '.') {
            isMoved = true;
            newboard[rx+dx][ry+dy] = 'R';
            newboard[rx][ry] = '.';
            rx += dx;
            ry += dy;
        } else break;
    }
    // B움직인다. 이때 B 구슬이 구멍에 들어가면 false 반환
    while(1) {
        if(newboard[bx+dx][by+dy] == 'O') {
            return 0;
        }
        else if(newboard[bx+dx][by+dy] == '.') {
            isMoved = true;
            newboard[bx+dx][by+dy] = 'B';
            newboard[bx][by] = '.';
            bx += dx;
            by += dy;
        } else break;
    }
    // 다시 R 움직인다.
    if(holeinR) return 1;
    else {
        while(1) {
        if(newboard[rx+dx][ry+dy] == 'O') {
            isMoved = true;
            return 1;
        }
        else if(newboard[rx+dx][ry+dy] == '.') {
            newboard[rx+dx][ry+dy] = 'R';
            newboard[rx][ry] = '.';
            rx += dx;
            ry += dy;
            isMoved = true;
        } else break;
    }
    }
    if(!isMoved) return 0;
    return 2;
}
int result = MAX_TRY;
void escape(int times, char curboard[10][10]) {
    times++;
    if(times >=result) return;
    char newboard[10][10];
    for(int i = 0; i < 4; i++) {
        int poss = move(curboard, newboard,i);
        if(poss == 1) {
            result = min(result, times);
            return;
        } else if(poss==2) {
            escape(times, newboard);
        }
    }
    return ;
}


int main() {
    char str[11];
    cin >> N >> M;

    char board[10][10];
    for(int i = 0; i < N; i++) {
        cin >> str;
        for(int j = 0; j < M; j++) board[i][j] = str[j];
    }
    escape(0, board);
    if(result>=MAX_TRY) cout << -1 << endl;
    else cout << result << endl;
    return 0;
}