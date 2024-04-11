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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int m, k;
    cin >> m >> k;
    vi d(m), s(m);
    ll res = 0;
    for (int i = 0; i < m; ++i) {
        cin >> d[i];
        res += d[i];
    }
    for (int i = 0; i < m; ++i)
        cin >> s[i];
    int cur = 0;
    int ma = s[0], len = 0;
    for (int i = 0; i < m; ++i) {
        len += d[i];
        cur += s[i];
        ma = max(ma, s[i]);
        int t = (max(len - cur, 0) + ma - 1) / ma;
//        cerr << res << endl;
        res += t * k;
        cur += ma * t;
    }
    cout << res << endl;
    return 0;
}