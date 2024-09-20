#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int MOD = 1000000007;

int cache[100];

int findAllTiling(int n) {
    if(n==0) return 1;
    if(n==1) return 1;

    int &ret = cache[n];
    if(ret != -1) return ret;
    ret = (findAllTiling(n-1) + findAllTiling(n-2)) % MOD;
    return ret;
}

int findAsym(int n) {
    int ret;
    if(n % 2 == 0) {
        ret = (findAllTiling(n) - 2 * findAllTiling(n/2-1) - findAllTiling(n/2-2)) % MOD;
    } else {
        ret = (findAllTiling(n) - findAllTiling((n-1)/2) + MOD) % MOD;
    }
    if(ret < 0) ret = ret + MOD;
    return ret;
}

int main() {
    int n1 = 2;
    int n2 = 4;
    int n3 = 92;
    memset(cache, -1, sizeof(cache));
    cout << findAsym(n1) << endl;
    memset(cache, -1, sizeof(cache));
    cout << findAsym(n2) << endl;
    memset(cache, -1, sizeof(cache));
    cout << findAsym(n3) << endl;
}
