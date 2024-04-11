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
    int n, m, k;
    cin >> n >> m >> k;
    vvi a(n, vi(m));
    vvi b = a, c = a;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j)
            cin >> a[i][j] >> b[i][j] >> c[i][j];
    }
    ll ma = 0;
    for (int n1 = 0; n1 < n; ++n1) for (int n2 = 0; n2 < n; ++n2) {
        vii ts;
        for (int j = 0; j < m; ++j) if (a[n1][j] < b[n2][j]) {
            ts.push_back(pii(b[n2][j] - a[n1][j], min(k, c[n1][j])));
        }
        sort(ts.begin(), ts.end());
        ll sum = 0, rem = k;
        for (int i = (int)ts.size() - 1; i >= 0; --i) {
            ll cnt = min(rem, (ll)ts[i].second);
            sum += ts[i].first * cnt;
            rem -= cnt;
        }
        ma = max(sum, ma);
    }
    cout << ma << endl;
    return 0;
}