#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    priority_queue<int> sa, sb;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        while (a % 2 == 0) a /= 2;
        sa.push(a);
    }
    for (int i = 1, b; i <= n; i++) {
        cin >> b;
        while (b % 2 == 0) b /= 2;
        sb.push(b);
    }
    while (!sa.empty()) {
        auto a = sa.top();
        sa.pop();
        while (sb.top() >= a) {
            auto b = sb.top();
            sb.pop();
            while (b > a) b /= 2;
            if (b == a) goto next_a;
            sb.push(b);
        }
        cout << "NO\n";
        return;
    next_a:;
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