#include <iostream>
#include <memory>
#include <vector>
using namespace std;
const int ALPHABETS = 26;
int toNumber(char ch) {return ch - 'A';}

struct TrieNode  {
    TrieNode* children[ALPHABETS];
    bool terminal;
    pair<string, int> tabAns;
    bool init;
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

    void insert(const char* key, int r) {
        if(tabAns.second < r) tabAns = make_pair(key, r);
        else if(tabAns.second == r && tabAns.first.compare(key) > 0) tabAns = make_pair(key,r); 

        if(*key == 0) {
            terminal = true;
        }
        else {
            int next = toNumber(*key);
            if(children[next] == NULL) children[next] = new TrieNode();
            children[next]->insert(key + 1, r);
        }
    }

    TrieNode* find(const char* key) {
        if(*key == 0) return this;
        int next = toNumber(*key);
        if(children[next]==NULL) return NULL;
        return children[next]->find(key+1);
    }
};

int main() {
    int c;
    cin >> c;
    // find할 때에는 찾을 때마다 횟수를 증가시키면서 
}

