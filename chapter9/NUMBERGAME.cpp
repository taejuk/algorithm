#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int MIN = INT_MIN;
vector<int> board;
int cache[100000];
// used: 현재 board의 상태
// turn: 0일 경우, first, 1일 경우 second
// return: 현재 turn인 사람이 낼 수 있는 최대 점수 차
int numbergame(int used, int turn, int firstScore, int secondScore) {
    int boardSize = board.size();
    // board에 칸이 없는 경우
    if(used == (1 << boardSize) - 1) {
        return turn == 0 ? firstScore - secondScore : secondScore - firstScore;
    }
    //int &ret = cache[used];
    // if(ret != MIN) return ret;
    int ret = MIN;
    int rightMost=-1;
    int leftMost=-1;
    for(int i = 0; i < boardSize; i++) {
        if((used & (1 << i)) == 0) 
            if(leftMost == -1) {
                leftMost = i;
                break;
            }
    }

    for(int i = boardSize-1; i>=0; i--) {
        if((used & (1 << i)) == 0) 
            if(rightMost == -1) {
                rightMost = i;
                break;
            }
    }

    if(rightMost == leftMost) {
        ret = turn == 0 ? -1 * numbergame(used | (1 << rightMost), 1-turn, firstScore + board[rightMost], secondScore) : -1 * numbergame(used | (1 << rightMost), 1-turn, firstScore, secondScore + board[rightMost]);
        return ret;
    }
    
    // 왼쪽에서 두개 뺴는 경우
    ret = max(ret, -1 * numbergame(used | (1 << leftMost) | (1 << (leftMost + 1)),1-turn, firstScore, secondScore));
    // 왼쪽에서 하나 선택하는 경우
    ret = max(ret, -1 * numbergame(used | (1 << leftMost),1-turn, firstScore + (1-turn)*board[leftMost], secondScore + turn*board[leftMost]));
    // 오른쪽에서 두개 빼는 경우
    ret = max(ret, -1 * numbergame(used | (1 << rightMost) | (1 << (rightMost - 1)),1-turn, firstScore, secondScore));
    // 오른쪽에서 하나 선택하는 경우
    ret = max(ret, -1 * numbergame(used | (1 << rightMost),1-turn, firstScore + (1-turn)*board[rightMost], secondScore + turn*board[rightMost]));
    return ret;
}





int main() {
    for(int i = 0; i < 100000; i++) cache[i] = MIN;
    vector<int> newboard = {7,-5,8,5,1,-4,-8,6,7,9};
    board = newboard;
    cout << numbergame(0, 0, 0, 0) << endl;
}