#include <iostream>
#include <vector>
#include <memory.h>
// cache[i]: i번째 숫자부터 시작하는 LIS의 길이
using namespace std;
int cache[100];
int numcache[100];


int makecache(int index, vector<int> numlist) {
    int& ret = cache[index];
    if(ret != -1) return ret;
    int &numret = numcache[index];
    ret = 1;
    numret = 1;
    int listLen = numlist.size();
    for(int i = index+1; i < listLen; i++) {
        if(numlist[index] < numlist[i]) {
            int newret = 1+makecache(i,numlist);
            if(newret > ret) {
                ret = newret;
                numret = numcache[i];
            }
            else if(newret == ret) {
                numret = numret + numcache[i];
            }
        }
    }
    return ret;
}

void findKth(int kth, int len, vector<int> numlist) {
    // kth가 0인 경우도 고려해야 하는데
    if(kth==0) return;
    // 만약 같은 길이이면 뒤의 숫자가 가장 작다.
    int listLen = numlist.size();
    for(int i = listLen; i>=0; i--) {
        if(cache[i] == len) {
            // kth 안에 있는 경우
            if(kth <= numcache[i]) {
                cout << numlist[i] << " ";
                findKth(kth, len-1, numlist);
                return;
            } else {
                kth -= numcache[i];
            }
        }
    }
}

int main() {
    vector<int> numlist={-1,2,1,4,3,6,5,8,7};
    memset(cache,-1,sizeof(cache));
    memset(numcache, -1, sizeof(numcache));
    makecache(0,numlist);
    vector<int> answer;
    findKth(4,cache[0]-1, numlist);
    cout << "" << endl;
   
}