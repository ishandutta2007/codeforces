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
    int n, k, x;
    cin >> n >> k >> x;
    vl a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.rbegin(), a.rend());
    ll res = 0;
    vl l(n), r(n);
    for (int i = 1; i < n; ++i) l[i] = l[i-1] | a[i-1];
    for (int i = n-2; i >= 0; --i) r[i] = r[i+1] | a[i+1];
    for (int t = 0; t < n; ++t) {
        for (int i = 0; i < k; ++i) a[t] *= x;
        res = max(res, a[t] | l[t] | r[t]);
    }
    cout << res << endl;
    return 0;
}