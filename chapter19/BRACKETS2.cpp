#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

bool isCorrect(string text) {
    stack<char> s;
    for(int i = 0; i < text.length(); i++) {
        if(text[i] == '(' || text[i] == '{' || text[i] == '[') {
            s.push(text[i]);
        }
        else {
            // 스택 비어있는 경우 고려
            if(s.empty()) return false;
            if(text[i] == ')') {
                if(s.top() != '(') return false;
            } else if (text[i] == '}') {
                if(s.top() != '{') return false;
            } else if (text[i] == ']') {
                if(s.top() != '[') return false;
            }
            s.pop();
        }
    }
    if(s.size() == 0) return true;
    else return false;
    // stack이 다 비워졌는지도 확인해야 함
}


int main() {
    cout << isCorrect("()()") << endl;
    cout << isCorrect("({[}])") << endl;
    cout << isCorrect("({}[(){}])") << endl;
}
