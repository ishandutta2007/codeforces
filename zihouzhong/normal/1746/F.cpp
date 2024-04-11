#include <bits/stdc++.h>
using namespace std;

template <class T> struct fenwick_tree {
    int n;
    vector<T> a;
    fenwick_tree(int n = 0) : n(n), a(n + 1) {}

    void add(int p, T v) {
        for (int i = p + 1; i <= n; i += i & -i) a[i] += v;
    }
    T sum(int l, int r) { // [l, r)
        return sum(r) - sum(l);
    }

  private:
    T sum(int p) {
        T ans = 0;
        for (int i = p; i > 0; i -= i & -i) ans += a[i];
        return ans;
    }
};

using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    auto get = [&](int x) {
        static int tot = 0;
        static map<int, int> mp;
        if (!mp.count(x)) mp[x] = tot++;
        return mp[x];
    };
    vector<int> a(n);
    for (int &x : a) {
        cin >> x, x = get(x);
    }
    auto orig = a;
    vector<tuple<int, int, int, int>> b(q);
    vector<int> res(q);
    for (int i = 0; i < q; i++) {
        auto &[op, x, y, z] = b[i];
        cin >> op >> x >> y;
        if (op == 1) {
            x--, y = get(y);
            z = a[x], a[x] = y;
            res[i] = -1;
        } else {
            cin >> z;
            x--, y--;
            res[i] = 1;
        }
    }
    vector<ll> w(n + q);
    for (int _ = 0; _ < 40; _++) {
        generate(w.begin(), w.end(), mt19937(_));
        fenwick_tree<ll> bit(n);
        for (int i = 0; i < n; i++) {
            bit.add(i, w[orig[i]]);
        }
        for (int i = 0; i < q; i++) {
            auto &[op, x, y, z] = b[i];
            if (op == 1) {
                bit.add(x, w[y] - w[z]);
            } else {
                res[i] &= bit.sum(x, y + 1) % z == 0;
            }
        }
    }
    for (auto x : res) {
        if (~x) cout << (x ? "YES" : "NO") << "\n";
    }
    return 0;
}