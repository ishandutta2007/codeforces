#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool chk_(ll l, ll r) {
    cout<<l<<' '<<r<<'\n';
    cout.flush();
    string s;
    cin>>s;

    if (s[0] == 'B') {
        exit(0);
    }

    return s[0] == 'Y';
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));

    ll n, k, l, r;
    cin>>n>>k;
    l = 1, r = n;

    while (1) {
        if (r - l + 1 <= 5*k + 10) {
            ll pos = l + rand()%(r - l + 1);

            if (chk_(pos, pos)) {
                exit(0);
            } 

            l = max(1ll, l - k);
            r = min(n, r + k);
            continue;
        }

        ll mid = (l + r)>>1;

        if (chk_(l, mid)) {
            l = max(1ll, l - k);
            r = min(mid + k, n);
        } else {
            l = max(1ll, mid + 1 - k);
            r = min(r + k, n);
        }
    }
}