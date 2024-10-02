#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
// 현재 놓는 사람이 이길 수 있는가?
// 현재 놓는 사람이 이길 수 있으면 1, 없으면 -1을 반환하자.
int cache[1<<25];
int findcache(char board[5][5]) {
    int num = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(board[i][j] == '#') num += 1 << (i*5+j);
        }
    }
    return num;
}
int blockgame(char board[5][5]) {
    // 더이상 둘 수 없는 경우가 있을 떄
    int cachenum = findcache(board);

    int &ret = cache[cachenum];
    if(ret != -2) return ret;
    ret = -1;
    // 일자 블록을 놓을 수 있는 경우의 수
    for(int r = 0; r < 5; r++) {
        for(int c = 0; c < 5; c++) {
            // 해당 포인트에서 둘 수 있는 경우의 수를 다 두자.
            // 첫 번째는 -
            if(c < 4 && board[r][c] == '.' && board[r][c+1] == '.') {
                board[r][c] = '#';
                board[r][c+1] = '#';
                
                ret = max(ret, -1 * blockgame(board));
                board[r][c] = '.';
                board[r][c+1] = '.';
            }
            // 두번째는 I
            if(r < 4 && board[r][c] == '.' && board[r+1][c] == '.') {
                board[r][c] = '#';
                board[r+1][c] = '#';
                
                ret = max(ret, -1 * blockgame(board));
                board[r][c] = '.';
                board[r+1][c] = '.';
            }

            // ㄱ 자 블록에 대한 경우의 수를 찾아야 한다.
            if(r >= 1 && c >= 1 && board[r][c] == '.' && board[r-1][c] == '.' && board[r][c-1] == '.') {
                board[r][c] = '#';
                board[r-1][c] = '#';
                board[r][c-1] = '#';
                
                ret = max(ret, -1 * blockgame(board));
                board[r][c] = '.';
                board[r-1][c] = '.';
                board[r][c-1] = '.';
            }
            if(r >= 1 && c < 4 && board[r][c] == '.' && board[r-1][c] == '.' && board[r][c+1] == '.') {
                board[r][c] = '#';
                board[r-1][c] = '#';
                board[r][c+1] = '#';
                
                ret = max(ret, -1 * blockgame(board));
                board[r][c] = '.';
                board[r-1][c] = '.';
                board[r][c+1] = '.';
            }
            if(r < 4 && c >= 1 && board[r][c] == '.' && board[r+1][c] == '.' && board[r][c-1] == '.') {
                board[r][c] = '#';
                board[r+1][c] = '#';
                board[r][c-1] = '#';
               
                ret = max(ret, -1 * blockgame(board));
                board[r][c] = '.';
                board[r+1][c] = '.';
                board[r][c-1] = '.';
            }
            if(r < 4 && c < 4 && board[r][c] == '.' && board[r+1][c] == '.' && board[r][c+1] == '.') {
                board[r][c] = '#';
                board[r+1][c] = '#';
                board[r][c+1] = '#';
                
                ret = max(ret, -1 * blockgame(board));
                board[r][c] = '.';
                board[r+1][c] = '.';
                board[r][c+1] = '.';
            }
        }
    }
    
    return ret;
}

int main() {
    char board[5][5] = {
        {'.','.','.','.','.'},
        {'.','.','.','.','.'},
        {'.','.','.','.','.'},
        {'.','.','.','.','.'},
        {'.','.','.','.','.'}
    };
    for(int i = 0; i < (1<<25); i++) cache[i] = -2;
    cout << blockgame(board) << endl;
}