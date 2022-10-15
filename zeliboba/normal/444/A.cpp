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
typedef vector<string> vs;

int main() {
    int n, m;
    cin >> n >> m;
    vi v(n);
    for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
    double ma = 0;
    for (int i = 0; i < m; ++i) {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        --a; --b;
        ma = max(ma, (v[a] + v[b]) / (double)c);
    }
    printf("%.10lf\n", ma);
    return 0;
}