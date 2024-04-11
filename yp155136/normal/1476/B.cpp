#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 106;

ll p[N];

bool ok(ll mid, ll n, int k) {
    ll now = p[0] + mid;
    for (int i = 1; i < n; ++i) {
        if (p[i] * 100 > now * k) return false;
        now += p[i];
    }
    return true;
}

int main () {
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        ll l = -1, r = (1ll << 40);
        while (r - l != 1) {
            ll mid = (l + r) >> 1;
            if (ok(mid, n, k)) r = mid;
            else l = mid;
        }
        cout << r << endl;
    }
}