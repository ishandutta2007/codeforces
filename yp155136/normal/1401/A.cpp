#include <bits/stdc++.h>
using namespace std;

int main () {
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        int ans = max(0, k - n);
        n += max(0, k - n);
        if (n % 2 != k % 2) ++ans;
        cout << ans << endl;
    }
}