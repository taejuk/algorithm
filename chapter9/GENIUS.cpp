#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;
int n = 3;
double percents[3][3] = {
    {0.18, 0.40, 0.42},
    {0.15, 0.46, 0.39},
    {0.58, 0.23, 0.19}
};

int times[3] = {4,4,2};

double genius(int k, int prev,int find) {
    if(k < 0) {
        if(prev != find) return 0;
        else return 1;
    }

    double ret = 0;
    for(int i = 0; i < n; i++) {
        ret += percents[prev][i] * genius(k-times[i], i, find);
    }
    return ret;
}

int main() {
    cout << genius(2,0,0) << endl;
    cout << genius(2,0,1) << endl;
    cout << genius(2,0,2) << endl;
}