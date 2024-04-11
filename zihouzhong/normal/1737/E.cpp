#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;

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

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    vector<mint> pw(n + 1), ipw(n + 1);
    pw[0] = ipw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = 2 * pw[i - 1];
        ipw[i] = pw[i].inv();
    }
    auto ps1 = pw;
    for (int i = 2; i <= n; i++) {
        ps1[i] /= 2;
    }
    partial_sum(ps1.begin(), ps1.end(), ps1.begin());
    vector<mint> g(n + 1), sum(n + 2);
    g[n] = 1, sum[n] = ipw[n];
    for (int i = n - 1; i; i--) {
        if (i > n - i) g[i] += ipw[n - i];
        g[i] += pw[i] * (sum[i + 1] - sum[min(n + 1, 2 * i)]);
        sum[i] = sum[i + 1] + ipw[i] * g[i];
    }
    mint r = 1;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << "0\n";
            continue;
        }
        if (i == n) {
            cout << r << "\n";
            continue;
        }
        int k = min(i, (i + 2) / 2);
        mint ans = ps1[k] - ps1[0];
        ans *= g[i] * ipw[i + 1];
        cout << ans << "\n";
        r -= ans;
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