#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll a,b;
    cin >> a >> b;
    if (a-b == 1) {
        ll y = a+b;
        for (ll i=2;i*i<=y;++i) {
            if (y%i==0) {
                puts("NO");
                return;
            }
        }
        puts("YES");
    }
    else puts("NO");
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}