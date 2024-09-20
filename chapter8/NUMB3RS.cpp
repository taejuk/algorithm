#include <iostream>
#include <memory.h>

int N = 5;
double pos[5] = {0,0,0,0,0};
int roadCounts[5] = {0,0,0,0,0};
int road[5][5] = {
    {0,1,1,1,0},
    {1,0,0,0,1},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {0,1,0,0,0}};
// 어떻게 하면 메모이제이션을 적용할 수 있을까?
void calculate(int current, int days, double currentPos) {
    if(days == 0) {
        pos[current] += currentPos;
        return ;
    }
    int roadCounts = 0;
    for(int i = 0; i < N; i++) {
        if(road[current][i] == 1) roadCounts += 1;
    }
    for(int i = 0; i < N; i++) {
        if(road[current][i] == 1) calculate(i, days-1, currentPos / roadCounts);
    }
    
    return ;
}

double cache[100][100];

double search(int current, int days, int start) {
    if(days == 0) {
        if(current == start) return 1;
        else return 0;
    }
    double &ret = cache[current][days];
    if(ret != -1) return ret;
    
    ret = 0;
    for(int i = 0; i < N; i++) {
        if(road[current][i] == 1) {ret += search(i, days-1, start) / roadCounts[i];}
        
    }
    return ret;
}



int main() {
   for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) cache[i][j] = -1;
   }
   for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
        if(road[i][j] == 1) roadCounts[i]++;
    }
   }
   std::cout << search(4,2,0) << std::endl;
}