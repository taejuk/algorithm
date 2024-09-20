#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
// 메모이제이션을 추가해보자

bool isCorrect(string filename, string wildcard, int fileIndex, int wildIndex) {
    int F = filename.length();
    int W = wildcard.length();

    if(F <= fileIndex && W <= wildIndex) return true;
    // 더이상 남은 wild가 없는 경우
    if(F <= fileIndex || W <= wildIndex) return false;

    if(wildcard[wildIndex] == '*') {
        // position을 계속 증가시킬 수 있다.
        bool res = false;
        for(int i = fileIndex; i < F; i++) res = res || isCorrect(filename, wildcard, i, wildIndex+1);
        return res; 
    } else if(wildcard[wildIndex] == '?') {
        return isCorrect(filename, wildcard, fileIndex+1, wildIndex+1);
    } else {
        if(filename[fileIndex] != wildcard[wildIndex]) return false;
        return isCorrect(filename, wildcard, fileIndex+1, wildIndex+1);
    }
}

int main() {
    string wildcard = "he?p";
    string filename = "helpp";
    std::cout << isCorrect(filename,wildcard,0,0) << std::endl;
    
}
