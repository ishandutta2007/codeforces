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

int ma[1 << 20];
int N = 1;

void add(int pos, int val) {
    pos += N;
    while (pos) {
        ma[pos] = max(ma[pos], val);
        pos /= 2;
    }
}

int getma(int l, int r) {
    int res = 0;
    l += N; r += N;
    while (l <= r) {
        if (l == r) {
            return max(ma[l], res);
        }
        if (l % 2) {
            res = max(res, ma[l]);
            ++l;
        }
        if (r % 2 == 0) {
            res = max(res, ma[r]);
            --r;
        }
        if (r < l) break;
        l /= 2; r /= 2;
    }
    return res;
}

int main() {
    memset(ma, 0, sizeof(ma));
    int n, q;
    scanf("%d", &n);
    while (N < n) N *= 2;
    vi p(n), l(n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &p[i], &l[i]);
    vi maxd(n);
    vvi nx(18, vi(n));
    vvl c(nx.size(), vl(n));
    maxd[n-1] = p[n-1] + l[n-1];
    add(n-1, maxd[n-1]);
    for (int i = n-2; i >= 0; --i) {
        maxd[i] = p[i] + l[i];
        int it = upper_bound(p.begin(), p.end(), p[i] + l[i]) - p.begin();
        maxd[i] = max(maxd[i], getma(i + 1, it - 1));
        add(i, maxd[i]);
    }
    for (int i = 0; i < n; ++i) {
        int it = upper_bound(p.begin(), p.end(), maxd[i]) - p.begin();
        it = min(it, n-1);
        nx[0][i] = it;
        c[0][i] = max(0, p[it] - maxd[i]);
    }
    for (int b = 1; b < nx.size(); ++b) {
        for (int i = 0; i < n; ++i) {
            nx[b][i] = nx[b-1][nx[b-1][i]];
            c[b][i] = c[b-1][i] + c[b-1][nx[b-1][i]];
        }
    }
    scanf("%d", &q);
    //vi x(q), y(q);
    for (int i = 0; i < q; ++i) {
        int x,y;
        scanf("%d%d", &x, &y);
        --x; --y;
        ll sum = 0;
        int b = c.size() - 1;
        while (maxd[x] < p[y]) {
            while (b > 0 && nx[b][x] >= y) {
                --b;
            }
            sum += c[b][x];
            x = nx[b][x];
        }
        cout << sum << endl;
    }
    return 0;
}