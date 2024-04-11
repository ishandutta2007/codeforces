#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
map<int, int> cnt;
void solve() {
    cin >> n;
    cnt.clear();
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        cnt[a]++;
    }
    n = 0;
    int added = 0;
    for (auto&& [x, c] : cnt) {
        if (c > 1) added++;
        else a[++n] = x;
    }
    cout << added + (n + 1) / 2 << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}