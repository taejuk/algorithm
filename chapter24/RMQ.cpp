#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


struct RMQ {
    int n;
    vector<int> rangeMin;
    RMQ(const vector<int>& array) {
        n = array.size();
        rangeMin.resize(n*4);
        init(array, 0, n-1,1);
    }

    int init(const vector<int>& array, int left, int right, int node) {
        if(left ==  right) return rangeMin[node] = array[left];
        int mid = (left + right) / 2;
        // 왼쪽 자식을 결정한다.
        int leftMin = init(array, left, mid, node * 2);
        // 오른쪽 자식을 결정한다.
        int rightMin = init(array, mid+1, right, node*2+1);
        return rangeMin[node] = min(leftMin, rightMin);
    }

    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || nodeRight < left) return INT_MAX;
        if(left <= nodeLeft && nodeRight <= right) return rangeMin[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left,right, node*2, nodeLeft, mid), query(left,right, node*2+1, mid+1, nodeRight));
    }

    int query(int left, int right) {
        return query(left,right,1,0,n-1);
    }

    int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
        if(index < nodeLeft || nodeRight < index) return rangeMin[node];
        if(nodeLeft == nodeRight) return rangeMin[node] = newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeMin[node] = min(
            update(index, newValue, node, nodeLeft, mid),
            update(index, newValue, node, mid+1, nodeRight)
        );
    }

    int update(int index, int newValue) {
        return update(index, newValue, 1, 0 , n-1);
    }
};


struct Node {
    int idx;
    int parent;
    set<int> child;
    set<int> desc;
};


void updateDesc(int curNodeIdx,vector<Node>& nodes) {
    if(curNodeIdx == 0) return;
    int parent = nodes[curNodeIdx].parent;
    if(parent == -1) return;
    nodes[parent].desc.insert(curNodeIdx);
    return updateDesc(parent, nodes);
}

int findCommonParents(int curNodeIdx, int a, int b, vector<Node>& nodes) {
    int ret = curNodeIdx;
    for(int curChild: nodes[curNodeIdx].child) {
        if(nodes[curChild].desc.find(a) != nodes[curChild].desc.end() && nodes[curChild].desc.find(b) != nodes[curChild].desc.end()){
            ret = findCommonParents(curChild,a,b,nodes);
            break;
        }
    }
    return ret;
}

int findLength(int start, int end, vector<Node>& nodes) {
    int len = 0;
    if(start == end) return 0;
    for(int curChild: nodes[start].child){
        if(nodes[curChild].desc.find(end) != nodes[curChild].desc.end()) {
            len = 1 + findLength(curChild, end, nodes);
            break;
        }
    }
    return len;
}


int main() {
    vector<int> inputs = {-1,0,1,1,3,3,0,6,0,8,9,9,8};
    vector<Node> nodes;
    for(int i = 0; i < inputs.size(); i++) {
        Node newNode;
        newNode.idx = i;
        newNode.parent = inputs[i];
        newNode.desc.insert(i);
        nodes.push_back(newNode);
    }
    // child 추가했고
    for(int i = 1; i < inputs.size(); i++) {
        int parent = inputs[i];
        nodes[parent].child.insert(i);
    }

    // node를 순회하면서 desc 정보를 업데이트한다.
    for(int i = 0; i < inputs.size(); i++) {
        updateDesc(i, nodes);
    }
    int a = 2, b = 7;
    int common = findCommonParents(0,a,b,nodes);
    
    cout << findLength(common,a,nodes) + findLength(common,b,nodes) << endl;
}