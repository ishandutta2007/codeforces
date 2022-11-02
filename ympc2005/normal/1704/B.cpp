#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10, mod = 998244353;

int n, x, a[N];

void work_() {
    cin>>n>>x;
    int ans = 0, cl = -2e9, cr = 2e9;

    for (int v, i = 1; i <= n; i++) {
        cin>>v;
        int l = v - x, r = v + x;

        if (l > cr || r < cl) {
            ans++;
            cl = l;
            cr = r;
        } else {
            cl = max(cl, l);
            cr = min(cr, r);
        }
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