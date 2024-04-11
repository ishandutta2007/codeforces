#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    ll a, b, c; cin >> a >> b >> c;
    ll ans = a;
    for (int i = 0; i <= 10000000ll; ++i) {
        if (b * i > a) break;
        ans = min(ans, (a - b * i) % (5 * c));
    }
    cout << ans << endl;
}