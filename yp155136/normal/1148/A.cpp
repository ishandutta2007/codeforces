#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    ll a,b,c; cin >> a >> b >> c;
    ll ans = c*2;
    if (a>0) {
        --a;
        ++ans;
    }
    ll mn = min(a,b);
    ans += 2*mn;
    if (mn == a) {
        ans += min(b-a,2ll);
    }
    cout << ans << endl;
}