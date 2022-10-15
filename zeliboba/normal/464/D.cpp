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
typedef vector<long double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
    int n, k;
    cin >> n >> k;
    vd p(600);
    p[1] = 1;
    vd m(n+1);
    for (int i = 0; i < n; ++i) {
        vd np(p.size(), 0);
        m[i+1] = m[i];
        int b = 0;
        if (i >= 10000) b = sqrt(i);
        for (int j = b+1; j < p.size(); ++j) {
            np[j] = p[j] * j / (j+1) + p[j-1] / j;
            m[i+1] += p[j] * (j*(j+3)/2) / (j + 1);
        }
        p.swap(np);
    }
    if (k == 1) {
        printf("%.15lf\n", (double)m[n]);
        return 0;
    }
    double res = 0;
    vd lnfac(n + 1);
    for (int i = 2; i < lnfac.size(); ++i)
        lnfac[i] = lnfac[i-1] + log(i);
    for (int i = 0; i < m.size(); ++i) {
        double prob = exp((n-i)*log(k-1) - n*log(k) + lnfac[n] - lnfac[i] - lnfac[n-i]);
        res += prob*m[i];
    }
    printf("%.15lf\n", (double)(k*res));
//    cerr << m.back() << endl;
/*    cerr << p.back() << endl;
    for (int i = 0; i < p.size(); ++i) {
        cerr << p[i] << ' ';
    }*/
    return 0;
}