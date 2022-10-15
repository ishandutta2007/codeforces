#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, a[1000010];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; ; i++) {
        int x = i;
        ll l = max(0LL, 1LL * x * x - a[1]), r = 1LL * x * (x + 1) - a[1];
        for (int j = 2; j <= n; j++) {
            j = lower_bound(a + j + 1, a + n + 1, a[j - 1] + x) - a - 1;
            while (1) {
                ll _l = 1LL * x * x - a[j], _r = 1LL * x * (x + 1) - a[j];
                if (x <= i + a[n] / i && max(l, _l) > min(r, _r)) x++;
                else { l = max(l, _l), r = min(r, _r); break; }
            }
        }
        if (l <= r) { cout << l << "\n"; break; }
    }
    return 0;
}