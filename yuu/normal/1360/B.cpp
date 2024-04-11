#include <bits/stdc++.h>
using namespace std;
int n;
int s[51];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    sort(s + 1, s + n + 1);
    for (int i = n; i >= 2; i--) s[i] -= s[i - 1];
    cout << *min_element(s + 2, s + n + 1) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}