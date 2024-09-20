#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int INF = 987654321;
int cache[10000];
int findRank(vector<int> numbers) {
    int length = numbers.size();

    // rank 1인지 확인
    bool rank1 = true;
    bool rank2 = true;
    bool rank4 = true;
    bool rank5 = true;
    for(int i = 0; i < length-1; i++) {
        if(numbers[i] != numbers[i+1]) rank1 = false;
    }

    if(rank1) return 1;
    int aa = numbers[0] - numbers[1];
    for(int i = 0; i < length-1; i++) {
        if(numbers[i] - numbers[i+1] != aa) rank2 = false;
    }

    if(rank2) return 2;

    int first = numbers[0];
    int second = numbers[1];

    for(int i = 2; i < length; i++) {
        if(i % 2 == 0) {
            if(numbers[i] != first) rank4 = false;
        } else {
            if(numbers[i] != second) rank4 = false;
        }
    }
    if(rank4) return 4;

    for(int i = 0; i < length-2; i++) {
        if((numbers[i] + numbers[i+2]) != (2*numbers[i+1])) rank5 = false;
    }
    if(rank5) return 5;
    return 10;
}

// 현재 index가 주어졌을 때, 현재 index로부터 가장 작은 합. 만약 남은 숫자열이 1,2이면 max를 반환하자.

int PI(int index, vector<int> pilist) {
    int length = pilist.size();
    if((length - index) == 0) return 0;
    if((length - index) <= 2) return INF;

    int &ret = cache[index];
    if(ret != -1) return ret;
    ret = INF;
    int remainLength = length - index;
    if(remainLength >= 3) {
        vector<int> sublist;
        for(int i = index; i < index+3; i++) sublist.push_back(pilist[i]);
        ret = min(ret, findRank(sublist) + PI(index+3, pilist));
    }
    if(remainLength >= 4) {
        vector<int> sublist;
        for(int i = index; i < index+4; i++) sublist.push_back(pilist[i]);
        ret = min(ret, findRank(sublist) + PI(index+4, pilist));
    }
    if(remainLength >= 5) {
        vector<int> sublist;
        for(int i = index; i < index+5; i++) sublist.push_back(pilist[i]);
        ret = min(ret, findRank(sublist) + PI(index+5, pilist));
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    vector<int> test = {1,1,1,1,1,2,2,2};
    cout << PI(0, test) << endl;
    memset(cache, -1, sizeof(cache));
    vector<int> test2 = {1,2,1,2,2,2,2,2};
    cout << PI(0, test2) << endl;
    memset(cache, -1, sizeof(cache));
    vector<int> test3 = {2,2,2,2,2,2,2,2};
    cout << PI(0, test3) << endl;
    memset(cache, -1, sizeof(cache));
    vector<int> test4 = {1,2,6,7,3,9,3,9};
    cout << PI(0, test4) << endl;
}