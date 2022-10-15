#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int T, n, a[maxn], b[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        vector<array<int, 2>> res;
        auto op = [&](int l, int r) {
            reverse(a + l, a + r + 1), res.push_back({l, r});
        };
        bool flag = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] ^ b[i]) { flag = 0; break; }
            if (a[i + 1] == b[i + 1]) continue;
            for (int j = i + 1; j <= n; j++) {
                if (a[i] == a[j] && b[i + 1] == a[j - 1]) { op(i, j); break; }
            }
            if (a[i + 1] == b[i + 1]) continue;
            int p = 0;
            for (int j = i; j < n; j++) {
                if (a[i] == a[j] && b[i + 1] == a[j + 1]) { p = j; break; }
            }
            if (!p) { flag = 0; break; }
            for (int j = i; j <= p; j++) {
                for (int k = p + 1; k <= n; k++) {
                    if (a[j] == a[k]) { op(j, k); goto next; }
                }
            }
        next:
            for (int j = i + 1; j <= n; j++) {
                if (a[i] == a[j] && b[i + 1] == a[j - 1]) { op(i, j); break; }
            }
        }
        if (!flag || a[n] ^ b[n]) { cout << "NO\n"; continue; }
        cout << "YES\n" << res.size() << "\n";
        for (auto &p : res) {
            cout << p[0] << " " << p[1] << "\n";
        }
    }
    return 0;
}