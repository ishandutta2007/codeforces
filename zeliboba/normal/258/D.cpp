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

double p[1001][1001];

void sett(int i, int j, double t) {
    p[i][j] = t;
    p[j][i] = 1 - t;
}

int main() {
    int n, m;
    cin >> n >> m;
    vi v(n), a(m), b(m), w(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        --v[i];
        w[v[i]] = i;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        --a[i]; --b[i];
    }
    memset(p, 0, sizeof(p));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            p[i][j] = 1.;
    for (int i = m - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            double t = (p[a[i]][j] + p[b[i]][j]) / 2.;
            sett(a[i], j, t);
            sett(b[i], j, t);
        }
        sett(a[i], b[i], 0.5);
    }
    double res = 0;
/*    vector<double> s(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.;
        vector<double> s1(n + 1);
        for (int pos = 0; pos < n; ++pos) {
            if (pos)
                res += s[pos - 1] * p[w[i]][pos];
            sum += p[w[i]][pos];
            s1[pos] = sum;
        }
        for (int pos = 0; pos < n; ++pos)
            s[pos] += s1[pos];
    }*/
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (v[i] < v[j])
        res += p[i][j];
    printf("%.12lf\n", res);
    return 0;
}