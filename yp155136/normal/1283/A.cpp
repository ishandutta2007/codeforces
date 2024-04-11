#include <bits/stdc++.h>
using namespace std;

int main () {
    int T; cin >> T;
    while (T--) {
        int a, b; cin >> a >> b;
        int ans = 0;
        while (a != 0 || b != 0) {
            ++b;
            ++ans;
            if (b == 60) {
                ++a;
                b = 0;
            }
            if (a == 24) {
                a = 0;
            }
        }
        cout << ans << endl;
    }
}