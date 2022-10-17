#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18 + 5;
const int P = 1e9 + 7;
inline void add(int &x, int y) {
    (x += y) >= P && (x -= P);
}
inline int Add(int x, int y) {
    return add(x, y), x;
}
inline void sub(int &x, int y) {
    (x -= y) < 0 && (x += P);
}
inline int Sub(int x, int y) {
    return sub(x, y), x;
}
inline void mul(int &x, int y) {
    x = 1ll * x * y % P;
}
inline int Mul(int x, int y) {
    return 1ll * x * y % P;
}
int main() {
    int t, k;
    cin >> t >> k;
    vector<int> p2(t + 1);
    p2[0] = 1;
    for (int i = 1; i <= t; ++i) {
        p2[i] = Add(p2[i - 1], p2[i - 1]);
    }
    vector<int> a, b;
    for (int tt = 0; tt < t; ++tt) {
        int x;
        cin >> x;
        if (x > 0) {
            a.push_back(x);
        } else {
            b.push_back(-x);
        }
    }
    sort(a.begin(), a.end(), [&](int x, int y) {
        return x > y;
    });
    sort(b.begin(), b.end(), [&](int x, int y) {
        return x > y;
    });
    int n = a.size();
    int m = b.size();
    int ans = 0;
    auto solve1 = [&]() {
        if (k & 1) {
            reverse(b.begin(), b.end());
            vector<int> f(m + 1);
            f[0] = 1;
            for (auto x : b) {
                for (int i = m; i > 0; --i) {
                    int val = f[i - 1];
                    if (i <= k) {
                        mul(val, Sub(0, x));
                    }
                    add(f[i], val);
                }
            }
            for (int i = k; i <= m; ++i) {
                add(ans, f[i]);
            }
            reverse(b.begin(), b.end());
        }
    };
    auto get = [&](vector<int> a) {
        int n = (int) a.size() - 1;
        vector<vector<int>> f(n + 1, vector<int>(k + 1, 0));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1];
            for (int j = 1; j <= min(i, k); ++j) {
                add(f[i][j], Mul(f[i - 1][j - 1], a[i]));
            }
        }
        return f;
    };
    auto solve2 = [&]() {
        a.insert(a.begin(), -1);
        b.insert(b.begin(), -1);
        auto f = get(a);
        auto g = get(b);
        for (int i = 1; i < k; i += 2) {
            sub(ans, Mul(g[m][i], f[n][k - i]));
        }
        for (int t = 0; t < 2; ++t) {
            bool odd = !t ? 0 : (k & 1);
            vector<int> pos(n + 1);
            for (int i = 1, j = 0; i <= n; ++i) {
                while (j < m && b[j + 1] - t >= a[i]) {
                    ++j;
                }
                pos[i] = j;
            }
            for (int i = 0; i <= n; ++i) {
                vector<int> sum(m + 1);
                for (int j = 0; j <= m; ++j) {
                    for (int x = odd; x < k; x += 2) {
                        add(sum[j], Mul(g[j][x], Sub(f[i][k - 1 - x], (i == 0) ? 0 : f[i - 1][k - 1 - x])));
                    }
                }
                for (int i1 = i + 1; i1 <= n; ++i1) {
                    i64 val = (i == 0) ? inf : (1ll * a[i] * a[i1]);
                    int res = sum[pos[i1]];
                    for (int j = m, j1 = 1; j > 0; --j) {
                        while (j1 <= m && (1ll * b[j] * b[j1] + !t > val)) {
                            ++j1;
                        }
                        int x = p2[min(m + 1 - j1, m - j)];
                        int y = sum[min(pos[i1], j - 1)];
                        add(res, Mul(x, y));
                    }
                    add(ans, Mul(res, Mul(a[i1], p2[n - i1])));
                }
            }
            swap(n, m);
            swap(a, b);
            swap(f, g);
        }
    };
    solve1();
    solve2();
    cout << ans << "\n";
    return 0;
}