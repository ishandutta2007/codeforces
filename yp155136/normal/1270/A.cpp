#include <bits/stdc++.h>
using namespace std;

int main () {
    int T; cin >> T;
    while (T--) {
        int n, k1, k2; cin >> n >> k1 >> k2;
        int mx1 = 0, mx2 = 0;
        while (k1--) {
            int x; cin >> x;
            mx1 = max(mx1, x);
        }
        while (k2--) {
            int x; cin >> x;
            mx2 = max(mx2, x);
        }
        if (mx1 > mx2) puts("YES");
        else puts("NO");
    }
}