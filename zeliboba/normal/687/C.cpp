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
#include <bitset>
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

const int N = 501;
const int MAX = N*N;
bitset<MAX> d[N];

int main() {
  int n, k;
  cin >> n >> k;
  vi c(n);
  for (int i = 0; i < n; ++i) cin >> c[i];
  d[0].set(0);
  for (int i = 0; i < n; ++i) {
    d[i+1] = d[i] | (d[i] << (c[i]*N));
    for (int a = 0; a <= k; ++a) for (int b = 0; b <= k - c[i]; ++b) {
      int j = a*N + b;
      if (d[i].test(j)) {
        d[i+1].set(j + c[i]);
      }
    }
  }
  vi res;
  for (int i = 0; i <= k; ++i) if (d[n].test(i*N + k-i)) {
    res.push_back(i);
  }
  cout << res.size() << endl;
  for (int i : res) cout << i << ' ';
  return 0;
}