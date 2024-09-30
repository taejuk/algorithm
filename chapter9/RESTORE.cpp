#include <iostream>
#include <string.h>
#include <vector>
#include <memory>
using namespace std;

const int MAX_N = 15;
int k;
string word[MAX_N];
int cache[MAX_N][1<<MAX_N], overlap[MAX_N][MAX_N];
// 단어를 저장할 때 전처리해야 함
int restore(int last, int used) {
    if(used == (1 << k)-1) return 0;
    int& ret = cache[last][used];
    if(ret != -1) return ret;
    ret = 0;
    for(int next = 0; next < k; next++) {
        if((used & (1 << next))==0) {
            int cand = overlap[last][next] + restore(next, used + (1 << next));
            ret = max(ret, cand);
        }
    }
    return ret;
    
}

int main() {
}
