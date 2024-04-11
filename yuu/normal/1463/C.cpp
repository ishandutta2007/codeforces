#include <bits/stdc++.h>
using namespace std;
int n;
int64_t t[100002];
int64_t x[100002];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i] >> x[i];
    t[n + 1] = 1e18;
    int64_t pos = 0;
    int64_t start_time = 0;
    int64_t dir = 0;
    int64_t end_time = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (end_time <= t[i]) {
            pos += dir * (end_time - start_time);
            start_time = t[i];
            end_time = abs(x[i] - pos) + start_time;
            dir = (x[i] > pos) ? 1 : -1;
        } else {
            pos += dir * (t[i] - start_time);
            start_time = t[i];
        }
        int64_t finish;
        if (end_time <= t[i + 1]) finish = pos + dir * (end_time - start_time);
        else finish = pos + dir * (t[i + 1] - start_time);
        if (((pos <= x[i]) && (finish >= x[i])) || ((pos >= x[i]) && (finish <= x[i]))) ans++;
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