#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 10;

int n, m, a[N], b[N], c[N], tot;

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);
    tot = unique(b + 1, b + n + 1) - b - 1;

    for (int i = 1; i <= n; i++) {
        c[lower_bound(b + 1, b + tot + 1, a[i]) - b]++;
    }

    m *= 8, m /= n;
    m = min(m, 20);
    int len = min(tot, 1<<m), ans = 0, sum = 0;

    for (int i = 1; i <= tot; i++) {
        sum += c[i];

        if (i > len) {
            sum -= c[i - len];
        }

        ans = max(ans, sum);
    }

    cout<<n - ans<<'\n';
}