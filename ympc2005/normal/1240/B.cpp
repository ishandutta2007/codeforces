#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, a[N], b[N], m, l[N], r[N];

void work_() {
    cin>>n;

    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);
    m = unique(b + 1, b + n + 1) - b - 1;

    for (int i = 1; i <= m; i++) {
        l[i] = n + 1;
        r[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }

    int ans = m;

    for (int i = 1, j; i <= m; i = j + 1) {
        j = i;

        while (j < m && r[j] < l[j + 1]) {
            j++;
        }

        ans = min(ans, m - (j - i + 1));
    }

    cout<<ans<<'\n';
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;

    while (T--) {
        work_();
    }
}