#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;

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
    friend mint operator + (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        return res += rhs, res;
    }
    friend mint operator - (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        return res -= rhs, res;
    }
    friend mint operator * (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        return res *= rhs, res;
    }
    friend mint operator / (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        return res /= rhs, res;
    }

    friend ostream &operator << (ostream &os, const mint &a) {
        return os << a.val();
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int &x : a) {
            cin >> x;
        }
        vector<vector<int>> G(n), rG(n);
        vector<int> d(n), dist(n);
        while (m--) {
            int x, y;
            cin >> x >> y, x--, y--;
            G[x].push_back(y), rG[y].push_back(x), d[x]++;
        }
        queue<int> Q;
        for (int i = 0; i < n; i++) {
            if (!d[i]) Q.push(i);
        }
        vector<int> ord;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            ord.push_back(u);
            for (int v : rG[u]) {
                dist[v] = max(dist[v], dist[u] + 1);
                if (!--d[v]) Q.push(v);
            }
        }
        reverse(ord.begin(), ord.end());
        mint ans;
        for (int i = 0; i < n; i++) {
            bool flag = 0;
            for (int j = ord.size() - 1; ~j; j--) {
                int u = ord[j];
                if (a[u]) {
                    flag = 1, a[u]--;
                    for (int v : G[u]) a[v]++;
                }
            }
            if (!flag) break;
            ans = ans + 1;
        }
        vector<mint> f(n);
        for (int i = 0; i < n; i++) {
            f[i] = a[i];
        }
        for (int u : ord) {
            for (int v : G[u]) {
                if (dist[v] < dist[u] - 1) {
                    f[v] += f[u];
                } else if (dist[v] == dist[u] - 1) {
                    f[v] += f[u];
                }
            }
        }
        ans += f[ord.back()];
        cout << ans << "\n";
    }
    return 0;
}