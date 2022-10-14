#include <bits/stdc++.h>

const long long MOD = 998244353;

int T;
int N, K;
int A[210000], B[210000];
int vis[210000];
int loc[210000];
std::set<int> set;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &K);
        for (int i = 1; i <= N; ++i) loc[i] = vis[i] = 0;
        for (int i = 1; i <= N; ++i) scanf("%d", &A[i]), loc[A[i]] = i;
        for (int i = 1; i <= K; ++i) scanf("%d", &B[i]), vis[B[i]] = true;
        set.clear();
        for (int i = 1; i <= N; ++i) set.insert(i);
        long long res = 1;
        for (int i = 1; i <= K; ++i) {
            long long mul = 2; bool rm = false;
            auto it = set.find(loc[B[i]]);
            if (it == set.begin()) {
                --mul;
            } else {
                auto prev = it; --prev;
                if (vis[A[*prev]]) {
                    --mul;
                } else {
                    set.erase(prev);
                    rm = true;
                }
            }
            if (it == --set.end()) {
                --mul;
            } else {
                auto next = it; ++next;
                if (vis[A[*next]]) {
                    --mul;
                } else {
                    if (!rm) set.erase(next);
                }
            }
            vis[B[i]] = false;
            res = res * mul % MOD;
        }
        printf("%lld\n", res);
    }
}