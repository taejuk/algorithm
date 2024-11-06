#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

vector<int> preorder;
vector<int> inorder;

void printpostorder(vector<int> pre, vector<int> in) {
    if(pre.size() == 0) return;
    
    int root = pre[0];
    vector<int> inleft, inright;
    vector<int> preleft, preright;
    int idx = 0;
    while(idx < in.size()) {
        if(in[idx] == root) {
            idx++;
            break;
        }
        inleft.push_back(in[idx]);
        idx++;
    }

    while(idx < in.size()) {
        inright.push_back(in[idx]);
        idx++;
    }
    
    for(int i = 0; i < pre.size(); i++) {
        if(find(inleft.begin(), inleft.end(), pre[i]) != inleft.end()) {
            preleft.push_back(pre[i]);
        } else if(find(inright.begin(), inright.end(), pre[i]) != inright.end()) {
            preright.push_back(pre[i]);
        }
    }

    printpostorder(preleft, inleft);
    printpostorder(preright, inright);

    cout << root << " ";
}

int main() {
    preorder.push_back(27);
    preorder.push_back(16);
    preorder.push_back(9);
    preorder.push_back(12);
    preorder.push_back(54);
    preorder.push_back(36);
    preorder.push_back(72);

    inorder.push_back(9);
    inorder.push_back(12);
    inorder.push_back(16);
    inorder.push_back(27);
    inorder.push_back(36);
    inorder.push_back(54);
    inorder.push_back(72);

    int root = preorder[0];
    printpostorder(preorder, inorder);
    cout << "" << endl;

}
