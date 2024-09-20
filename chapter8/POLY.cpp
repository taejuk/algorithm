#include <iostream>
#include <vector>
#include <memory.h>
int MOD = 10000000;
int cache[100][100];
using namespace std;
// 남은 block = n, 그 전 층의 block 개수 = before
int poly(int n, int before) {
    if(n == 0) return 1;
    int& ret = cache[n][before];
    if(ret != -1) return ret;
    ret = 0;
    // 그 전 층의 block 개수가 0이면 그냥 더하면 된다
    if(before == 0) {
        // 현재층에 반드시 하나 이상은 놓아야 한다.
        for(int current = 1; current <= n; current++) {
            ret = (ret + poly(n-current, current)) % MOD;
        }
    } else {
    // 그 전 층의 block이 존재하면 가능한 경우의 수를 곱해야 한다.
        for(int current = 1; current <= n; current++) {
            int pos = current + before - 1;
            ret = (ret + pos * poly(n-current, current)) % MOD;
        }
    }

    return ret;
}

int main() {
    memset(cache, -1 ,sizeof(cache));
    cout << poly(2,0) << endl;
    memset(cache, -1 ,sizeof(cache));
    cout << poly(4,0) << endl;
    memset(cache, -1 ,sizeof(cache));
    cout << poly(92,0) << endl;
    
}