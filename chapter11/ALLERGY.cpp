#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
// i번째 친구가 먹을 수 있는 음식 list
const int MAX = 100;
vector<int> foods[MAX];
const int CACHE_DEPTH = 5;
vector <string> friends;

// n은 친구의 수, m은 음식의 수 
int n,m;

int best;
const int INF = 54321;
void init() {
    friends.clear();
    n = m = 0;
    best = INF;
    for(int i = 0; i < MAX; i++) foods[i].clear(); 
    return;
}

int findIdx(string s) {
    auto it = find(friends.begin(), friends.end(),s);
    return it - friends.begin();
}
// curFood: 현재까지 사용한 음식, curFriend: 현재 친구
// curFood가 결정되면 curFriend도 자동으로 결정되니깐 남은 친구가 5명 이하일 때 메모이제이션을 쓰자
// 최소한으로 사용해야 하는 음식 수를 반환한다.
void allergy(int curFood, int curFriend) {
    // 다 완료되었으면 0을 반환
    int used = __builtin_popcount(curFood);
    int remainfriends = n - curFriend;
    if(remainfriends <= 0) {
        best = min(best, used);
        return;
    }
    
    
    
}




int main() {
    int c,a;
    string name;
    cin >> c;
    for(int i = 0; i < c; i++) {
        cin >> n >> m;
        for(int j = 0; j < n; j++) {
            cin >> name;
            friends.push_back(name);
        }
        for(int j = 0; j < m; j++) {
            int k,idx;
            cin >> k;
            for(int p = 0; p < k; p++) {
                cin >> name;
                idx = findIdx(name);
                foods[idx].push_back(j);
            }
        }
        
        allergy(0,0);
        cout << best << endl;
    }
    
}