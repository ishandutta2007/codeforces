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

int sign(ll x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

int main() {
    ll x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    vl a(n), b(n), c(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        if (sign(a[i]*x1+b[i]*y1+c[i]) != sign(a[i]*x2+b[i]*y2+c[i]))
            ++res;
    }
    cout << res << endl;
    return 0;
}