#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool isSort(const vector<int>& cur) {
    int vars = cur.size();
    for(int i = 0; i < vars-1; i++) {
        if(cur[i] > cur[i+1]) return false;
    }
    return true;
}
void printvec(vector<int> c) {
    for(int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}
int sortinggame(vector<int> init) {
    int ret = 0;
    if(isSort(init)) return ret;
    queue<vector<int>> q;
    q.push(init);
    int range = init.size();
    // 새로운 요소를 push할 때마다 sort되었는지 확인하고 값을 return한다.
    while(!q.empty()) {
        int s = q.size();
        ret++;
        for(int i = 0; i < s; i++) {
            vector<int> cur = q.front();
            q.pop();
        // 새로운 요소를 만들어야 한다. 
            for(int i = 0; i < range-1; i++) {
                for(int j = i+2; j <= range; j++) {
                // i부터 j까지 뒤집어야 한다.
                    vector<int> new_vec = cur;
                    reverse(new_vec.begin()+i, new_vec.begin()+j);
                    if(isSort(new_vec)) return ret;
                    q.push(new_vec);
                }
            }
        }
    }
    return INT_MAX;
}

int main() {
    int c;
    cin >> c;
    for(int i = 0; i < c; i++) {
        vector<int> init;
        int n;
        cin >> n;
        int num;
        for(int j = 0; j < n; j++) {
            
            cin >> num;
            init.push_back(num);
        }
        cout << sortinggame(init) << endl;
    }
}