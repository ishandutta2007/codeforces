#include <bits/stdc++.h>
using namespace std;

void go() {
    int n; cin >> n;
    int ans = 0;
    while (n != 1) {
        if (n % 6 == 0) {
            n /= 6;
        }
        else if (n % 3 == 0) {
            n *= 2;
        }
        else {
            cout << -1 << endl;
            return;
        }
        ++ans;
    }
    cout << ans << endl;
}

int main () {
    int T; cin >> T;
    while (T--) {
        go();
    }
}