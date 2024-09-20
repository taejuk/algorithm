#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

int cache[100];

int LIS(int index, vector<int> list) {
    // index가 list의 끝에 다다르면 1을 반환
    int &ret = cache[index];
    if(ret != -1) return ret;
    // 자기자신을 포함하니깐
    ret = 1;
    int standard = list[index];
    for(int i = index+1; i <= list.size()-1; i++) {
        if(standard < list[i]) {
            ret = max(ret, 1 + LIS(i, list));
        }
    }
    return ret;
}
// index에 대해 for문을 돌아야 한다. 이렇게 하기 싫으면 list 시작점에 -1을 추가해서 길이를 구한다음 1을 뺀다.


int main() {
    memset(cache,-1,size(cache));
    vector<int> list = {};
}
