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

int N = 1;
vi up, dw;

void put(int pos, int val, vi & v) {
    pos += N;
    while (pos) {
        v[pos] = max(v[pos], val);
        pos /= 2;
    }
}

int get(int l, int r, const vi & v) {
    l += N;
    r += N;
    int res = -1e9;
    while (l <= r) {
        if (l == r) {
            return max(res, v[l]);
        }
        if (l % 2 == 1) {
            res = max(res, v[l]);
            ++l;
        }
        if (r % 2 == 0) {
            res = max(res, v[r]);
            --r;
        }
        if (l > r) return res;
        l /= 2;
        r /= 2;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vi a(n), s(n+1);
    vi all;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s[i+1] = s[i] + a[i];
        for (int j = 0; j <= i; ++j)
            all.push_back(s[i+1] - s[j]);
    }
    sort(all.begin(), all.end());
    while (N < all.size()) N *= 2;
    up.assign(2*N, -1e9);
    dw.assign(2*N, -1e9);
    all.resize(unique(all.begin(), all.end()) - all.begin());
    vvi d(n, vi(n, 0));
    for (int t = 1; t < k; ++t) {
        vvi nd(n, vi(n, -1e9));
        up.assign(2*N, -1e9);
        dw.assign(2*N, -1e9);
//      map<int, int> up, dw;
        for (int e = n-1; e >= 0; --e) {
            for (int b = 0; b <= e; ++b) {
                int cur = s[e + 1] - s[b];
                int pos = lower_bound(all.begin(), all.end(), cur) - all.begin();
                int v1 = get(pos, N - 1, up) - cur;
                int v2 = get(0, pos, dw) + cur;
                nd[b][e] = max(v1, v2);
//                cerr << b << ' ' << e << ' ' << nd[b][e] << endl;
            }
            for (int i = e; i < n; ++i) {
                int cur = s[i+1] - s[e];
                int curu = d[e][i] + cur;
                int curd = d[e][i] - cur;
                int pos = lower_bound(all.begin(), all.end(), cur) - all.begin();
                put(pos, curu, up);
                put(pos, curd, dw);
/*                if (up.count(cur)) {
                    up[cur] = max(up[cur], d[e][i] + cur);
                } else {
                    up[cur] = d[e][i] + cur;
                }
                if (dw.count(cur)) {
                    dw[cur] = max(dw[cur], d[e][i] - cur);
                } else {
                    dw[cur] = d[e][i] - cur;
                }*/
            }
        }
        d.swap(nd);
    }
    int res = -1e9;
    for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j)
        res = max(res, d[i][j]);
    cout << res << endl;
    return 0;
}