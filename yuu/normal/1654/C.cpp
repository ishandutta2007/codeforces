#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
    cin >> n;
    priority_queue<int> a;
    priority_queue<int64_t> c;
    int64_t sum = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        a.push(x);
        sum += x;
    }
    c.push(sum);
    int cut = 0;
    while (!a.empty()) {
        auto x = a.top();
        a.pop();
        while (!c.empty()) {
            auto y = c.top();
            c.pop();
            if (x == y) break;
            if (x > y) {
                cout << "NO\n";
                return;
            }
            cut++;
            if (cut >= n) {
                cout << "NO\n";
                return;
            }
            c.push(y / 2);
            c.push(y - y / 2);
        }
    }
    cout << "YES\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}