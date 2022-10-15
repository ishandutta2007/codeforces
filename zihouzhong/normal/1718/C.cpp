#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    vector<array<int, 2>> Q;
    vector<ll> res(q + 1);
    for (int i = 0, p, x; i < q; i++) {
        cin >> p >> x, p--;
        Q.push_back({p, x});
    }
    auto orig = a;
    for (int d = 1; d < n; d++) if (!(n % d)) {
        a = orig;
        priority_queue<ll> Q1, Q2;
        vector<ll> sum(d);
        for (int i = 0; i < d; i++) {
            for (int j = i; j < n; j += d) {
                sum[i] += 1LL * a[j] * d;
            }
            Q1.push(sum[i]);
        }
        auto top = [&]() {
            while (!Q2.empty() && Q1.top() == Q2.top()) {
                Q1.pop(), Q2.pop();
            }
            return Q1.top();
        };
        res[0] = max(res[0], top());
        for (int t = 0; t < q; t++) {
            int p = Q[t][0], x = Q[t][1], id = p % d;
            Q2.push(sum[id]);
            sum[id] -= 1LL * a[p] * d, a[p] = x;
            Q1.push(sum[id] += 1LL * a[p] * d);
            res[t + 1] = max(res[t + 1], top());
        }
    }
    for (ll x : res) {
        cout << x << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}