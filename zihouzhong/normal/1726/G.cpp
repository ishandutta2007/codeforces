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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x, x--;
    }
    vector<array<int, 2>> cnt(3 * n);
    for (int i = 0, b; i < n; i++) {
        cin >> b, cnt[a[i]][b]++;
    }
    vector<mint> fact(n + 1), finv(n + 1);
    fact[0] = finv[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = i * fact[i - 1];
        finv[i] = fact[i].inv();
    }
    int mn = find_if(cnt.begin(), cnt.end(), [&](const auto &v)
        { return v[0] || v[1]; }) - cnt.begin();
    if (cnt[mn][0] + cnt[mn][1] == n) {
        cout << fact[n] << "\n", exit(0);
    }
    mint ans = fact[n] * finv[n - cnt[mn + n - 1][1]];
    int num = 0;
    for (int i = mn; i < mn + n; i++) {
        if (cnt[i][0] && i + num < mn + n - 1) {
            ans = 0;
        } else {
            ans *= fact[cnt[i][0]];
        }
        num += cnt[i][0];
        if (i < mn + n - 1 && cnt[i][1]) {
            if (cnt[i][1] > 1 || i - mn > num) ans = 0;
        }
        num += cnt[i][1];
    }
    if (num != n) ans = 0;
    cout << ans << "\n";
    return 0;
}