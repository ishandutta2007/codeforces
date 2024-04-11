#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    int T; cin >> T;
    while (T--) {
        ll a, b, n, m; cin >> a >> b >> n >> m;
        if (a + b >= n + m && m <= min(a, b)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}