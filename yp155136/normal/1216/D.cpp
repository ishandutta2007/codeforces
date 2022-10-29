#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200006;

ll a[N];

int main () {
    int n; scanf("%d", &n);
    ll gcd = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; ++i) {
        gcd = __gcd(gcd, a[i + 1] - a[i]);
    }
    ll y = 0, z = gcd;
    ll mx = *max_element(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        y += (mx - a[i]) / gcd;
    }
    cout << y << ' ' << z << endl;
}