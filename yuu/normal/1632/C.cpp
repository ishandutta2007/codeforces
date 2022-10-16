#include <bits/stdc++.h>
using namespace std;
int bit_a[21];
int bit_b[21];
int get_diff(int a, int b) {
    int ans = 0;
    while ((a | b) != b) {
        int add = 1 << __lg(a & (~b));
        ans += add - a % add;
        a += add - a % add;
    }
    return ans;
    // int weight = 1;
    // int ans = 1e9;
    // for (int i = 0; i <= 20; i++) {
    //     bit_a[i] = a % 2;
    //     bit_b[i] = b % 2;
    //     a /= 2;
    //     b /= 2;
    // }
    // for (int i = 20; i >= 0; i--)
    //     if (bit_b[i]) {
    //     }
    // return ans;
}
int a, b;
void solve() {
    cin >> a >> b;
    int lim = b * 2;
    int cost = 0;
    int best = b - a;
    while (b <= lim) {
        best = min(best, cost + get_diff(a, b) + 1);
        cost++;
        b++;
    }
    cout << best << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}