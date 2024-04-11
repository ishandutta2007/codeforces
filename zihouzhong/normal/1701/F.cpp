#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int q, d;
bool cur[maxn];

namespace BIT {
int c[maxn];

void add(int p, int v) {
    for (; p < maxn; p += p & -p) c[p] += v;
}

int sum(int p) {
    int s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}
} // namespace BIT

typedef array<array<ll, 3>, 3> mat;
const mat I = {array<ll, 3>{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

mat operator + (const mat &A, const mat &B) {
    mat C;
    for (int i : {0, 1, 2}) for (int j : {0, 1, 2}) {
        C[i][j] = A[i][j] + B[i][j];
    }
    return C;
}

mat operator * (const mat &A, const mat &B) {
    mat C{};
    for (int i : {0, 1, 2}) for (int j : {0, 1, 2}) {
        for (int k : {0, 1, 2}) C[i][k] += A[i][j] * B[j][k];
    }
    return C;
}

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
mat t[maxn << 2], tag[maxn << 2];

void apply(int k, mat v) {
    t[k] = t[k] * v, tag[k] = tag[k] * v;
}

void pushdown(int k) {
    if (tag[k] != I) apply(ls, tag[k]), apply(rs, tag[k]), tag[k] = I;
}

void build(int k, int l, int r) {
    tag[k] = I;
    if (l == r) { t[k][0][0] = 1; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    t[k] = t[ls] + t[rs];
}

void upd(int k, int l, int r, int p, mat v) {
    if (l == r) { t[k] = v; return; }
    pushdown(k);
    mid >= p ? upd(ls, l, mid, p, v) : upd(rs, mid + 1, r, p, v);
    t[k] = t[ls] + t[rs];
}

void mul(int k, int l, int r, int ql, int qr, mat v) {
    if (ql > qr) return;
    if (l >= ql && r <= qr) return apply(k, v);
    pushdown(k);
    if (mid >= ql) mul(ls, l, mid, ql, qr, v);
    if (mid < qr) mul(rs, mid + 1, r, ql, qr, v);
    t[k] = t[ls] + t[rs];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> q >> d;
    while (q--) {
        int x;
        cin >> x;
        if (!cur[x]) {
            mat A = {array<ll, 3>{1, 1, 1}, {0, 1, 2}, {0, 0, 1}};
            mul(1, 1, maxn - 1, max(1, x - d), x - 1, A);
            int v = BIT::sum(min(maxn - 1, x + d)) - BIT::sum(x);
            A = {array<ll, 3>{1, v, 1LL * v * v}, {0, 0, 0}, {0, 0, 0}};
            upd(1, 1, maxn - 1, x, A);
            BIT::add(x, 1);
        } else {
            mat A = {array<ll, 3>{1, -1, 1}, {0, 1, -2}, {0, 0, 1}};
            mul(1, 1, maxn - 1, max(1, x - d), x - 1, A);
            A = {array<ll, 3>{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
            upd(1, 1, maxn - 1, x, A);
            BIT::add(x, -1);
        }
        cur[x] = !cur[x];
        cout << (t[1][0][2] - t[1][0][1]) / 2 << "\n";
    }
    return 0;
}