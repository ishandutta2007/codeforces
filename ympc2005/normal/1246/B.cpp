#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, m, a[N], c[N];

ll mx = 1e9, ans, b[N], d[N];

void calc_(int u, int p, int k) {
    for (int i = 1; i <= k; i++) {
        b[u] = min(b[u]*p, mx);
    }

    for (int i = 1; i <= (m - k)%m; i++) {
        d[u] = min(d[u]*p, mx);
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        b[i] = d[i] = 1;

        for (int j = 2; 1ll*j*j <= a[i]; j++) {
            if (a[i]%j == 0) {
                int cnt = 0;

                while (a[i]%j == 0) {
                    a[i] /= j;
                    cnt++;
                }

                cnt = (m - cnt%m)%m;
                calc_(i, j, cnt);
            }
        }

        if (a[i] > 1) {
            calc_(i, a[i], m - 1);
        }

        if (b[i] <= 1e5 && d[i] <= 1e5) {
            ans += c[d[i]];
            c[b[i]]++;
        }
    }

    cout<<ans<<'\n';
}