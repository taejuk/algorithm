#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// index, value 값이라고 생각하면 된다.
vector<pair<int,int>> nodes;

int makenodes(vector<int> numLefts) {
    for(int i = 0; i < numLefts.size(); i++) {
        pair<int,int> newpair = make_pair(i, -1);
        if(i == 0) {
            nodes.push_back(newpair);
            continue;    
        }
        int lefts = numLefts[i];
        int pos = nodes.size() - lefts;
        nodes.insert(nodes.begin() + pos, newpair);

    }

    for(int i = 0; i < nodes.size(); i++) {
        nodes[i].second = i+1;
    }
    sort(nodes.begin(), nodes.end());
    for(int i = 0; i < nodes.size(); i++) cout << nodes[i].first << ": " <<nodes[i].second << endl;
}

int main() {
    vector<int> numLefts = {0,1,1,2,3};
    makenodes(numLefts);
}