#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

pair<int, string> solve1(const string& s, char x, char y) {
    int m = int(s.size());
    auto dist = [&](const string& t, const string& r) {
        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (t[i] != r[i]) ans++;
        }
        return ans;
    };
    string pred0, pred1;
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            pred0 += x;
            pred1 += y;
        } else {
            pred0 += y;
            pred1 += x;
        }
    }
    int d0 = dist(s, pred0);
    int d1 = dist(s, pred1);
    if (d0 < d1) return {d0, pred0};
    else return {d1, pred1};
}

pair<int, V<string>> solve_inside(const V<string>& v, char x, char y, char z, char w) {
    int n = int(v.size());
    int sm = 0;
    V<string> res;
    for (int i = 0; i < n; i++) {
        pair<int, string> p;
        if (i % 2 == 0) {
            p = solve1(v[i], x, y);
        } else {
            p = solve1(v[i], z, w);
        }
        sm += p.first;
        res.push_back(p.second);
    }
    return {sm, res};
}

pair<int, V<string>> solve(V<string> v) {
    pair<int, V<string>> res; res.first = TEN(9);
    auto chmin = [&](const pair<int, V<string>>& pred) {
        if (res.first < pred.first) return;
        res = pred;
    };
    chmin(solve_inside(v, 'A', 'G', 'C', 'T'));
    chmin(solve_inside(v, 'A', 'C', 'G', 'T'));
    chmin(solve_inside(v, 'A', 'T', 'G', 'C'));
    chmin(solve_inside(v, 'G', 'C', 'A', 'T'));
    chmin(solve_inside(v, 'G', 'T', 'A', 'C'));
    chmin(solve_inside(v, 'C', 'T', 'A', 'G'));
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
//    n = 300000; m = 1;
    V<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        //v[i] = "A";
    }
    V<string> w(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            w[i] += v[j][i];
        }
    }

    auto res1 = solve(v);
    auto res2 = solve(w);

    if (res2.first < res1.first) {
        for (int i = 0; i < n; i++) {
            res1.second[i].clear();
            for (int j = 0; j < m; j++) {
                res1.second[i] += res2.second[j][i];
            }
        }
    }

    for (auto s: res1.second) {
        cout << s << "\n";
    }
    return 0;
}