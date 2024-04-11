#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 500006;
const ll mod = 1000000007;
vector<int> x[N];

int p[N]; // point to ???

int Find(int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
}

void Union(int par, int son) {
    p[Find(son)] = Find(par);
}

bool used[N];

int main () {
    int n, m; scanf("%d%d", &n, &m);
    vector<int> ans_idx;
    for (int i = 1; i <= m; ++i) {
        p[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        int k; scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            int a; scanf("%d", &a);
            x[i].push_back(a);
        }
        if (k == 1) {
            int _ = x[i][0];
            int pp = Find(_);
            if (used[pp]) continue;
            else {
                used[pp] = true;
                ans_idx.push_back(i);
            }
        }
        else {
            int _ = x[i][0];
            int __ = x[i][1];
            if (_ > __) swap(_, __);
            // _ < __
            int p1 = Find(_);
            int p2 = Find(__);
            if (p1 < p2) {
                swap(p1, p2);
                swap(_, __);
            }
            // cerr << "p1 = " << p1 << " , p2 = " << p2 << endl;
            if (p1 == p2) continue;
            if (!used[p1]) {
                used[p1] = true;
                ans_idx.push_back(i);
                Union(__, p1);
            }
            else if (!used[p2]) {
                used[p2] = true;
                ans_idx.push_back(i);
                Union(_, p2);
            }
        }
    }
    ll ans1 = 1;
    for (int i = 0; i < (int)ans_idx.size(); ++i) {
        ans1 *= 2;
        ans1 %= mod;
    }
    printf("%lld %d\n", ans1, (int)ans_idx.size());
    for (int i = 0; i < (int)ans_idx.size(); ++i) {
        printf("%d%c", ans_idx[i], " \n"[i == (int)ans_idx.size() - 1]);
    }
}