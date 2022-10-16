#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
void solve() {
    cin >> n >> m;
    cin >> s;
    int cnt_1 = 0;
    for (auto&& c : s)
        if (c == '1') cnt_1++;
    int req_1 = 0;
    if (cnt_1 == 0) {
        req_1 = 0;
    } else {
        // cnt_1 / n == req_1 / m
        req_1 = static_cast<int64_t>(m) * cnt_1 / n;
    }
    if (static_cast<int64_t>(m) * cnt_1 != static_cast<int64_t>(n) * req_1) {
        cout << "-1\n";
        return;
    }
    int head = 0;
    int current = 0;
    for (int i = 0; i < n; i++) {
        while (head < i + m) {
            current += (s[head % n] == '1');
            head++;
        }
        if (req_1 == current) {
            if (i + m <= n) {
                cout << "1\n";
                cout << i + 1 << ' ' << i + m << '\n';
            } else {
                cout << "2\n";
                cout << 1 << ' ' << i + m - n << '\n';
                cout << i + 1 << ' ' << n << '\n';
            }
            return;
        }
        current -= (s[i] == '1');
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}