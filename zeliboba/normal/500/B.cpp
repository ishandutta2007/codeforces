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

vi pr, r;

int getp(int v) {
    if (v == pr[v]) return v;
    return pr[v] = getp(pr[v]);
}

void join(int a, int b) {
    a = getp(a);
    b = getp(b);
    if (a == b) return;
    if (r[a] < r[b]) {
        pr[a] = b;
    } else {
        pr[b] = a;
        if (r[a] == r[b])
            ++r[a];
    }
}

int main() {
    int n;
    cin >> n;
    r.assign(n, 0);
    pr.assign(n, 0);
    for (int i = 0; i < n; ++i) pr[i] = i;
    vi p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    vs a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < i; ++j) if (a[i][j] == '1')
            join(i, j);
    }
    vvi v(n);
    for (int i = 0; i < n; ++i) v[getp(i)].push_back(i);
    vi res(n);
    for (int i = 0; i < n; ++i) {
        sort(v[i].begin(), v[i].end());
        vi ts;
        for (int j = 0; j < v[i].size(); ++j)
            ts.push_back(p[v[i][j]]);
        sort(ts.begin(), ts.end());
        for (int j = 0; j < v[i].size(); ++j) {
            res[v[i][j]] = ts[j];
        }
    }
    for (int i = 0; i < n; ++i)
        cout << res[i] << ' ';
    return 0;
}