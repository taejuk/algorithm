#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

struct obj{
    int volume;
    int wanted;
    string name;
};

vector<struct obj> objs; 

int cache[100];
int choices[100];


// index번쨰 물건을 넣고 넣었을 때 남은 volume이 remainVolume일 때 
// 
int packing(int index, int remainVolume) {
    int &ret = cache[index];
    if(ret != -1) return ret;
    ret = objs[index].wanted;
    remainVolume = remainVolume - objs[index].volume;
    // remainVolume이 0일때에 대한 처리를 하자.

    int len = objs.size();
    int bestNext=-1;
    for(int i = index+1; i < len; i++) {
        if(remainVolume >= objs[i].volume) {
            int ret2 = objs[index].wanted + packing(i, remainVolume);
            if(ret < ret2) {
                bestNext = i;
                ret = ret2;
            }
        }
    }
    choices[index] = bestNext;
    return ret;
}

void print_list(int index) {
    if(index == -1) return;
    cout << objs[index].name << endl;
    print_list(choices[index]);
}


int main() {
    memset(cache, -1 ,sizeof(cache));
    memset(choices, -1, sizeof(cache));
    obj nothing = {0, 0, "nothing"};
    obj laptop = {4,7,"laptop"};
    obj camera = {2,10,"camera"};
    obj xbox = {6,6,"xbox"};
    obj grinder = {4,7,"grinder"};
    obj dumbell = {2,5,"dumbell"};
    obj ency = {10,4,"ency"};
    objs.push_back(nothing);
    objs.push_back(laptop);
    objs.push_back(camera);
    objs.push_back(xbox);
    objs.push_back(grinder);
    objs.push_back(dumbell);
    objs.push_back(ency);
    
    cout << packing(0, 17) << endl;
    print_list(0);
    return 0;
}