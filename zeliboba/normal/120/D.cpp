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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    vi v(3);
    cin >> n >> m;
    vector<vvi> a(2);
    a[0].assign(n, vi(m));
    a[1].assign(m, vi(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        cin >> a[0][i][j];
        a[1][j][i] = a[0][i][j];
    }
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    int res = 0;
    vvi sum(2);
    for (int h = 0; h < 2; ++h) {
        sum[h].resize(a[h].size() + 1);
        for (int i = 1; i < sum[h].size(); ++i) {
            sum[h][i] = sum[h][i - 1];
            for (int j = 0; j < a[h][i - 1].size(); ++j)
                sum[h][i] += a[h][i - 1][j];
        }
        for (int t1 = 1; t1 < sum[h].size(); ++t1) for (int t2 = t1 + 1; t2 + 1 < sum[h].size(); ++t2) {
            vi cur(3);
            cur[0] = sum[h][t1];
            cur[1] = sum[h][t2] - sum[h][t1];
            cur[2] = sum[h].back() - sum[h][t2];
            sort(cur.begin(), cur.end());
            if (cur == v)
                ++res;
        }
    }
    cout << res << endl;
    return 0;
}