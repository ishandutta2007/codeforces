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

char s[105][10005];

int down(int j, int m) {
    if (j >= m)
        return j - m;
    return j;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vi> d(n, vi(m, m - 1));
    int res = n * m;
    for (int r = 0; r < n; ++r) {
        scanf("%s", s[r]);
        int prev = -m;
        for (int j1 = 0; j1 < 2 * m; ++j1) {
            int j = down(j1, m);
            if (s[r][j] == '1')
                prev = j1;
            d[r][j] = min(d[r][j], j1 - prev);
        }
        prev = 3 * m;
        for (int j1 = 2 * m - 1; j1 >= 0; --j1) {
            int j = down(j1, m);
            if (s[r][j] == '1')
                prev = j1;
            d[r][j] = min(d[r][j], prev - j1);
        }
        if (prev > 2 * m) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int j = 0; j < m; ++j) {
        int cur = 0;
        for (int i = 0; i < n; ++i)
            cur += d[i][j];
        res = min(res, cur);
    }
    cout << res << endl;
    return 0;
}