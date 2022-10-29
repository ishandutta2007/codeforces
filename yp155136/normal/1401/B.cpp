#include <bits/stdc++.h>
using namespace std;

int main () {
    int T; cin >> T;
    while (T--) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;
        int _cnt = min(y2, z1);
        int ans = 2 * _cnt;
        y2 -= _cnt;
        z1 -= _cnt;
        y1 -= (x2 + y2);
        z2 -= (x1 + z1);
        if (y1 > 0 && z2 > 0) {
            ans -= 2 * min(y1, z2);
        }
        cout << ans << endl;
    }
}