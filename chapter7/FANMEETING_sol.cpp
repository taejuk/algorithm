#include <iostream>
#include <vector>

using namespace std;

// bit 연산자로 바꾸면 되나?
// 분할이니깐 어떤 기준으로 분할하면 될까?
// 곱으로 분할하면 될까?

int hugs(const string& members, const string& fans) {
    int N = members.size(), M = fans.size();
    vector<int> A(N), B(M);
    for(int i = 0; i < N; ++i) A[i] = (members[i] == 'M');
    for(int i = 0; i < M; ++i) B[M-i-1] = (fans[i] == 'M');
    // C는 A*B이다
    vector<int> C;

    int allHugs = 0;
    for(int i=N-1; i < M; ++i) {
        if(C[i] == 0) ++allHugs;
    }
    return allHugs;
}