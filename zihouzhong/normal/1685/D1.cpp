#include <bits/stdc++.h>
using namespace std;

const int maxn = 210;
int T, n, p[maxn], fa[maxn], pre[maxn], nxt[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i], pre[p[i]] = i;
        }
        iota(fa + 1, fa + n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fa[find(i)] = find(nxt[i] = pre[i]);
        }
        for (int i = 2; i <= n; i++) if (find(i - 1) ^ find(i)) {
            int t = nxt[i - 1];
            nxt[i - 1] = pre[i], nxt[i] = t;
            fa[find(i)] = find(i - 1);
        }
        for (int i = 1, j = 1; i <= n; i++) {
            cout << j << " ", j = nxt[j];
        }
        cout << "\n";
    }
    return 0;
}