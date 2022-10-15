#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
using ll = long double;
const ll eps = 1e-12;

ll sumx[N * 4], sumy[N * 4];
bool tag[N * 4];

#define ls (k << 1)
#define rs (k << 1 | 1)
#define mid ((l + r) / 2)
void apply(int k) {
    tag[k] = true;
    sumx[k] = sumy[k] = 0;
}

void pushdown(int k) {
    if (tag[k]) {
        apply(ls);
        apply(rs);
        tag[k] = false;
    }
}

void pushup(int k) {
    sumx[k] = sumx[ls] + sumx[rs];
    sumy[k] = sumy[ls] + sumy[rs];
}

void build(int k, int l, int r) {
    sumx[k] = sumy[k] = 0;
    tag[k] = false;
    if (l == r) return;
    build(ls, l, mid); build(rs, mid + 1, r);
}

void update(int p, ll x, ll y, int k, int l, int r) {
    if (l == r) return sumx[k] = x, sumy[k] = y, void();
    pushdown(k);
    p <= mid ? update(p, x, y, ls, l, mid) : update(p, x, y, rs, mid + 1, r);
    pushup(k);
}

void query(ll &x, ll &y, int k, int l, int r) {
    if (l == r) {
        auto t = make_pair(sumx[k], sumy[k]);
        cout << x + y / t.second * t.first << "\n";
        return;
    }
    pushdown(k);
    if (y >= sumy[ls]) {
        x += sumx[ls]; y -= sumy[ls];
        return query(x, y, rs, mid + 1, r);
    } else {
        return query(x, y, ls, l, mid);
    }
}

void fix1(ll &x, ll &y, int k, int l, int r) {
    if (l == r) {
        if (abs(sumx[k]) < eps) return;
        ll t = min(sumx[k], (-x)) / sumx[k];
        x += sumx[k] * t; y -= sumy[k] * t;
        sumx[k] *= (1 - t); sumy[k] *= (1 - t);
        return;
    }
    pushdown(k);
    if (x + sumx[ls] < -eps) {
        x += sumx[ls];
        y -= sumy[ls];
        apply(ls);
        fix1(x, y, rs, mid + 1, r);
    } else {
        fix1(x, y, ls, l, mid);
    }
    pushup(k);
}

void fix2(ll &x, ll &y, int k, int l, int r) {
    if (l == r) {
        if (abs(sumy[k]) < eps) return;
        ll t = min(sumy[k], (-y)) / sumy[k];
        x -= sumx[k] * t; y += sumy[k] * t;
        sumx[k] *= (1 - t); sumy[k] *= (1 - t);
        return;
    }
    pushdown(k);
    if (y + sumy[rs] < -eps) {
        x -= sumx[rs];
        y += sumy[rs];
        apply(rs);
        fix2(x, y, ls, l, mid);
    } else {
        fix2(x, y, rs, mid + 1, r);
    }
    pushup(k);
}

void print(ll &x, ll &y, int k, int l, int r) {
    if (l == r) {
        x += sumx[k];
        y -= sumy[k];
        return;
    }
    pushdown(k);
    if (sumx[ls] || sumy[ls]) print(x, y, ls, l, mid);
    if (sumx[rs] || sumy[rs]) print(x, y, rs, mid + 1, r);
}

void solve() {
    int n;
    ll a, b;
    cin >> n >> a >> b;
    vector<ll> p(n), q(n);
    for (ll &x : p) {
        cin >> x;
    }
    for (ll &x : q) {
        cin >> x;
    }
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j) {
        auto a = pair(p[i], q[i]), b = pair(p[j], q[j]);
        return a.second * b.first < b.second * a.first;
    });
    vector<int> rk(n);
    for (int i = 0; i < n; i++) {
        rk[id[i]] = i;
    }
    build(1, 0, n - 1);
    for (int i = 0; i < n; i++) {
        update(rk[i], 2 * p[i], 2 * q[i], 1, 0, n - 1);
        a -= p[i]; b += q[i];
        if (a < -eps) {
            fix1(a, b, 1, 0, n - 1);
        }
        if (b - sumy[1] < -eps) {
            ll x = a + sumx[1], y = b - sumy[1];
            fix2(x, y, 1, 0, n - 1);
        }
        cout << a + sumx[1] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    cout << fixed << setprecision(10);
    while (T--) {
        solve();
    }
    return 0;
}