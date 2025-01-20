#define MAX_N 1000
#define MAX_M 20
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
int rr[4][500][500];
int treasures[10010][2];
int nums;
struct Result {
	int y, x;
};

int N;
int M;
int board[MAX_N][MAX_N];
void init(int n, int m, int Map[MAX_N][MAX_N])
{
    memset(treasures,-1,sizeof(treasures));
    int idx = 0;
    nums = 0;
    N = n;
    M = m;
    for(int i = 0; i < n ; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] = Map[i][j];
            if(Map[i][j]) {
                treasures[idx][0] = i;
                treasures[idx][1] = j;
                idx++;
                nums++;
            }
        }
    }
}
// 0: 0, 1: 90, 2: 180, 3: 270

void rotate(int basex, int basey, int &newx, int &newy, int rot) {
    newx = basex;
    newy = basey;
    if(rot == 0) {
        newx = basex;
        newy = basey;
    } else if(rot == 1) {
        swap(newx,newy);
        newy = -1*newy;
    } else if(rot == 2) {
        newx = -1*newx;
    } else if(rot==3) {
        swap(newx,newy);
        newx = -1*newx;
    }
}


void rotateboard(int baseboard[MAX_M][MAX_M], int rot, int sysx[4][2], int rrs[500][500]) {
    int newx, newy;
    int dxdy[4][2] = {{0,0},{0,M+1},{M+1,M+1},{M+1,0}};
    int dx = dxdy[rot][0];
    int dy = dxdy[rot][1];
    int idx = 0;
    if(rot == 0) {
        
        for(int y = 0; y < M; y++) {
            for(int x = 0; x < M; x++) {
                //newboard[y][x] = baseboard[y][x];
                if(baseboard[y][x] == 9) {
                    sysx[rot][0] = y;
                    sysx[rot][1] = x;
                    rrs[idx][0] = y;
                    rrs[idx][1] = x;
                    idx++;
                } else if(baseboard[y][x]==1) {
                    rrs[idx][0] = y;
                    rrs[idx][1] = x;
                    idx++;
                }
            }
        }
        return;
    }
    
    for(int y = 1; y <= M; y++) {
        for(int x = 1; x <= M; x++) {
            if(rot == 0) {
                newy = y;
                newx = x;
            } else if(rot == 1) {
                newx = y;
                newy = -x;
            } else if(rot == 2) {
                newx = -x;
                newy = -y;
            } else if(rot == 3) {
                newx = -y;
                newy = x;
            }
            newx = newx+dx;
            newy = newy+dy;
            //newboard[newy-1][newx-1] = baseboard[y-1][x-1];
            if(baseboard[y-1][x-1] == 9) {
                sysx[rot][0] = newy-1;
                sysx[rot][1] = newx-1;
                rrs[idx][0] = newy-1;
                rrs[idx][1] = newx-1;
                idx++;
            } else if(baseboard[y-1][x-1] == 1) {
                rrs[idx][0] = newy-1;
                rrs[idx][1] = newx-1;
                idx++;
            }
        }
    }
}
bool isCanStand(int basey, int basex, int rrs[500][500], int sy, int sx) {
    int dy,dx;
    int y,x;
    int idx = 0;
    if(((basey-sy) < 0) || ((basey+(M-1-sy)) >= N) || ((basex-sx) < 0) || ((basex+(M-1-sx)) >= N)) return false;
    // for(int y = 0; y < M; y++) {
    //     for(int x = 0; x < M; x++) {
    //         dy = y - sy;
    //         dx = x - sx;
    //         if(piece[y][x] > 0) {
    //             if(board[basey+dy][basex+dx] == 0) return false;
    //         }
    //     }
    // }
    while(1) {
        if(rrs[idx][0] == -1 || rrs[idx][1] == -1) break;
        y = rrs[idx][0]; x = rrs[idx][1];
        dy = y - sy; dx = x - sx;
        if(board[basey+dy][basex+dx] == 0) return false;
        idx++;
    }
    idx= 0;
    while(1) {
        if(rrs[idx][0] == -1 || rrs[idx][1] == -1) break;
        y = rrs[idx][0]; x = rrs[idx][1];
        dy = y - sy; dx = x - sx;
        board[basey+dy][basex+dx] = 0;
        idx++;
    }
    
    return true;
}
Result findTreasureChest(int Pieces[MAX_M][MAX_M])
{
	Result res;
	res.y = res.x = 0;
    int y,x;
    // rotateboard를 여기서 다 구하자.
    // 여기서 그냥 vector를 집어넣으면 된다.
    
    memset(rr,-1,sizeof(rr));
    
    int sysx[4][2];
    for(int i = 0; i < 4; i++) {
        rotateboard(Pieces, i,sysx, rr[i]);
    }
    
    for(int i = 0; i < nums; i++) {
        y = treasures[i][0];
        x = treasures[i][1];
        if(board[y][x]==1) {
            for(int rot = 0; rot < 4; rot++)
                    if(isCanStand(y,x,rr[rot],sysx[rot][0],sysx[rot][1])) {
                        res.y = y;
                        res.x = x;
                        return res;
                    }
        }
    }
    
            
    
    
	return res;
}


// int main() {
//     M = 5;
//     int temp[5][5] = {
//         {0,1,1,0,0},
//         {1,0,1,0,1},
//         {0,1,1,1,0},
//         {0,0,1,0,0},
//         {1,1,1,0,0},
//     };
//     int newtemp[5][5];
//     int rot=2;
//     int newx, newy;
//     int dxdy[4][2] = {{0,0},{0,M+1},{M+1,M+1},{M+1,0}};
//     int dx = dxdy[rot][0];
//     int dy = dxdy[rot][1];
//     for(int y = 1; y <= M; y++) {
//         for(int x = 1; x <= M; x++) {
//             rotate(x,y,newx,newy,rot);
//             newx = ((newx+dx));
//             newy = ((newy+dy));
//             newtemp[newy-1][newx-1] = temp[y-1][x-1];
//         }
//     }
//     for(int i = 0; i < 5; i++) {
//         for(int j = 0; j < 5; j++) {
//             cout << newtemp[i][j] << " ";
//         }
//         cout << endl;
//     }
// }