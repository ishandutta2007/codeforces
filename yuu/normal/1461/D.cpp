#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[100001];
int64_t s[100001];
set<int64_t> good;
void make(int l, int r) {
    if (l > r) return;
    good.insert(s[r] - s[l - 1]);
    if (a[l] == a[r]) return;
    int pivot = (a[r] + a[l]) / 2;
    for (int m = l; m <= r; m++)
        if (a[m] > pivot) {
            make(l, m - 1);
            make(m, r);
            return;
        }
}
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    good.clear();
    make(1, n);
    for (int i = 1, s; i <= q; i++) {
        cin >> s;
        if (good.find(s) != good.end()) cout << "Yes\n";
        else cout << "No\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}