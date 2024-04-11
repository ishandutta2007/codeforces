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
    int n;
    cin >> n;
    vd p(n);
    for (int i = 0; i < n; ++i) scanf("%lf", &p[i]);
    sort(p.begin(), p.end());
    long double ma = p.back();
    long double prod = 1, sum = 0;
    for (int i = n-1; i >= 0; --i) {
        long double q = 1 - p[i];
        prod *= q;
        sum += 1./q - 1;
        ma = max(ma, prod*sum);
    }
    printf("%.15lf\n", (double)ma);
    return 0;
}