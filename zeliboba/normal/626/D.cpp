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
  vi a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  const int N = 15000;
  vvl d(2, vl(2*N + 1));
//  d[0][N] = 1;
  vi v(5001);
  for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j) if (i != j) {
    v[abs(a[i]-a[j])]++;
    d[1][abs(a[i]-a[j])+N]++;
    d[0][-abs(a[i]-a[j])+N]++;
  }
  for (int t = 1; t < 3; ++t) {
    vvl nd(2, vl(d[0].size()));
    for (int w = 0; w < 2; ++w) for (int i = 0; i < d[w].size(); ++i) if (d[w][i]) {
      for (int w1 = 0; w1 + w <= 1; ++w1) {
        if (t == 2 && w1+w != 1) continue;
        if (w1 == 0) {
          for (int j = 0; j <= min(5000, i); ++j) nd[w1+w][i-j] += d[w][i]*v[j];
        } else {
          for (int j = 0; j <= min(5000, 2*N-i); ++j) nd[w1+w][i+j] += d[w][i]*v[j];
        }
      }
    }
    d.swap(nd);
//    for (int w = 0; w < 2; ++w) for (int i = 0; i < d[w].size(); ++i) if (d[w][i]) cerr << t << ' ' << w << ' ' << i-N << ' ' << d[w][i] << endl;
  }
  double res = 0;
  vl s;
  for (int i = N + 1; i < d[1].size(); ++i) s.push_back(d[1][i]);
  sort(s.begin(), s.end());
  for (int i = 0; i < s.size(); ++i) res += s[i];
  double all = n*(n-1)/2;
  all *= 3*all*all;
  printf("%.9lf\n", res / all);
  return 0;
}