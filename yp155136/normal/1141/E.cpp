#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 222222;

ll a[N];

int main () {
    ll h,n; cin >> h >> n;
    ll pre=0;
    ll mn_pre = (1ll<<60);
    for (int i=1;i<=n;++i) {
        cin >> a[i];
        pre += a[i];
        mn_pre = min(mn_pre,pre);
        if (h + pre <= 0) {
            cout << i << endl;
            return 0;
        }
    }
    if (pre >= 0) {
        cout << -1 << endl;
        return 0;
    }
    ll L=0,R = (1ll<<40);
    while (R-L != 1) {
        ll mid=(L+R)>>1;
        ll hh = h;
        if (log10(-pre) + log10(mid) >= 18) {
            R = mid;
            continue;
        }
        hh += pre*mid;
        if (hh <= 0) {
            R = mid;
            continue;
        }
        bool okay = false;
        for (int i=1;i<=n;++i) {
            hh += a[i];
            if (hh <= 0) {
                okay = true;
                break;
            }
        }
        if (okay) R = mid;
        else L = mid;
    }
    //R is the answer
    ll ans = n * R;
    h += R * pre;
    for (int i=1;i<=n;++i) {
        h += a[i];
        if (h <= 0) {
            cout << ans + i << endl;
            return 0;
        }
    }
}