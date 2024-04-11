#include <bits/stdc++.h>

int N;
int A[6], B[110000];
std::vector<std::pair<int, int>> vec;
std::multiset<int> set;

int main() {
    for (int i = 0; i < 6; ++i) scanf("%d", &A[i]);
    std::sort(A, A + 6);
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", &B[i]);
    for (int i = 0; i < N; ++i) for (int j = 0; j < 6; ++j) {
        vec.push_back(std::make_pair(i, j));
    }
    std::sort(vec.begin(), vec.end(), [&](auto &a, auto &b) {
        if (B[a.first] - A[a.second] != B[b.first] - A[b.second])
            return B[a.first] - A[a.second] < B[b.first] - A[b.second];
        return a.second > b.second;
    });
    for (int i = 0; i < N; ++i) set.insert(B[i] - A[5]);
    int ans = *(--set.end()) - *set.begin();
    for (auto &x: vec) {
        ans = std::min(ans, *(--set.end()) - *set.begin());
        if (x.second > 0) {
            set.erase(set.find(B[x.first] - A[x.second]));
            set.insert(B[x.first] - A[x.second - 1]);
        }
    }
    printf("%d\n", ans);
}