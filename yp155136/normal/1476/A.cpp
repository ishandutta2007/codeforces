#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    int T; cin >> T;
    while (T--) {
        ll n, k; cin >> n >> k;
        if (k % n == 0) cout << k / n << endl;
        else if (k > n) cout << k / n + 1 << endl;
        else if (n % k != 0) cout << 2 << endl;
        else cout << 1 << endl;
    }
}