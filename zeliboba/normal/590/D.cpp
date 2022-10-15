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

//int d[2][76][12000];
//int v[2][76][12000];
vector<vvi> d(2, vvi(76, vi(12000)));
vector<vvi> v(2, vvi(76, vi(12000)));

int main() {
    int n, k, s;
    cin >> n >> k >> s;
    s = min(s, (int)d[0][0].size() - 1);
    //s = min(s, k*(n-k) + k*(k-1)/2);
    assert(s >= 0);
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int j = 1; j <= min(k, n - k); ++j) for (int c = 0; c <= s; ++c) d[0][j][c] = 1e9;
    for (int i = k-1; i >= 0; --i) {
        int t = (k - 1 - i) % 2;
        assert(t >= 0 && t <= 1);
        for (int j = 1; j <= min(k - i, n - k); ++j) {
            int dist = (k - j) - i;
            for (int c = 0; c <= s; ++c) {
                assert(j < d[0].size() && c < d[0][j].size());
                v[1-t][j][c] = v[t][j][c];
                if (c >= dist) v[1-t][j][c] = max(v[1-t][j][c], v[t][j-1][c-dist] + a[i]);
            }
        }
    }
    int cur1 = (k) % 2;
    for (int i = k; i < n; ++i) {
        int t = (i - k) % 2;
        assert(t >= 0 && t <= 1);
        for (int j = 1; j <= min(k, n - k); ++j) for (int c = 0; c <= s; ++c) {
            d[1-t][j][c] = d[t][j][c];
            assert(j < d[0].size() && c < d[0][j].size());
        }
        for (int j = 1; j <= min(k, n - k); ++j) {
            int dist = i - k + j;
            for (int c = dist; c <= s; ++c) {
                assert(j < d[0].size() && c < d[0][j].size());
                d[1-t][j][c] = min(d[1-t][j][c], d[t][j-1][c-dist] + a[i]);
            }
        }
    }
    int cur = (n - k) % 2;
    for (int j = 0; j <= min(k, n - k); ++j) for (int c = 1; c <= s; ++c) {
        d[cur][j][c] = min(d[cur][j][c], d[cur][j][c-1]);
        assert(j < d[0].size() && c < d[0][j].size());
    }
    ll sum = 0;
    for (int i = 0; i < k; ++i) sum += a[i];
    ll res = sum;
    assert(cur >= 0 && cur1 >= 0 && cur < 2 && cur1 < 2);
    for (int j = 0; j <= min(k, n - k); ++j) {
        for (int c = 0; c <= s; ++c) {
            assert(j < d[0].size() && c < d[0][j].size());
            res = min(res, sum - v[cur1][j][c] + d[cur][j][s-c]);
        }
    }
    cout << res << endl;
    return 0;
}