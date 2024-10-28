#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int counting[100000];
int psum[100000];
int N = 6;
int K = 4;

void partial_sum(vector<int> arr) {
    int length = arr.size();
    memset(psum, 0, sizeof(psum));
    memset(counting, 0, sizeof(counting));
    for(int i = 0; i < length; i++) {
        if(i == 0) psum[0] = arr[0] % K;
        else psum[i] = (psum[i-1] + arr[i]) % K;
        counting[psum[i]]++;
    }
    return ;
}

int find_one() {
    int ret = 0;
    for(int i = 0; i < K; i++) {
        ret = (ret + counting[i] * (counting[i] - 1) / 2) % 20091101;
    }
    return ret;
}

