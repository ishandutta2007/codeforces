#include <bits/stdc++.h>
using namespace std;

int P;

template <class T> T qp(T a, int b) {
    T c = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) c *= a;
    }
    return c;
}

struct mint {
    int x;
    mint(int _x = 0) : x(_x % P) { x < 0 ? x += P : 0; }
    int val() const { return x; }

    mint operator - () const {
        return !x ? 0 : P - x;
    }
    mint inv() const {
        assert(x != 0);
        return qp(*this, P - 2);
    }
    mint &operator += (const mint &rhs) {
        x += rhs.x - P, x += x >> 31 & P;
        return *this;
    }
    mint &operator -= (const mint &rhs) {
        x -= rhs.x, x += x >> 31 & P;
        return *this;
    }
    mint &operator *= (const mint &rhs) {
        x = (long long)x * rhs.x % P;
        return *this;
    }
    mint &operator /= (const mint &rhs) {
        return *this *= rhs.inv();
    }
    friend mint operator + (const mint &a, const mint &b) {
        mint res = a;
        return res += b, res;
    }
    friend mint operator - (const mint &a, const mint &b) {
        mint res = a;
        return res -= b, res;
    }
    friend mint operator * (const mint &a, const mint &b) {
        mint res = a;
        return res *= b, res;
    }
    friend mint operator / (const mint &a, const mint &b) {
        mint res = a;
        return res /= b, res;
    }

    friend istream &operator >> (istream &is, mint &a) {
        int x;
        is >> x, a = mint(x);
        return is;
    }
    friend ostream &operator << (ostream &os, const mint &a) {
        return os << a.val();
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n >> P;
    vector<vector<int>> G(n);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        G[u].push_back(v), G[v].push_back(u);
    }
    vector<vector<mint>> f(n, vector<mint>(n + 1));
    decltype(f) ps(n, vector<mint>(n + 1)), coef(n, vector<mint>(n + 1));
    auto dfs = [&](auto self, int u, int fa) -> void {
        if (u) G[u].erase(find(G[u].begin(), G[u].end(), fa));
        vector<mint> g(n + 1, 0), _g(n + 1);
        g[1] = 1;
        for (int v : G[u]) {
            self(self, v, u);
            partial_sum(g.begin(), g.end(), _g.begin());
            for (int i = 1; i <= n; i++) _g[i] *= ps[v][i];
            for (int i = 1; i <= n; i++) g[i] = _g[i] - _g[i - 1];
        }
        for (int i = 0; i < n; i++) {
            f[u][i + !u] = g[i];
        }
        if (!u) return;
        partial_sum(f[u].begin(), f[u].end(), f[u].begin());
        for (int i = 1; i < n; i++) {
            vector<mint> suf(G[u].size() + 1);
            suf[G[u].size()] = 1;
            for (int j = G[u].size() - 1; ~j; j--) {
                suf[j] = suf[j + 1] * ps[G[u][j]][i];
            }
            mint pre = 1;
            for (int j = 0; j < G[u].size(); j++) {
                coef[G[u][j]][i + 1] += pre * suf[j + 1];
                pre *= ps[G[u][j]][i];
            }
        }
        for (int v : G[u]) {
            partial_sum(coef[v].begin(), coef[v].end(), coef[v].begin());
            for (int i = 0; i <= n; i++) {
                f[u][i] += f[v][i] * coef[v][i];
            }
        }
        partial_sum(f[u].begin(), f[u].end(), ps[u].begin());
    };
    dfs(dfs, 0, -1);
    vector<vector<mint>> binom(n + 1, vector<mint>(n + 1));
    for (int i = 0; i <= n; i++) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j < i; j++) {
            f[0][i] -= f[0][j] * binom[i - 2][j - 2];
        }
        cout << f[0][i] << " ";
    }
    return 0;
}