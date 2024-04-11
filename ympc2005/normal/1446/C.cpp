#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, rt, ch[N<<5][2], tot, f[N<<5];

void ins_(int &o, int k, int x) {
    if (!o) {
        o = ++tot;
    }

    if (k >= 0) {
        ins_(ch[o][(x>>k)&1], k - 1, x);
    }
}

void solve_(int o, int k) {
    if (!o) {
        return;
    }

    if (k == -1) {
        f[o] = 1;
        return;
    }

    solve_(ch[o][0], k - 1);
    solve_(ch[o][1], k - 1);

    for (int i = 0; i < 2; i++) {
        f[o] = max(f[o], f[ch[o][i]] + (ch[o][i^1] > 0));
    }
}

int main() {
    scanf("%d", &n);

    for (int x, i = 1; i <= n; i++) {
        scanf("%d", &x);
        ins_(rt, 29, x);
    }

    solve_(rt, 29);
    printf("%d\n", n - f[rt]);
}