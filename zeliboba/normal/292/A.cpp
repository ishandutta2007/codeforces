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

int main() {
    int n;
    cin >> n;
    vl t(n), c(n);
    ll ma = 0, cur = 0, curt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> c[i];
        if (i) {
            cur -= min(cur, t[i] - t[i-1]);
        }
        curt = t[i];
        cur += c[i];
        if (cur > ma)
            ma = cur;
    }
    cout << t.back() + cur << ' ' << ma << endl;
    return 0;
}