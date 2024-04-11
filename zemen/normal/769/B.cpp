#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <vector>
using namespace std;

const int N = 105;

int A[N];

void die() {
    puts("-1");
    exit(0);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    if (A[0] == 0) {
        die();
    }
    vector<int> zeroes;
    vector<int> non_zeroes;
    for (int i = 0; i < n; i++) {
        if (!A[i])
            zeroes.push_back(i);
        else
            non_zeroes.push_back(i);
    }
    vector<pair<int, int>> ans;
    assert(non_zeroes.front() == 0);
    for (int i = 0; i + 1 < (int)non_zeroes.size(); i++) {
        ans.emplace_back(non_zeroes[i], non_zeroes[i + 1]);
        --A[non_zeroes[i]];
    }
    int pt = 0;
    for (int i = 0; i < (int)zeroes.size(); i++) {
        while (pt != (int)non_zeroes.size() && A[non_zeroes[pt]] == 0)
            pt++;
        if (pt == (int)non_zeroes.size())
            die();
        A[non_zeroes[pt]]--;
        ans.emplace_back(non_zeroes[pt], zeroes[i]);
    }
    printf("%d\n", (int)ans.size());
    for (auto pr : ans) {
        printf("%d %d\n", pr.first + 1, pr.second + 1);
    }
}