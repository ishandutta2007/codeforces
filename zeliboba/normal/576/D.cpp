#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

//vector<vii> g, gr;
int B;

vi mul(const vvi & v, const vi & a) {
    vi res(B);
    for (int i = 0; i < v.size(); ++i) {
        int t = 0;
        for (int j = 0; j < v[i].size(); ++j) if (v[i][j] & a[j]) {
            t = 1; break;
        }
        if (t) res[i/32] |= (1 << (i % 32));
    }
    return res;
}

vvi mul(const vvi & a, const vvi & b) {
    int n = a.size();
    vvi res(n, vi(B));
    vvi tr(n, vi(B));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (b[i][j/32] & (1 << (j % 32))) {
        tr[j][i/32] |= (1 << (i % 32));
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        int t = 0;
        for (int l = 0; l < B; ++l) if (a[i][l] & tr[j][l]) {
            t = 1; break;
        }
        if (t) {
            res[i][j/32] |= (1 << (j % 32));
        }
    }
    return res;
}

vvi id(int n) {
    vvi res(n, vi(B));
    for (int i = 0; i < n; ++i) res[i][i / 32] |= (1 << (i % 32));
    return res;
}

vvi mpow(vvi x, ll n) {
    vvi res = id(x.size());
    while (n) {
        if (n & 1) res = mul(res, x);
        x = mul(x, x);
        n /= 2;
    }
    return res;
}

int n;
void out(vi v) {
    for (int i = 0; i < n; ++i) {
        if (v[i/32] & (1 << (i % 32))) cerr << 1 << ' ';
        else cerr << 0 << ' ';
    }
    cerr << endl;
}

void out(vvi v) {
    for (int i = 0; i < v.size(); ++i) out(v[i]);
    cerr << endl;
}

int main() {
    int m;
    cin >> n >> m;
//    g.resize(n);
//    gr.resize(n);
    vvi ts(m, vi(3));
    for (int i = 0; i < m; ++i) {
        int a,b,d;
        cin >> a >> b >> d;
        --a; --b;
//        g[a].push_back(pii(b, d));
//       gr[b].push_back(pii(a, d));
        ts[i] = {d,a,b};
    }
    sort(ts.begin(), ts.end());
//    int l = 0, r = 2e9;
    B = n / 32 + 1;
//    while (r - l > 1) {
//        cerr << l << ' ' << r << endl;
//        int x = (l + (ll)r) / 2;
    vi p(B); p[0] = 1;
    vvi a(n, vi(B));
    int prev = 0;
    for (int i = 0; i < ts.size(); ++i) {
        int nx = ts[i][0];
        if (nx > prev) {
            vvi a1 = a;
            for (int j = 0; j < n; ++j) a1[j][j/32] |= (1 << (j % 32));
            vector<vvi> pw(1, a1);
            while (prev + (1 << pw.size()) <= nx) {
                pw.push_back(mul(pw.back(), pw.back()));
            }
            vi p1 = p;
            int add = 0;
            for (int j = pw.size() - 1; j >= 0; --j) {
                if (add + (1 << j) <= nx - prev) {
                    vi p2 = mul(pw[j], p1);
                    if (!(p2[(n-1)/32] & (1 << ((n-1) % 32)))) {
                        p1.swap(p2);
                        add += 1<<j;
                    }
                }
            }
            if (add < nx - prev) {
                cout << prev + add + 1 << endl;
//                cerr << prev << ' ' << nx << ' ' << add << endl;
                return 0;
            }
            p = mul(mpow(a, nx - prev), p);
        }
        int j = ts[i][1];
        a[ts[i][2]][j/32] |= (1 << (j % 32));
        prev = nx;
        if (p[(n-1)/32] & (1 << ((n-1) % 32))) {
            cout << prev << endl;
//             cerr << i << endl;
            return 0;
        }
    }
    for (int j = 0; j < n; ++j) a[j][j/32] |= (1 << (j % 32));
    for (int i = 0; i < n; ++i) {
        ++prev;
        p = mul(a, p);
        if (p[(n-1)/32] & (1 << ((n-1) % 32))) {
            cout << prev << endl;
            return 0;
        }
    }
/*        if (p[(n-1)/32] & (1 << ((n-1) % 32))) {
            r = x;
        } else l = x;
    }*/
    cout << "Impossible\n";
    return 0;
}