#include <bits/stdc++.h>
using namespace std;
int n;
constexpr int MAX = 1e6;
bool c[MAX + 1];
void solve() {
    cin >> n;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        c[a] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= MAX; i++) {
        int g = 0;
        for (int j = i; j <= MAX; j += i)
            if (c[j]) {
                g = gcd(g, j);
                if (g == i) break;
            }
        if (g == i) cnt++;
    }
    cout << cnt - n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}