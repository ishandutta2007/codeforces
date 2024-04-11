#include <bits/stdc++.h>
using namespace std;
int n;
int a[101];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        cin >> s;
        for (auto&& c : s) {
            if (c == 'D') {
                a[i]++;
            } else {
                a[i]--;
            }
        }
        ((a[i] %= 10) += 10) %= 10;
        cout << a[i] << " \n"[i == n];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}