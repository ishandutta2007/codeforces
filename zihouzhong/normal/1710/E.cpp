#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, a[maxn], b[maxn], c[maxn], d[maxn];
long long cs[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    int foo = a[1], bar = b[1];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int px = find(a + 1, a + n + 1, foo) - a;
    int py = find(b + 1, b + m + 1, bar) - b;
    auto chk = [&](int lim) {
        for (int i = 1, j = m; i <= n; i++) {
            while (j && a[i] + b[j] > lim) j--;
            cs[i] = cs[i - 1] + (c[i] = j);
        }
        for (int i = m, j = 0; ~i; i--) {
            while (j < n && c[j + 1] > i) j++;
            d[i] = j;
        }
        auto calc = [&](int i, int j, bool flag = 0) {
            int t = min(i, d[j]);
            long long s = 1LL * j * t + cs[i] - cs[t];
            t = max(i, d[j]);
            s += 1LL * m * (n - i) - (cs[t] - cs[i]) - 1LL * j * (n - t);
            if (flag) {
                if (foo + bar <= lim && px <= i && py <= j) s--;
                if (foo + bar > lim && px > i && py > j) s--;
            }
            return s;
        };
        long long ans1 = 0, ans2 = 0;
        for (int i = 0, j = 0; i <= n; i++) {
            while (j < m && calc(i, j) <= calc(i, j + 1)) j++;
            ans1 = max(ans1, calc(i, j));
        }
        for (int i = 0, j = 0; i <= n; i++) {
            while (j < m && calc(i, j, 1) <= calc(i, j + 1, 1)) j++;
            ans2 = max(ans2, calc(i, j, 1));
        }
        return ans1 == ans2;
    };
    int ans = foo + bar, l = 0, r = ans - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        chk(mid) ? r = (ans = mid) - 1 : l = mid + 1;
    }
    cout << ans << "\n";
    return 0;
}