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
    vi c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];
    vector<vvi> d(2, vvi(n, vi(n, n)));
    for (int l = 1; l <= n; ++l) {
      for (int i = 0; i + l <= n; ++i) {
        int j = i + l - 1;
        for (int t = i; t < j; ++t) d[0][i][j] = min(d[0][i][j], d[0][i][t] + d[0][t+1][j]);
        if (c[i] == c[j]) {
          if (l <= 2) {
            d[0][i][j] = 1;
          } else {
            d[0][i][j] = min(d[0][i][j], d[0][i+1][j-1]);
          }
        }
      }
    }
    cout << d[0][0][n-1] << endl;
    return 0;
}