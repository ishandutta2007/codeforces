#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, m, a[N], b[N];

ll ans;

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;

    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin>>b[i];
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    if (a[n] > b[1]) {
        cout<<-1<<'\n';
        exit(0);
    } 

    if (a[n] == b[1]) {
        for (int i = 1; i < n; i++) {
            ans += 1ll*a[i]*m;
        }

        for (int i = 1; i <= m; i++) {
            ans += b[i];
        }
    } else {
        for (int i = 1; i < n - 1; i++) {
            ans += 1ll*a[i]*m;
        }

        ans += 1ll*(m - 1)*a[n - 1] + a[n];

        for (int i = 1; i <= m; i++) {
            ans += b[i];
        }
    }

    cout<<ans<<'\n';
}