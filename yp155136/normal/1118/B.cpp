#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200006;

ll a[N];
ll pre[N];

int main () {
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    ll x=1;
    for (int i=1;i<=n;++i) {
        pre[i] = pre[i-1] + x*a[i];
        x *= -1;
    }
    ll ans=0;
    for (int i=1;i<=n;++i) {
        ll saki = pre[i-1];
        if (i %2 == 1) saki += (pre[n] - pre[i])*(-1);
        else saki += (pre[n] - pre[i])*(-1);
        if (saki == 0) ++ans;
    }
    cout << ans << endl;
}