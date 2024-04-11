#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;
int T, n, a[maxn], f[maxn], cnt[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        fill(f + 1, f + n + 2, -1e9);
        for (int i = 1; i <= n + 1; i++) {
            fill(cnt + 1, cnt + n + 1, 0);
            int mx = 0;
            for (int j = i - 1; ~j; j--) {
                if ((i - j) % 2 && mx <= (i - j - 1) / 2 && (i > n || !j || a[i] == a[j])) {
                    f[i] = max(f[i], f[j] + 1);
                }
                mx = max(mx, ++cnt[a[j]]);
            }
        }
        cout << f[n + 1] - 1 << "\n";
    }
    return 0;
}