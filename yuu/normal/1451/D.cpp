#include <bits/stdc++.h>
using namespace std;
int64_t d, k;
void solve() {
    cin >> d >> k;
    int64_t x = 0, y = 0;
    while (x * x + y * y <= d * d) {
        x += k;
        y += k;
    }
    x -= k;
    y -= k;
    if ((x + k) * (x + k) + y * y > d * d) {
        cout << "Utkarsh\n";
    } else {
        cout << "Ashish\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}