#include <bits/stdc++.h>
using namespace std;

const int N = 200006;

vector<int> a[N];

int main () {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        a[i].resize(m);
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            --a[i][j];
        }
    }
    int ans = 0;
    for (int j = 0; j < m; ++j) {
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; ++i) {
            if (a[i][j] % m == j) {
                if (a[i][j] < n * m) cnt[ (-a[i][j] / m + i + n) % n ]++;
            }
        }
        int mn = n;
        for (int i = 0; i < n; ++i) {
            mn = min(mn, n - cnt[i] + i);
        }
        ans += mn;
    }
    printf("%d\n", ans);
}