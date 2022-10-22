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

using info = array<array<mint, 2>, 2>;
const int N = 3e5 + 5;
int val[N];
info t[N * 4];

#define mid ((l + r) / 2)
#define ls (2 * k)
#define rs (2 * k + 1)
void maintain(int k, int l, int r) {
    t[k] = {};
    int x = val[mid + 1];
    for (int a : {0, 1}) {
        for (int b : {0, 1}) {
            for (int c : {b & x, b | x, b ^ x}) {
                for (int d : {0, 1}) {
                    t[k][a][d] += t[ls][a][b] * t[rs][c][d];
                }
            }
        }
    }
}

void modify(int k, int l, int r, int p, int v) {
    if (l == r) {
        val[l] = v, t[k][0][0] = t[k][1][1] = 1;
        return;
    }
    if (mid >= p) modify(ls, l, mid, p, v);
    else modify(rs, mid + 1, r, p, v);
    maintain(k, l, r);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> a(N);
    for (int i = 0, l, r; i < n; i++) {
        cin >> l >> r;
        a[0].emplace_back(i, 0);
        a[l].emplace_back(i, 1);
        a[r + 1].emplace_back(i, 0);
    }
    mint ans;
    for (int i = 0; i < N; i++) {
        for (auto [j, x] : a[i]) {
            modify(1, 0, n - 1, j, x);
        }
        ans += t[1][val[0]][1];
    }
    cout << ans << "\n";
    return 0;
}