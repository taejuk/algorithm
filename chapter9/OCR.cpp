#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
#define WORDSIZE 5
#define OCRSIZE 4
string list[WORDSIZE] = {"I", "am", "a", "boy", "buy"};

double B[WORDSIZE] = {1, 0 ,0 ,0 ,0};
// i번째 다음에 j가 나올 확률
double T[WORDSIZE][WORDSIZE] = {
    {0.1,0.6,0.1,0.1,0.1},
    {0.1,0.1,0.6,0.1,0.1},
    {0.1,0.1,0.1,0.6,0.1},
    {0.2,0.2,0.2,0.2,0.2},
    {0.2,0.2,0.2,0.2,0.2}
};
// i를 j로 인식할 확률
double M[WORDSIZE][WORDSIZE] = {
    {0.8,0.1,0.0,0.1,0.0},
    {0.1,0.7,0.0,0.2,0.0},
    {0.0,0.1,0.8,0.0,0.1},
    {0.0,0.0,0.0,0.5,0.5},
    {0.0,0.0,0.0,0.5,0.5}
};

int ocrlist[OCRSIZE] = {0, 1, 1, 3};
int words[OCRSIZE] = {-1,-1,-1,-1};
double cache[100][100];

double OCR(int index, int selectedBeforeWord) {
    if(index >= OCRSIZE) return 1;
    double& ret = cache[index][selectedBeforeWord];
    if(ret != 0) return ret;
    ret = 0;
    if(index == 0) {
        for(int i = 0; i < WORDSIZE; i++) {
            double newret = B[i]*M[ocrlist[index]][i]*OCR(index+1, i);
            if(newret > ret) {
                ret = newret;
                words[index] = i;
            }
        }
    } else {
        for(int i = 0; i < WORDSIZE; i++){
            double newret = T[selectedBeforeWord][i]*M[ocrlist[index]][i]*OCR(index+1,i);
            if(newret > ret) {
                ret = newret;
                words[index] = i;
            }
        }
    }

    return ret;
}

int main() {
    memset(cache,-1, sizeof(cache));
    for(int i = 0; i < WORDSIZE; i++) OCR(i, 0);
    for(int i = 0; i < OCRSIZE; i++) cout << list[i] << " ";
    cout<<""<<endl;

}