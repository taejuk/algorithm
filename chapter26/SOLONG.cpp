#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;
const int ALPHABETS = 26;
int toNumber(char ch) {return ch - 'A';}

struct TrieNode  {
    TrieNode* children[ALPHABETS];
    bool terminal;
    pair<string, int> tabAns;
    
    TrieNode() {
        terminal = false;
        memset(children, 0, sizeof(children));
        tabAns = make_pair("",0);
    }

    ~TrieNode() {
        for(int i = 0; i < ALPHABETS; i++) {
            if(children[i]) delete children[i];
        }
    }

    void insert(const char* key, int r,int c) {
        if(c) {
            if(tabAns.second < r) tabAns = make_pair(key, r);
            else if(tabAns.second == r && tabAns.first.compare(key) > 0) tabAns = make_pair(key,r); 
        }
        if(*key == 0) {
            terminal = true;
        }
        else {
            int next = toNumber(*key);
            if(children[next] == NULL) children[next] = new TrieNode();
            children[next]->insert(key+1, r,1);
        }
    }

    TrieNode* find(const char* key) {
        if(*key == 0) return this;
        if(key == tabAns.first) return this;
        int next = toNumber(*key);
        if(children[next]==NULL) return NULL;
        return children[next]->find(key+1);
    }
};

int main() {
    int c,n,m;
    cin >> c;
    // find할 때에는 찾을 때마다 횟수를 증가시키면서
    for(int i = 0; i < c; i++) {
        cin >> n >> m;
        TrieNode node;
        int ret = m-1;
        for(int j = 0; j < n; j++) {
            string word;
            int fre;
            cin >> word >> fre;
            node.insert(word.c_str(), fre, 0);
        }
        for(int j = 0; j < m; j++) {
            string word;
            cin >> word;
            TrieNode* retnode = node.find(word.c_str());
            // string result = retnode == NULL ? "" : retnode->tabAns.first;
            // cout << "result: " << result << endl;
            if(retnode == NULL) ret += word.length();
            else {
                if(retnode->tabAns.first.length())
                ret += word.length()-retnode->tabAns.first.length()+1;
                else ret += word.length();
            }
        }
        cout << ret << endl;
    } 
}

