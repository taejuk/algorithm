#include <memory.h>
int n, board[100][100];
int cache[100][100];
int jump(int y, int x) {
    if(x >= n || y >= n) return 0;
    if(x == n-1 && y == n-1) return 1;
    if(cache[y][x] != -1) return cache[y][x];
    int jumpSize = board[y][x];
    cache[y][x] = jump(y + jumpSize,x) || jump(y, x+jumpSize);
    return cache[y][x];
}

int main() {
    memset(cache, -1, sizeof(cache));
}