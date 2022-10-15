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

vvi v;
int n, p;
int d[4001][4001];
int d1[4001][4001];
void fill(int pos) {
    for (int i = pos; i < n && v[i][0] < v[pos][0] + p; ++i) {
        for (int c = 4000; c >= 0; --c) {
            d[i-pos+1][c] = d[i-pos][c];
            if (c >= v[i][1])
                d[i-pos+1][c] = max(d[i-pos+1][c], d[i-pos][c-v[i][1]] + v[i][2]);
        }
    }
}

int main() {
    scanf("%d%d", &n, &p);
    v.assign(n, vi(3));
    vi x1(n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d%d", &v[i][1], &v[i][2], &v[i][0]);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i)
        x1[i] = v[i][0];
    int Q;
    scanf("%d", &Q);
    vvi q(Q, vi(3));
    for (int i = 0; i < Q; ++i) {
        scanf("%d%d", &q[i][0], &q[i][1]);
        q[i][2] = i;
    }
    sort(q.begin(), q.end());
    const int m = 80;
    for (int i = 0; i <= 4000; ++i) d[0][i] = 0;
    fill(0);
    int last = 0;
    vi res(Q);
    vi e(Q, -1), b(Q, -1);
    for (int t = 0; t < q.size(); ++t) {
        if (q[t][0] >= v[n-1][0] + p) break;
        if (q[t][0] < v[0][0]) continue;
        if (q[t][0] >= v[last][0] + p) {
            last = min(last + m, n - 1);
            fill(last);
            --t;
            continue;
        }
        e[t] = (int)(upper_bound(x1.begin(), x1.end(), q[t][0]) - x1.begin()) - 1;
        b[t] = (int)(lower_bound(x1.begin(), x1.end(), q[t][0] - p + 1) - x1.begin());
        if (b[t] > e[t]) continue;
        //cerr << t << ' ' << last << ' ' << b[t] << ' ' << e[t] << endl;
        assert(e[t] < n && b[t] >= 0 && last >= b[t]);
        int start = min(last, e[t] + 1);
        if (!t || e[t] != e[t-1] || b[t] != b[t-1]) {
            for (int i = 0; i <= 4000; ++i)
                d1[0][i] = d[max(0, e[t] - last + 1)][i];
            for (int i = start - 1; i >= b[t]; --i) {
                for (int c = 4000; c >= 0; --c) {
                    d1[start - i][c] = d1[start - i - 1][c];
                    if (c >= v[i][1]) {
                        d1[start - i][c] = max(d1[start - i][c], d1[start - i - 1][c - v[i][1]] + v[i][2]);
                    }
                }
            }
        }
        int s = start - b[t];
        for (int c = 0; c <= q[t][1]; ++c)
            res[q[t][2]] = max(res[q[t][2]], d1[s][c]);
    }
    for (int i = 0; i < Q; ++i)
        printf("%d\n", res[i]);
    return 0;
}