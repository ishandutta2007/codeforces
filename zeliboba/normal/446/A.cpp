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
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vi l(n), r(n);
    for (int i = 0; i < n; ++i) {
        l[i] = i;
        if (i && a[i] > a[i-1]) l[i] = l[i-1];
    }
    for (int i = n-1; i >= 0; --i) {
        r[i] = i;
        if (i+1<n && a[i] < a[i+1]) r[i] = r[i+1];
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int res = max(1+r[1], n-l[n-2]);
    for (int i = 1; i+1 < n; ++i) {
        res = max(res, 1 + r[i+1] - i);
        res = max(res, i+1 - l[i-1]);
        if (a[i-1] + 2 <= a[i+1]) {
            res = max(res, r[i+1] - l[i-1] + 1);
        }
    }
    cout << res << endl;
    return 0;
}