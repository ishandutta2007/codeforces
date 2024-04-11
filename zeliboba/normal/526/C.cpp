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

int main() {
    ll c,a,b,wa,wb;
    cin >> c >> a >> b >> wa >> wb;
    int d = __gcd(wa,wb);
    wa /= d;
    wb /= d;
    c /= d;
    if (wa > wb) {
        swap(a,b);
        swap(wa,wb);
    }
    /*if (a >= b) {
        ll x = c/wa;
        cout << a*x + (c - wa*x)/wb*b << endl;
        return 0;
    }*/
    ll add = 0;
    if (c >= 4*wa*wb) {
        int t = c/wa/wb - 4;
        c %= (wa*wb);
        c += 4*wa*wb;
        ll p = max(wb*a, wa*b);
        add = p*t;
    }
    ll ma = 0;
    for (int y = 0; y <= c/wb; ++y) {
        ma = max(ma, y*b + (c-y*wb)/wa*a);
    }
    cout << ma + add << endl;
    return 0;
}