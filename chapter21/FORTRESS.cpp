#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int x;
    int y;
    int r;

    vector<TreeNode> children;
};

void findParentNode(TreeNode& newNode, TreeNode& parent) {
    // 1. newNode가 parent를 포함하는 경우
    // 2. parent가 newNode를 포함하는 경우
    for(int i = 0; i < parent.children.size(); i++) {
        TreeNode child = parent.children[i];
        int distance = (newNode.x - child.x) * (newNode.x - child.x) + (newNode.y - child.y) * (newNode.y - child.y);
        cout << "distance: " << distance << endl;
        // // 1. newNode가 parent를 포함하는 경우
        if(distance < (newNode.r * newNode.r)) {
            newNode.children.push_back(child);
            parent.children[i] = newNode;
            return ;
        } else if(distance < (child.r * child.r)) {
            return findParentNode(newNode, child);
        }
    }
    parent.children.push_back(newNode);
    return;
    // 없으면 추가한다.
}

// 최대 경로를 찾는다.

int findMax(TreeNode node) {
    int ret = 0;
    cout << "childs: " << node.children.size() << endl;
    for(int i = 0; i < node.children.size(); i++) {
        ret = max(ret, 1+findMax(node.children[i]));
    }
    return ret;
}



int main() {
    int inputs[8][3] =  {
        {21,15,20},
        {15,15,10},
        {13,12,5},
        {12,12,3},
        {19,19,2},
        {30,24,5},
        {32,10,7},
        {32,9,4},
    };
    vector<TreeNode> nodes;
    for(int i = 0; i < 8; i++) {
        TreeNode newNode;
        nodes.push_back(newNode);
    }
    nodes[0].x = inputs[0][0];
    nodes[0].y = inputs[0][1];
    nodes[0].r = inputs[0][2];
    for(int i = 1; i < 8; i++) {
        
        nodes[i].x = inputs[i][0];
        nodes[i].y = inputs[i][1];
        nodes[i].r = inputs[i][2];
        findParentNode(nodes[i],nodes[0]);
    }
    findMax(nodes[0]);
    return 0;  

}