#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, q;
double X, Y;
bool ok[3][3];

typedef array<array<double, 3>, 3> mat;

mat operator * (const mat &A, const mat &B) {
    mat C;
    for (int i : {0, 1, 2}) for (int j : {0, 1, 2}) {
        C[i][j] = -1e18;
    }
    for (int i : {0, 1, 2}) for (int j : {0, 1, 2}) {
        for (int p : {0, 1, 2}) if (ok[j][p]) for (int q : {0, 1, 2}) {
            C[i][q] = max(C[i][q], A[i][j] + B[p][q]);
        }
    }
    return C;
}

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
mat t[maxn << 2];

void upd(int k, int l, int r, int p, mat v) {
    if (l == r) { t[k] = v; return; }
    mid >= p ? upd(ls, l, mid, p, v) : upd(rs, mid + 1, r, p, v);
    t[k] = t[ls] * t[rs];
}

mat query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[k];
    if (mid >= qr) return query(ls, l, mid, ql, qr);
    if (mid < ql) return query(rs, mid + 1, r, ql, qr);
    return query(ls, l, mid, ql, qr) * query(rs, mid + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q >> X >> Y;
    if (X > Y) swap(X, Y);
    array<double, 3> val = {0, 1 / (X + Y), 1 / Y};
    for (int i : {0, 1, 2}) for (int j : {0, 1, 2}) {
        ok[i][j] = X * val[i] + Y * val[j] < 1 + 1e-9 && X * val[j] + Y * val[i] < 1 + 1e-9;
    }
    auto modify = [&](int p, int v) {
        mat A{};
        for (int i : {0, 1, 2}) for (int j : {0, 1, 2}) {
            if (i == j) A[i][j] = val[i] * v;
            else A[i][j] = -1e18;
        }
        upd(1, 1, n, p, A);
    };
    for (int i = 1, b; i <= n; i++) {
        cin >> b, modify(i, b);
    }
    cout << setprecision(12) << fixed;
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            modify(x, y);
        } else {
            mat A = query(1, 1, n, x, y);
            double ans = 0;
            for (int i : {0, 1, 2}) for (int j : {0, 1, 2}) {
                ans = max(ans, A[i][j]);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}