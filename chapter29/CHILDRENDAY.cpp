#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

map<string, int> remain;

bool isBigger(string a, int b) {
    int rangeA = a.size();
    int rangeB = 0;
    int newb = b;
    while(newb > 0) {
        newb = newb / 10;
        rangeB++;
    }
    if(rangeA > rangeB) return true;
    else if(rangeA < rangeB) return false;
    else {
        string bstring = to_string(b);
        for(int i = rangeA-1; i >= 0; i--) {
            if(bstring[i] > a[i]) return false;
        }
        return true;
    }
}

string childday(vector<int> list, int n, int m) {
    queue<string> q;
    int range = list.size();
    for(int i = 0; i < range; i++) {
        if(list[i] >= (n+m) && ((list[i] % n) == m)) return to_string(list[i]);
        if(list[i] > 0) q.push(to_string(list[i]));
        remain[to_string(list[i])] = list[i] % m;
    }
    while(!q.empty()) {
        string cur = q.front();
        q.pop();
        int r = remain[cur];
        for(int i = 0; i < range; i++) {
            string newstr = cur + to_string(list[i]);
            q.push(newstr);
            // 그래프로 이 계산을 줄일 수 있따.
            int newr = (r * 10 + list[i]) % n;
            if(newr == m && isBigger(newstr, n+m)) return newstr;
            remain[newstr] = newr;
        }

    }
    return "IMPOSSIBLE";
}

int main() {
    int c;
    cin >> c;
    for(int i = 0; i < c; i++) {
        string liststr;
        int n,m;
        vector<int> list;
        cin >> liststr >> n >> m;
        for(int j = 0; j < liststr.length(); j++) {
            list.push_back(liststr[j]-'0');
        }
        sort(list.begin(), list.end());
        cout << childday(list, n, m) << endl;
    }
}