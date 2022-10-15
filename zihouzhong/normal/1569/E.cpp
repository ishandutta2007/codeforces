#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;
int K, A, h, pw[100], ans[32];
vector<pair<int, int>> L1[32], L2[32], R1[32], R2[32];

int main() {
    scanf("%d %d %d", &K, &A, &h);
    for (int i = pw[0] = 1; i < 100; i++) {
        pw[i] = 1LL * A * pw[i - 1] % P;
    }
    int m = 1 << (K - 1);
    for (int i = 0; i < 1 << (m - 1); i++) {
        int tot = 0;
        function<pair<int, int>(int, int)> solve = [&](int l, int r) {
            if (l == r) return make_pair(l, 0);
            int mid = (l + r) >> 1;
            auto p1 = solve(l, mid), p2 = solve(mid + 1, r);
            int t = (1 << K) / (r - l + 1) + 1;
            if (i >> tot++ & 1) {
                int s = (p1.second + p2.second) % P;
                s = (s + 1LL * pw[t] * (p2.first + 1)) % P;
                return make_pair(p1.first, s);
            } else {
                int s = (p1.second + p2.second) % P;
                s = (s + 1LL * pw[t] * (p1.first + 1)) % P;
                return make_pair(p2.first, s);
            }
        };
        auto p = solve(0, m - 1);
        L1[p.first].emplace_back((p.second + 1LL * (p.first + 1) * pw[2]) % P, i);
        L2[p.first].emplace_back((p.second + 1LL * (p.first + 1) * pw[1]) % P, i);
        tot = 0, p = solve(m, (1 << K) - 1);
        R1[p.first].emplace_back((p.second + 1LL * (p.first + 1) * pw[2]) % P, i);
        R2[p.first].emplace_back((p.second + 1LL * (p.first + 1) * pw[1]) % P, i);
    }
    for (int i = 0; i < 1 << K; i++) {
        sort(L1[i].begin(), L1[i].end());
        sort(L2[i].begin(), L2[i].end());
        sort(R1[i].begin(), R1[i].end());
        sort(R2[i].begin(), R2[i].end());
    }
    auto print = [&](int S1, int S2) {
        int tot = 0, S;
        function<int(int, int)> solve = [&](int l, int r) {
            if (l == r) return l;
            int mid = (l + r) >> 1;
            int x = solve(l, mid), y = solve(mid + 1, r);
            int t = (1 << K) / (r - l + 1) + 1;
            if (S >> tot++ & 1) { ans[y] = t; return x; }
            ans[x] = t; return y;
        };
        S = S1, solve(0, m - 1);
        S = S2, tot = 0, solve(m, (1 << K) - 1);
        for (int i = 0; i < 1 << K; i++) printf("%d ", ans[i]);
        exit(0);
    };
    for (int i = 0; i < m; i++) {
        for (int j = m; j < 1 << K; j++) {
            for (auto &S : L1[i]) {
                auto it = lower_bound(R2[j].begin(), R2[j].end(), make_pair((P + h - S.first) % P, 0));
                if (it == R2[j].end() || it->first != (P + h - S.first) % P) continue;
                ans[i] = 2, ans[j] = 1;
                print(S.second, it->second);
            }
            for (auto &S : L2[i]) {
                auto it = lower_bound(R1[j].begin(), R1[j].end(), make_pair((P + h - S.first) % P, 0));
                if (it == R1[j].end() || it->first != (P + h - S.first) % P) continue;
                ans[i] = 1, ans[j] = 2;
                print(S.second, it->second);
            }
        }
    }
    puts("-1");
    return 0;
}