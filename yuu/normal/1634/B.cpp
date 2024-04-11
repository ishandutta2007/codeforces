#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    int64_t y;
    cin >> n >> x >> y;
    int a;
    x %= 2;
    while (n--) {
        cin >> a;
        (x += a) %= 2;
    }
    (y += x) %= 2;
    if (y)
        cout << "Bob\n";
    else
        cout << "Alice\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}