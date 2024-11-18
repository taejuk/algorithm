#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void push_heap(vector<int>& heap, int newValue) {
    heap.push_back(newValue);
    int idx = heap.size()-1;
    while(idx > 0 && heap[idx] > heap[(idx-1)/2]) {
        swap(heap[idx], heap[(idx-1)/2]);
        idx = (idx-1)/2;
    }
}

void pop_heap(vector<int>& heap) {
    heap[0] = heap.back();
    heap.pop_back();
    int here = 0;
    while(true) {
        int left = here * 2 + 1, right = here * 2 + 2;
        if(left >= heap.size()) break;
        int next = here;
        if(heap[next] < heap[left]) next = left;

        if(right < heap.size() && heap[next] < heap[right]) next = right;

        if(next == here) break;
        swap(heap[here], heap[next]);
        here = next;
    }
}


int find_median(vector<int> heap) {
    int size = heap.size();
    if(size == 1) return heap[0];
    int medianIdx = (size - 1) / 2;
    // 밑에서 부터 올라가자
    int level = 0;
    while(true) {
             
    }
}