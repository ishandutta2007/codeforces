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

double mpow(double x, int n) {
    double res = 1;
    while (n) {
        if (n & 1) res *= x;
        x *= x;
        n /= 2;
    }
    return res;
}

int main() {
    int n, T;
    cin >> n >> T;
    vi t(n), p(n);
    vd pp(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> t[i];
        p[i] = 100 - p[i];
        pp[i] = p[i] / 100.;
    }
    vd q(T + 1);
    q[0] = 1;
    double res = 0;
    for (int i = 0; i < n; ++i) {
        vd nq(T + 1);
        double pwt = mpow(pp[i], t[i] - 1);
        //vd pw(T + 1, 1);
        //for (int j = 1; j < pw.size(); ++j)
        //    pw[j] = pw[j-1] * pp[i];
        double sum = 0;
        for (int j = 0; j <= T; ++j) {
//            sum *= pp[i];
//            cerr << j << ' ' << sum << endl;
            if (j >= t[i]) {
                double add = pwt*q[j-t[i]];
                sum -= add;
                nq[j] += add;
            }
            nq[j] += sum * (1. - pp[i]);
            sum *= pp[i];
            sum += q[j];
        }
        q.swap(nq);
        for (int j = 0; j < q.size(); ++j) {
            res += q[j];
        }
//        cerr << res << endl;
    }
    printf("%.15lf\n", res);
    return 0;
}