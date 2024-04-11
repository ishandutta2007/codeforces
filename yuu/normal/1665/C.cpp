#include <bits/stdc++.h>
using namespace std;
int n;
int c[200001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) c[i] = 0;
    c[0] = 1;
    for (int i = 2, p; i <= n; i++) {
        cin >> p;
        c[p]++;
    }

    sort(c, c + n + 1);
    reverse(c, c + n + 1);

    while (c[n] == 0) n--;
    priority_queue<int> q;
    for (int i = 0; i <= n; i++) q.push(c[i] + i);

    int ans = n + 1;
    while (q.top() > ans) {
        ans++;
        q.push(q.top() - 1);
        q.pop();
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