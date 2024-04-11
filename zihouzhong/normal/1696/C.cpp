#include <bits/stdc++.h>
using namespace std;

const int maxn = 50010;
int T, n, m, k, a[maxn], b[maxn], c[maxn], d[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i], c[i] = 1;
            while (!(a[i] % m)) a[i] /= m, c[i] *= m;
        }
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> b[i], d[i] = 1;
            while (!(b[i] % m)) b[i] /= m, d[i] *= m;
        }
        int s = 1, t = 1;
        while (s <= n && t <= k) {
            if (a[s] ^ b[t]) break;
            int v = a[s];
            long long l = 0, r = 0;
            while (s <= n && a[s] == v) l += c[s++];
            while (t <= k && b[t] == v) r += d[t++];
            if (l ^ r) { s = n; break; }
        }
        if (s > n && t > k) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}