#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int n, a[N];

ll ans = 1e18, sum, b[N];

void solve_(ll x) {
    for (int i = 1; i <= n; i++) {
        b[i] = (b[i - 1] + a[i])%x;
    }

    ll res = 0;

    for (int i = 1; i < n; i++) {
        res += min(b[i], x - b[i]);
    }

    ans = min(ans, res);
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        sum += a[i];
    }

    if (sum == 1) {
        cout<<-1<<'\n';
        exit(0);
    }

    for (ll i = 2; i*i <= sum; i++) {
        if (sum%i == 0) {
            solve_(i);

            while (sum%i == 0) {
                sum /= i;
            }
        }
    }

    if (sum > 1) {
        solve_(sum);
    }

    cout<<ans<<'\n';
}