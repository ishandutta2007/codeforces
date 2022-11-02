#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10, M = 35;

int n, ans, rt, tot, ch[N*M][2];

ll f[M], g[M];

vector <int> id[N*M];

void ins_(int &o, int x, int y, int k) {
    if (!o) {
        o = ++tot;
    }

    id[o].push_back(y);

    if (k == -1) {
        return;
    }

    ins_(ch[o][(x>>k)&1], x, y, k - 1);
}

void solve_(int o, int k) {
    if (k == -1 || !o) {
        return;
    }

    solve_(ch[o][0], k - 1);
    solve_(ch[o][1], k - 1);

    int lc = ch[o][0], rc = ch[o][1];

    if (!lc || !rc) {
        return;
    }

    for (int i = 0, j = 0; i < id[lc].size(); i++) {
        while (j < id[rc].size() && id[rc][j] < id[lc][i]) {
            j++;
        }

        f[k] += j;
    }

    for (int i = 0, j = 0; i < id[rc].size(); i++) {
        while (j < id[lc].size() && id[lc][j] < id[rc][i]) {
            j++;
        }

        g[k] += j;
    }
} 

int main() {
    scanf("%d", &n);

    for (int x, i = 1; i <= n; i++) {
        scanf("%d", &x);
        ins_(rt, x, i, 29);
    }

    solve_(rt, 29);

    ll mn = 0;

    for (int i = 0; i < 30; i++) {
        if (f[i] > g[i]) {
            ans |= 1<<i;
            mn += g[i];
        } else {
            mn += f[i];
        }
    }

    printf("%lld %d\n", mn, ans);
}