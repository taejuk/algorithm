#include <iostream>
#include <vector>

using namespace std;

int findMax(vector<int> left, vector<int> right) {
    int height;
    int width = 0;
    if(left[left.size()-1] < right[0]) height = left[left.size()-1];
    else height = right[0];

    int start = left.size()-1;
    while(1) {
        if(left[start] >= height) {
            width++;
            start = start - 1;
        } else break;
    }

    int start2 = 0;
    while(1) {
        if(right[start2] >= height) {
            width++;
            start2 = start2 +1;
        } else break;
    }
    return height * width;

}

int divide(vector<int> fence) {
    
    int len = fence.size();
    if(len == 1) return fence[0];
    vector<int> leftFence;
    vector<int> rightFence;
    int max = 0;
    for(int i = 0; i < len/2 ; i++) {
        leftFence.push_back(fence[i]);
    } 
    for(int i = len / 2; i < len; i++) {
        rightFence.push_back(fence[i]);
    }

    int maxLeft = divide(leftFence);
    if(maxLeft > max) max = maxLeft;
    int maxRight = divide(rightFence);
    if(maxRight > max) max = maxRight;
    int maxMiddle = findMax(leftFence, rightFence);
    if(maxMiddle > max) max = maxMiddle;
    return max;
}

int main() {
    vector<int> fence = {1,4,4,4,4,1,1};
    cout<< divide(fence) << endl;
}