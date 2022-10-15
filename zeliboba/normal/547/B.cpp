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

vi p, sz;

int getp(int v) {
    if (p[v] == v) return v;
    return p[v] = getp(p[v]);
}

void join(int a, int b) {
    a = getp(a);
    b = getp(b);
    if (sz[a] > sz[b]) swap(a, b);
    p[a] = b;
    sz[b] += sz[a];
}

int main() {
    int n;
    cin >> n;
    vii a(n);
    sz.assign(n, 1);
    p.assign(n, 1);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
        int x; cin >> x;
        a[i] = pii(x, i);
    }
    sort(a.rbegin(), a.rend());
    vi res(n + 1), was(n);
    for (int i = 0; i < n; ++i) {
        int val = a[i].first, pos = a[i].second;
        was[pos] = 1;
        if (pos && was[pos - 1]) join(pos-1, pos);
        if (pos + 1 < n && was[pos + 1]) join(pos+1, pos);
        int t = sz[getp(pos)];
        res[t] = max(res[t], val);
    }
    for (int i = n - 1; i > 0; --i) res[i] = max(res[i], res[i + 1]);
    for (int i = 1; i <= n; ++i) cout << res[i] << ' ';
    return 0;
}