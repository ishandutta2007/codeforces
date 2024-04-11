#include <bits/stdc++.h>
using namespace std;
int a, b;
int get(int x) {
    if (b == 1) return 1e9;
    int res = 0;
    while (x) {
        x /= b;
        res++;
    }
    return res;
}
void solve() {
    cin >> a >> b;
    int ans = 1e9;
    for (int i = 0; i <= 30; i++) {
        ans = min(ans, i + get(a));
        b++;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}