#pragma GCC optimize("Ofast,unroll-loops")
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

string n;
mint f[2][2][2][2][2][2], g[2][2][2][2][2][2];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    f[0][0][0][1][1][1] = 1;
    for (int i = 0; i < n.size(); i++) {
        memset(g, 0, sizeof(g));
        int v = n[i] - '0';
        for (int a : {0, 1}) for (int b : {0, 1}) for (int c : {0, 1}) {
            for (int ab : {0, 1}) for (int ac : {0, 1}) for (int bc : {0, 1}) {
                if (!f[a][b][c][ab][ac][bc].val()) continue;
                for (int ax : {0, 1}) {
                    if (ax && !a && !v) continue;
                    for (int bx : {0, 1}) {
                        if (bx && !b && !v) continue;
                        for (int cx : {0, 1}) {
                            if (cx && !c && !v) continue;
                            g[a | (ax < v)][b | (bx < v)][c | (cx < v)][ab & !((ax ^ bx) & (bx ^ cx))]
                                [ac & !((ax ^ bx) & (ax ^ cx))][bc & !((ax ^ cx) & (bx ^ cx))] += f[a][b][c][ab][ac][bc];
                        }
                    }
                }
            }
        }
        swap(f, g);
    }
    mint ans;
    for (int a : {0, 1}) for (int b : {0, 1}) for (int c : {0, 1}) {
        for (int ab : {0, 1}) for (int ac : {0, 1}) for (int bc : {0, 1}) {
            if (!ab && !ac && !bc) ans += f[a][b][c][ab][ac][bc];
        }
    }
    cout << ans << "\n";
    return 0;
}