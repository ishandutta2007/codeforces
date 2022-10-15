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

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    if (n == 1 || a == vector(n, 0)) {
        cout << qp(mint(2), n - 1) << "\n";
        return;
    }
    vector<mint> fact(n + 1), finv(fact);
    fact[0] = finv[0] = 1;
    for (int i = 1; i < fact.size(); i++) {
        fact[i] = i * fact[i - 1];
        finv[i] = fact[i].inv();
    }
    auto binom = [&](int x, int y) -> mint {
        if (x < y || y < 0) return 0;
        return fact[x] * finv[y] * finv[x - y];
    };
    ll tot = accumulate(a.begin(), a.end(), 0LL);
    int lb = -1, rb;
    {
        ll cur = 0;
        for (int i = 0, j = n - 1; i < n; i++) {
            cur += a[i];
            while (j > i && cur >= a[j]) cur -= a[j--];
            if (cur || j < i) continue;
            lb = i, rb = j + 1;
        }
    }
    if (!~lb) {
        cout << "1\n";
        return;
    }
    if (rb == lb + 1) {
        while (!a[lb]) lb--;
        while (!a[rb]) rb++;
    }
    vector<ll> ps1(a.begin(), a.begin() + lb + 1), ps2(a.begin() + rb, a.end());
    reverse(ps1.begin(), ps1.end());
    ps1.insert(ps1.begin(), 0), ps2.insert(ps2.begin(), 0);
    partial_sum(ps1.begin(), ps1.end(), ps1.begin());
    partial_sum(ps2.begin(), ps2.end(), ps2.begin());
    ps1.pop_back(), ps2.pop_back();
    map<ll, int> freq1, freq2;
    for (ll x : ps1) {
        freq1[x]++;
    }
    for (ll x : ps2) {
        freq2[x]++;
    }
    mint ans = 1;
    for (auto &[x, i] : freq1) {
        int j = freq2[x];
        mint sum;
        for (int k = 0; k <= min(i, j); k++) {
            sum += binom(i, k) * binom(j, k);
        }
        ans *= sum;
    }
    bool good = 1;
    for (int i = lb + 1; i < rb; i++) {
        good &= !a[i];
    }
    if (good) ans *= qp(mint(2), rb - lb - 1);
    cout << ans << "\n";
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