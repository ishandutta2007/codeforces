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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
int n, m;

double p2(double x) {
    return x*x;
}

bool ok(pii x) {
    return x.first >= 0 && x.second >= 0 && x.first <= n && x.second <= m;
}

double l(vii p) {
    for (int i = 0; i < p.size(); ++i) for (int j = i + 1; j < p.size(); ++j) if (p[i] == p[j])
        return 0;
    for (int i = 0; i < p.size(); ++i) if (!ok(p[i]))
        return 0;
    double sum = 0;
    for (int i = 0; i + 1 < p.size(); ++i) {
        sum += sqrt(p2(p[i].first-p[i+1].first) + p2(p[i].second - p[i+1].second));
    }
    return sum;
}

pii f(int k) {
    return pii(k/4, k%4);
}

int main() {
    cin >> n >> m;
    double ma = 0;
    vii best;
    for (int i1 = 0; i1 < 16; ++i1) for (int i2 = 0; i2 < 16; ++i2) {
        for (int j1 = 0; j1 < 16; ++j1) for (int j2 = 0; j2 < 16; ++j2) {
            vii v(4);
            v[0] = f(i1);
            v[2] = f(i2);
            v[1] = f(j1);
            v[3] = f(j2);
            for (int t = 1; t <= 3; t += 2) {
                v[t].first = n - v[t].first;
                v[t].second = m - v[t].second;
            }
            //cerr << l(v) << endl;
            if (l(v) > ma) {
                ma = l(v);
                best = v;
            }
        }
    }
    for (int i = 0; i < best.size(); ++i) {
        cout << best[i].first << ' ' << best[i].second << endl;
    }
    return 0;
}