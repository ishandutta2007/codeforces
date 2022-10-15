#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        auto work = [&](auto a) {
            DSU dsu(30);
            vector<bool> use(30);
            int ans = 0;
            int t = 30;
            for (int i = 0; i < n; i++) {
                if (a[i] == 0) {
                    a[i]++;
                    ans++;
                }
                int x = __builtin_ctz(a[i]);
                for (int j = x; j < 30; j++) {
                    if (a[i] >> j & 1) {
                        use[j] = true;
                        dsu.merge(x, j);
                    }
                }
                t = min(t, x);
            }
            bool ok = true;
            for (int i = 0; i < 30; i++) {
                if (use[i] && !dsu.same(t, i)) {
                    ok = false;
                }
            }
            if (ok) {
                return make_pair(ans, a);
            }
            for (int i = 0; i < n; i++) {
                int x = __builtin_ctz(a[i]);
                if (t > 0) {
                    t = 0;
                    a[i]++;
                    ans++;
                    dsu.merge(0, x);
                }
                if (!dsu.same(0, x)) {
                    a[i]++;
                    ans++;
                    dsu.merge(0, x);
                }
            }
            return make_pair(ans, a);
        };
        auto ans = work(a);
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                continue;
            }
            a[i]--;
            auto res = work(a);
            a[i]++;
            res.first++;
            if (res.first < ans.first) {
                ans = res;
            }
        }
        cout << ans.first << "\n";
        for (int i = 0; i < n; i++) {
            cout << ans.second[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}