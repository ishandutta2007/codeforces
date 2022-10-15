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
    int n;
    cin >> n;
    vii a(n);
    for (int i = 0; i < n; ++i) scanf("%d %d", &a[i].first, &a[i].second);
    sort(a.begin(), a.end());
    vi x(n);
    for (int i = 0; i < n; ++i) x[i] = a[i].first;
    vi d(n, 1);
    int res = n-1;
    for (int i = 1; i < n; ++i) {
      int it = lower_bound(x.begin(), x.end(), x[i] - a[i].second) - x.begin();
      --it;
      if (it >= 0) d[i] += d[it];
//      cerr << i << ' ' << it << ' ' << d[i] << endl;
      res = min(res, n - d[i]);
    }
    cout << res << endl;
    return 0;
}