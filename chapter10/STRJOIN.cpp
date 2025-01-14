#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> words;

void printwords() {
    cout << endl;
    for(int i = 0; i < words.size(); i++) cout << words[i] << " ";
    cout << endl;
}

int strjoin() {
    int ret = 0;
    if(words.size()==1) return words[0];
    int times = words.size()-1;
    for(int i = 0; i < times; i++) {
        sort(words.begin(), words.end());
        ret += words[0] + words[1];
        words.push_back(words[0]+words[1]);
        words.erase(words.begin());
        words.erase(words.begin());
        //printwords();
    }
    return ret;
}

int main() {
    int t,n,a;
    cin >> t;
    for(int i = 0; i < t; i++) {
        words.clear();
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> a;
            words.push_back(a);
        }
        sort(words.begin(), words.end());
        cout << strjoin() << endl;
    }
}