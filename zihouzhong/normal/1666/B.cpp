#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, q;
    cin >> t >> q;
    double sum_p = 0, sum_inc = 0;
    vector<array<double, 6>> ev;
    while (t--) {
        int n;
        cin >> n;
        vector<double> c(n), p(n);
        for (auto &x : c) {
            cin >> x;
        }
        auto sc = accumulate(c.begin(), c.end(), (double)0);
        for (auto &x : p) {
            cin >> x;
        }
        auto sp = accumulate(p.begin(), p.end(), (double)0);
        for (auto &x : p) {
            x /= sp;
        }
        vector<array<double, 3>> v;
        auto sum = sc;
        sc = 0;
        for (int i = 0; i < n; i++) {
            auto x = c[i] / p[i] - sum;
            if (x < 0) continue;
            v.push_back({x, c[i], p[i]});
            sum_p += p[i], sc += c[i];
        }
        sort(v.begin(), v.end());
        sum_inc += sc / sum;
        double lst = 0;
        for (auto &[d, c, p] : v) {
            auto lb = sc / (sum + lst) / (sum + lst);
            auto rb = sc / (sum + d) / (sum + d);
            ev.push_back({lb, sqrt(sc), sum, -lst, -sc / (sum + lst)});
            ev.push_back({rb, -sqrt(sc), -sum, d, (sc - c) / (sum + d), -p});
            lst = d, sc -= c;
        }
    }
    sort(ev.begin(), ev.end(), greater());
    vector<pair<double, int>> Q(q);
    for (int i = 0; i < q; i++) {
        cin >> Q[i].first, Q[i].second = i;
    }
    sort(Q.begin(), Q.end());
    double sum_a = 0, sum_sq = 0, sum_c = 0;
    auto get = [&](double x) {
        return sum_a + sum_sq / sqrt(x) - sum_c;
    };
    vector<double> res(q);
    int cur = 0;
    for (auto &[x, id] : Q) {
        for (; cur < ev.size() && get(ev[cur][0]) <= x; cur++) {
            auto &[_, sq, c, a, inc, p] = ev[cur];
            sum_sq += sq, sum_c += c, sum_a += a;
            sum_inc += inc, sum_p += p;
        }
        if (cur < ev.size()) res[id] = 2 * (sum_inc + sum_sq * sum_sq /
            (x - sum_a + sum_c) - sum_p);
    }
    cout << fixed << setprecision(9);
    for (auto x : res) {
        cout << x << "\n";
    }
    return 0;
}