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
typedef pair<long double, long double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

ll p2(ll x) {
    return x*x;
}

bool bad(int a, int b, int c, int d) {
    int d1 = __gcd(a, b);
    int d2 = __gcd(c, d);
    a /= d1; b /= d1;
    c /= d2; d /= d2;
    return (a == c && b == d && d1 < d2);
}

pii pts(vi x) {
    return pdd(x[0], x[1]);
}

pdd sub(pii x, pii y) {
    return pdd((y.first-x.first)/(long double)x.first, (y.second-x.second)/(long double)x.second);
}

long double vect(pdd x, pdd y) {
    return x.first*y.second - x.second*y.first;
}

int n;
vi ok(const vvi & v) {
    vi ok(n);
    vvi q(1, v[0]);
    vi link(n, -1);
    int mx=q[0][0],my=q[0][1];
    for (int i = 1; i < n; ++i) if (!bad(v[i][0], v[i][1], q.back()[0], q.back()[1])) {
        if (v[i][0] == q.back()[0] && v[i][1] == q.back()[1]) {
            link[i] = q.back()[2];
            continue;
        }
        mx = max(mx, v[i][0]);
        my = max(my, v[i][1]);
        while (!q.empty() && bad(q.back()[0], q.back()[1], v[i][0], v[i][1])) {
            q.pop_back();
        }
        while (q.size() >= 2 && vect(sub(pts(q.back()), pts(v[i])), sub(pts(q[q.size()-2]), pts(v[i]))) > 1e-17) {
            q.pop_back();
        }
        q.push_back(v[i]);
    }
    while (!q.empty() && q.back()[1] < my) q.pop_back();
    while (q.size() >= 2 && q[q.size()-2][1] == my) q.pop_back();
    bool go = 0;
    for (int i = 0; i < q.size(); ++i) {
//        cerr << q[i][0] << ' ' << q[i+1][0] << ' ' << mx << endl;
        if (q[i][0] >= mx && (i + 1 == q.size() || q[i+1][0] < mx)) go = 1;
        if (go) ok[q[i][2]] = 1;
    }
    for (int i = 0; i < n; ++i) if (link[i] >= 0)
        ok[v[i][2]] = ok[link[i]]; 
    return ok;
}

bool cmp(const vi& a, const vi& b) {
    return a[0]*b[1] > a[1]*b[0];
}

int main() {
    cin >> n;
    vvi v(n, vi(3));
    for (int i = 0; i < n; ++i) {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    sort(v.begin(), v.end(), cmp);
    vi a = ok(v);
    for (int i = 0; i < n; ++i) if (a[i])
        cout << i + 1 << ' ';
    cout << endl;
    return 0;
}