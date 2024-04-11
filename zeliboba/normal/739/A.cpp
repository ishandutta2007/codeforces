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
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
  //  std::ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vi a(n);
  int mi = n;
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    mi = min(mi, r - l + 1);
  }
  cout << mi << endl;
  for (int i = 0; i < n; ++i) cout << i % mi << ' ';
  return 0;
}