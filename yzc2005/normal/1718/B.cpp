#include <bits/stdc++.h>
using namespace std;
int k, c[105], p[105];
long long f[100];
void solve() {
    cin >> k;
    long long sum = 0;
    for (int i = 1; i <= k; ++i) {
        cin >> c[i];
        sum += c[i];
    }
    int pos = 0;
    while (sum >= f[pos]) {
        sum -= f[pos];
        ++pos;
    }
    if (sum) {
        cout << "NO\n";
        return;
    }
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= k; ++i) {
        pq.emplace(c[i], i);
    }
    p[pos] = 0;
    for (int i = pos - 1; ~i; --i) {
        if (pq.empty()) {
            cout << "NO\n";
            return;
        }
        auto cur = pq.top();
        pair<int, int> tmp{-1, -1};
        if (cur.second == p[i + 1]) {
            pq.pop();
            tmp = cur;
            if (pq.empty()) {
                cout << "NO\n";
                return;
            }
            cur = pq.top();
        }
        pq.pop();
        if (cur.first < f[i]) {
            cout << "NO\n";
            return;
        }
        cur.first -= f[i];
        p[i] = cur.second;
        if (cur.first) {
            pq.push(cur);
        }
        if (~tmp.first) {
            pq.push(tmp);
        }
    }
    cout << "YES\n";
}
int main() {
    f[0] = f[1] = 1;
    for (int i = 2; i <= 90; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}