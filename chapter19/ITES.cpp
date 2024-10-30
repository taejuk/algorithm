#include <iostream>
#include <vector>

using namespace std;

vector<long> arr;

void makeArr(int N) {
    arr.push_back(1983);
    for(int i = 1; i < N ; i++) {
        long a = (arr[i-1] * 214013 + 2531011) % 0x100000000;
        arr.push_back(a);
    }
    for(int i = 0; i < N; i++) {
        arr[i] = (arr[i] % 10000) + 1;
    }
    
} 

int main() {
    makeArr(20);
}