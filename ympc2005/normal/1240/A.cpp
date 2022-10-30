#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n, p[N], a, x, b, y;

ll m;

bool chk_(int cur) {
    cur = min(cur, n);
    int cx = cur/a, cy = cur/b;
    ll d = 1ll*a/__gcd(a, b)*b;
    int cz = cur/d;
    cx -= cz, cy -= cz;
    ll sum = m;

    for (int i = 1; i <= cz; i++) {
        sum -= 1ll*(x + y)*p[i];
    } 

    for (int i = cz + 1; i <= cz + cx; i++) {
        sum -= 1ll*x*p[i];
    }

    for (int i = cz + cx + 1; i <= cz + cx + cy; i++) {
        sum -= 1ll*y*p[i];
    }

    return sum <= 0;
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;

    while (T--) {
        cin>>n;

        for (int i = 1; i <= n; i++) {
            cin>>p[i];
            p[i] /= 100;
        }

        cin>>x>>a>>y>>b;

        if (x < y) {
            swap(x, y);
            swap(a, b);
        }

        sort(p + 1, p + n + 1);
        reverse(p + 1, p + n + 1);
        cin>>m;
        int l = 1, r = n + 1;

        while (l < r) {
            int mid = (l + r)>>1;

            if (chk_(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        cout<<(l <= n ? l : -1)<<'\n';
    }
}