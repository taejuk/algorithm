#include <iostream>
#include <map>
using namespace std;

map<int,int> coords;
// 새로운 점이 다른 점들에 의해 지배당하는가?
bool isDominated(int x, int y) {
    map<int,int>::iterator it = coords.lower_bound(x);

    if(it == coords.end()) return false;

    return y < it->second;
}

void removeDominated(int x, int y) {
    map<int,int>::iterator it = coords.lower_bound(x);
    if(it == coords.begin()) return;
    // 아직 점을 넣지 않았으니깐
    --it;

    while(true) {
        if(it->second > y) break;
        if(it == coords.begin()) {
            coords.erase(it);
            break;
        }
        else {
            map<int,int>::iterator jt = it;
            --jt;
            coords.erase(it);
            it = jt;
        }
    }
}

int registered(int x, int y) {
    if(isDominated(x,y)) return coords.size();
    removeDominated(x,y);
    coords[x] = y;
    return coords.size();
}