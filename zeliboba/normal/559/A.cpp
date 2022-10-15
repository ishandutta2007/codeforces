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
    vi a(6);
    for (int i = 0; i < 6; ++i) cin >> a[i];
    ll res = 0;
    bool ok = 1;
    while (ok) {
        ok = 0;
        for (int i = 0; i < 6; ++i) {
            int & x = a[(i+1)%6];
            int & y = a[(i+5)%6];
            if (x > 0 && y > 0) {
                res += 2*a[i]+1;
                --x; --y;
                ok = 1;
                ++a[i];
            }
        }
    }
    cout << res << endl;
    return 0;
}