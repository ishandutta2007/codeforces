#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int dw(int i, int n) {
    return i % n;
    if (i < n)
        return i;
    else return i - n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, t, m;
    cin >> n >> t;
    vi a(2 * n), b(2 * n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> a[i + n] >> b[i + n];
    cin >> m;
    vector<string> name(m);
    vi c(m);
    vi was(m);
    for (int i = 0; i < m; ++i)
        cin >> name[i] >> c[i];
    vvi d(n, vi(m));
    vvi res(n);
    int curt = t, it = 0, n2 = 2 * n, cnt = 0;
    for (int i = 0; cnt < m; i = dw(i + 1, m)) if (!was[i]) {
        int it1 = dw(it, n);
        int cost = max(1, c[i] - a[it] - b[dw(it + n, n2)] - d[it1][i]);
//        cerr << it << " " << curt << " " << i << " " << cost << endl;
        if (curt >= cost) {
            curt -= cost;
            res[it1].push_back(i);
            was[i] = 1;
            ++cnt;
        } else {
            d[it1][i] += curt;
            curt = 0;
        }
        if (curt == 0) {
            curt = t;
            it = dw(it + 1, n2);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i].size();
        for (int j = 0; j < res[i].size(); ++j)
            cout << " " << name[res[i][j]];
        cout << endl;
    }
    return 0;
}