#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> arr;
// void makeArr(int N) {
//     arr.push_back(1983);
//     for(int i = 1; i < N ; i++) {
//         long a = (arr[i-1] * 214013 + 2531011) % 0x100000000;
//         arr.push_back(a);
//     }
//     for(int i = 0; i < N; i++) {
//         arr[i] = (arr[i] % 10000) + 1;
//     }  
// }

long makeNextNum(int prev) {
    long a = (prev * 214013 + 2531011) % 0x100000000;
    //a = (a % 10000) + 1;
    
    return a; 
}

// stack의 합이 k인 경우를 다 구하면 되는데
int ites(int k, int n) {
    int idx = 0;
    int res = 0;
    arr.push(1984);
    int sum = 1984;
    int lastarr = 1983;
    while(idx < n) {
        // 합이 같거나 크면 큐에서 앞의 값을 뺴야한다.
        if(sum >= k) {
            if(sum == k) res++;
            int first = arr.front();
            arr.pop();
            sum -= first;
        }
        else {
            long newlast = makeNextNum(lastarr);
            long aa = (newlast % 10000) + 1;
            cout << newlast << endl;
            arr.push(aa);
            sum += aa;
            lastarr = newlast;
            idx++;
        }
    }
    return res;
}

int main() {
        cout << ites(8791,20) << endl;
        // cout << ites(5265,5000) << endl;
        // cout << ites(3578452,5000000) << endl;
}