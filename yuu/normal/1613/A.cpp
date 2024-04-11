#include <bits/stdc++.h>
using namespace std;
int x1, x2, p1, p2;

void solve() {
    cin >> x1 >> p1 >> x2 >> p2;
    p1 -= p2;
    if (p1 > 0) {
        while ((p1 > 0) && (x1 <= x2)) {
            p1--;
            x1 *= 10;
        }
    } else if (p1 < 0) {
        while ((p1 < 0) && (x2 <= x1)) {
            p1++;
            x2 *= 10;
        }
    }
    if (x1 < x2)
        cout << "<\n";
    else if (x1 == x2)
        cout << "=\n";
    else
        cout << ">\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}