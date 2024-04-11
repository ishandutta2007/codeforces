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
typedef long double ld;
typedef vector<ld> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int N = 1000000;
vd lnfac(N);

ld c(int i, int j) {
    if (i > j || j < 0) return 0;
    return exp(lnfac[j] - lnfac[i] - lnfac[j-i]);
}

ld lnc(int i, int j) {
    return lnfac[j] - lnfac[i] - lnfac[j-i];
}

int main() {
    for (int i = 2; i < N; ++i) {
        lnfac[i] = lnfac[i-1] + log((ld)i);
    }
    int n,m,k;
    cin >> n >> m >> k;
    vd p(2*n + 1);
    for (int i = 0; i <= n; ++i) for (int j = 0; j <= n; ++j) {
        int used = n*n - (n-i)*(n-j);
        if (used > k) continue;
        double lnmul = lnc(i, n) + lnc(j, n);
        p[i+j] += exp(lnmul + lnc(k-used, m - used) - lnc(k, m));
    }
    ld res = 0, add = 0;
/*    if (k >= n * n) {
        res = exp(lnc(k - n*n, m - n*n) - lnc(k, m)) * pow((ld)2, (ld)(2*n));
    }*/
    for (int i = 2*n; i >= 0; --i) {
        ld add = p[i];
        /*for (int j = i + 1; j <= 2*n; ++j) {
            ld zn = 1;
            if ((j - i) % 2) zn = -1;
            add += zn*p[j]*c(i, j);
        }
        cerr << i << ' ' << add << ' ' << p[i] << endl;*/
        res += max((ld)0., add);//*pow((ld)2, (ld)i);
        if (res > 1e99) {
            res = 1e99;
            break;
        }
    }
    printf("%.20lf\n", (double)res);
    return 0;
}