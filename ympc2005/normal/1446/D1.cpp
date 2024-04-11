#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, S = 300;

int n, a[N], col, sz[N], ans, p[N<<1], c[N], lim, cnt;

void solve1_(int x) {
    for (int i = -n; i <= n; i++) {
        p[i + n] = n + 1;
    }

    p[n] = 0;
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += x == a[i];
        sum -= col == a[i];
        ans = max(ans, i - p[sum + n]);
        p[sum + n] = min(p[sum + n], i);
    }
}

void add_(int x) {
    c[x]++;

    if (x != col && c[x] == lim) {
        cnt++;
    }
}

void del_(int x) {
    c[x]--;

    if (x != col && c[x] == lim - 1) {
        cnt--;
    }
}

void solve2_() {
    for (int i = 1; i <= n; i++) {
        c[i] = 0;
    }

    cnt = 0;

    for (int i = 1, j = 1; i <= n; i++) {
        add_(a[i]);

        while (c[col] > lim) {
            del_(a[j++]);
        }

        if (cnt) {
            ans = max(ans, i - j + 1);
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sz[a[i]]++;

        if (sz[a[i]] > sz[col]) {
            col = a[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (sz[i] >= S && i != col) {
            solve1_(i);
        }
    }

    for (int i = 1; i < S; i++) {
        lim = i;
        solve2_();
    }

    printf("%d\n", ans);
}