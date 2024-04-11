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
  int n, m;
  cin >> n >> m;
  vs a(n), b(m);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int c = 0;
  for (int i = 0; i < n; ++i) if (binary_search(b.begin(), b.end(), a[i])) ++c;
  n -= c;
  m -= c;
  if (c % 2) ++n;
  if (n > m) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}