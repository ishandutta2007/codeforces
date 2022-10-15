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
    int n, m;
    cin >> n >> m;
    vi a(n);
    vi was(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= n)
            ++was[a[i]];
    }
    vi v;
    vector<vi> sum;
    for (int i = 1; i <= n; ++i) if (was[i] >= i) {
        v.push_back(i);
        sum.push_back(vi(1, 0));
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] == i)
                ++cnt;
            sum.back().push_back(cnt);
        }
    }
    for (int q = 0; q < m; ++q) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        int res = 0;
        for (int i = 0; i < v.size(); ++i) if (sum[i][r + 1] - sum[i][l] == v[i]) {
//            cerr << v[i] << " " << sum[i][r + 1] << " " <<  sum[i][l] << endl;
            ++res;
        }
        cout << res << endl;
    }
    return 0;
}