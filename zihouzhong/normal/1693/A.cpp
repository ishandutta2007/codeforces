#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n;
long long a[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        while (n > 1 && !a[n]) n--;
        if (n == 1) {
            cout << (a[1] ? "NO\n" : "YES\n"); continue;
        }
        for (int i = 1; i < n; i++) {
            a[i]--, a[i + 1]++;
        }
        bool flag = 1;
        long long s = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < 0) {
                long long t = min(s, -a[i]);
                a[i] += t, s -= t;
            }
            if (a[i] < 0) flag = 0;
            s += a[i], a[i] = 0;
        }
        if (s) flag = 0;
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}