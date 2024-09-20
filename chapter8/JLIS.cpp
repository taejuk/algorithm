#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
int cache[100][100];

using namespace std;

// int JLIS(int,int,vector<int>, vector<int>);

// int findMax(vector<int> first, vector<int> second) {
//     int n = first.size(), m = second.size();

//     int ret = 0;
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             ret = max(ret, JLIS(i,j,first,second));
//         }
//     }

//     return ret;
// }

// n과 m은 first list이다.
int JLIS(int n, int m, int standard,vector<int> first, vector<int> second) {
    int &ret = cache[n][m];
    if(ret != -1) return ret;
    ret = 1;
    // 기준이 min이 아니라 standard로 해야함
    for(int i = n; i < first.size(); i++) {
        if(standard < first[i]) {
            ret = max(ret, 1 + JLIS(i, m,first[i], first, second));
        }
    }

    for(int i = m; i < second.size(); i++) {
        if(standard < second[i]) {
            ret = max(ret, 1+ JLIS(n,i,second[i],first,second));
        }
    }
    return ret;
}

int main() {
    memset(cache,-1,sizeof(cache));
    vector<int> first = {1,2,3};
    vector<int> second = {4,5,6};
    cout << JLIS(0,0,-1,first,second)-1<< endl;
}