#include <iostream>
#include <algorithm>
#include <queue>
#include <memory>
using namespace std;
int N;
int res = 0;
struct RESULT {
    int times;
    int board[30][30];
    RESULT(int n, int b[30][30]) {
        times = n;
        for(int i = 0; i < 30; i++) {
            for(int j = 0; j < 30; j++) {
                board[i][j] = b[i][j];
            }
        }
    }
};

void printboard(int board[30][30]) {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) cout << board[i][j] << " ";
        cout << endl;
    }
}

// 0: down, 1: up, 2: left, 3: right
int direction[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};

void move(int board[30][30], int(*newboard)[30], int dir) {
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++)
            newboard[i][j] = board[i][j];
    int dx = direction[dir][0];
    int dy = direction[dir][1];
    int curx, cury;
    if(dir == 0) {
        for(int i = N-1; i >= 1; i--) {
            for(int j = 1; j <= N; j++) {
                if(newboard[i][j] > 0) {
                    curx = i;
                    cury = j;
                    while(1) {
                        if(newboard[curx+dx][cury+dy] == 0) {
                            newboard[curx+dx][cury+dy] = newboard[curx][cury];
                            newboard[curx][cury] = 0;
                            curx+=dx;
                            cury+=dy;
                        } else if(newboard[curx+dx][cury+dy] == newboard[curx][cury]) {
                            newboard[curx+dx][cury+dy] += newboard[curx][cury];
                            res = max(res, newboard[curx+dx][cury+dy]);
                            newboard[curx][cury] = 0;
                            curx+=dx;
                            cury+=dy;
                        } else break;
                    }
                }
            }
        }
    } else if(dir == 1) {
        for(int i = 2; i<=N;i++) {
            for(int j = 1; j<=N; j++) {
                if(newboard[i][j] > 0) {
                    curx = i;
                    cury = j;
                    while(1) {
                        if(newboard[curx+dx][cury+dy] == 0) {
                            newboard[curx+dx][cury+dy] = newboard[curx][cury];
                            newboard[curx][cury] = 0;
                            curx+=dx;
                            cury+=dy;
                        } else if(newboard[curx+dx][cury+dy] == newboard[curx][cury]) {
                            newboard[curx+dx][cury+dy] += newboard[curx][cury];
                            res = max(res, newboard[curx+dx][cury+dy]);
                            newboard[curx][cury] = 0;
                            curx+=dx;
                            cury+=dy;
                        } else break;
                    }
                }
            }
        }
    } else if(dir == 2) {
        for(int j = 2; j <= N; j++) {
            for(int i = 1; i <= N; i++) {
                for(int j = 1; j<=N; j++) {
                if(newboard[i][j] > 0) {
                    curx = i;
                    cury = j;
                    while(1) {
                        if(newboard[curx+dx][cury+dy] == 0) {
                            newboard[curx+dx][cury+dy] = newboard[curx][cury];
                            newboard[curx][cury] = 0;
                            curx+=dx;
                            cury+=dy;
                        } else if(newboard[curx+dx][cury+dy] == newboard[curx][cury]) {
                            newboard[curx+dx][cury+dy] += newboard[curx][cury];
                            res = max(res, newboard[curx+dx][cury+dy]);
                            newboard[curx][cury] = 0;
                            curx+=dx;
                            cury+=dy;
                        } else break;
                    }
                }
            }
            }
        }
    } else if(dir == 3) {
        for(int j = N-1; j >=1; j--) {
            for(int i = 1; i <= N; i++) {
                for(int j = 1; j<=N; j++) {
                if(newboard[i][j] > 0) {
                    curx = i;
                    cury = j;
                    while(1) {
                        if(newboard[curx+dx][cury+dy] == 0) {
                            newboard[curx+dx][cury+dy] = newboard[curx][cury];
                            newboard[curx][cury] = 0;
                            curx+=dx;
                            cury+=dy;
                        } else if(newboard[curx+dx][cury+dy] == newboard[curx][cury]) {
                            newboard[curx+dx][cury+dy] += newboard[curx][cury];
                            res = max(res, newboard[curx+dx][cury+dy]);
                            newboard[curx][cury] = 0;
                            curx+=dx;
                            cury+=dy;
                        } else break;
                    }
                }
            }
            }
        }
    }
}


void block(int times,int initB[30][30]) {
    int newtimes = times+1;
    if(newtimes > 5) return;
    for(int i = 0; i < 4; i++) {
        int newb[30][30];
        move(initB, newb,i);
        
        block(newtimes, newb);
        
    }
    // queue<RESULT> q;
    // RESULT r(0,initB);
    // int newb[30][30];
    // q.push(r);
    // while(!q.empty()) {
    //     RESULT cur = q.front(); q.pop();
    //     if(cur.times>=5) continue;
    //     int newtimes = cur.times+1;
    //     for(int i = 0; i < 4; i++) {
    //         move(cur.board, newb, i);
    //         RESULT newres = RESULT(newtimes, newb);
    //         q.push(newres);
    //     }
    // }
}

int main() {
    cin >> N;
    int board[30][30];
    for(int i = 0; i < 30; i++) for(int j = 0; j < 30; j++) board[i][j] = -1;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> board[i][j];
            res = max(board[i][j], res);
        }
    }
    block(0,board);
    cout << res << endl;
}