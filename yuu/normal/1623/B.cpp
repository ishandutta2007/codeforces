#include <bits/stdc++.h>
using namespace std;
int n;
int l[1001];
int r[1001];
void solve(int begin, int end) {
    if (begin == end) {
        cout << begin << ' ' << end << ' ' << begin << '\n';
        return;
    }
    int d = begin;
    for (int i = 1; i <= n; i++)
        if ((l[i] == begin) && (r[i] < end)) d = max(d, r[i] + 1);
    if (d == begin) {
        cout << begin << ' ' << end << ' ' << begin << '\n';
        solve(begin + 1, end);
    } else {
        cout << begin << ' ' << end << ' ' << d << '\n';
        solve(begin, d - 1);
        if (d + 1 <= end) solve(d + 1, end);
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    solve(1, n);
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}