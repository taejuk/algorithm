#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;
int INF = 987654321;
int cache[100][100];
// end는 포함안하게 계산해야 함.
int calculate(vector<int> list, int num,int start, int end) {
    int ret = 0;

    for(int i = start; i < end ; i++) ret += (list[i] - num) * (list[i] - num);
    return ret;
}

int quantization(vector<int> list, int s, int index) {
    int len = list.size();
    if(len == index) return 0;
    // 기저사례 2: s가 1일 경우
    if(s==1) {
        int hap = 0;
        for(int i = index; i < len; i++) {
            hap+= list[i];
        }
        int mean = hap / (len-index);
        
        int ret = min(calculate(list,mean,index,len), calculate(list,mean+1,index,len));
        return ret;
    }
    // s가 2이상일 때는 
    int &ret = cache[s][index];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = index; i < len; i++) {
        //mean을 구하자.
        int hap=0;
        for(int j = index; j < i+1; j++) hap += list[j];
        int mean = hap / (i+1-index);
        ret = min(ret,calculate(list,mean,index,i+1) + quantization(list,s-1,i+1));
        ret = min(ret,calculate(list,mean+1,index,i+1) + quantization(list,s-1,i+1));
    }

    return ret;
}

void printList(vector<int> list) {
    for(int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << "" << endl;
}

int main() {
    memset(cache,-1,sizeof(cache));
    vector<int> list{1,744,755,4,897,902,890,6,777};
    sort(list.begin(),list.end());
    
    cout << quantization(list,3,0) << endl;
}