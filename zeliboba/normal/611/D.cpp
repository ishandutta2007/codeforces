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
const int mod = 1000000007;

char s[5005];

const ll P = 131;
const int M1 = 1000000021;
const int M2 = 989999993;
vii mhash(const vi & v) {
  vii h(v.size() + 1);
  for (int i = 0; i < v.size(); ++i) {
    h[i + 1] = pii((h[i].first*P + v[i]) % M1, (h[i].second*P + v[i]) % M2);
  }
  return h;
}

ll pw[2][100005];

vii h;
vi v;

bool f(int i, int j, int L) {
  int l = 0, r = L+1;
  while (r - l > 1) {
    int t = (l + r) / 2;
    bool ok = 1;
    if ((h[i+t].first - h[j+t].first - h[i].first*pw[0][t] + h[j].first*pw[0][t]) % M1 ||
        (h[i+t].second - h[j+t].second - h[i].second*pw[1][t] + h[j].second*pw[1][t]) % M2) {
      ok = 0;
    }
    if (ok) {
      l = t;
    } else {
      r = t;
    }
  }
  return l < L && v[i+l] < v[j+l];
}

int main() {
  pw[0][0] = pw[1][0] = 1;
  for (int i = 1; i < 100000; ++i) {
    pw[0][i] = pw[0][i-1]*P%M1;
    pw[1][i] = pw[1][i-1]*P%M2;
  }
  int n;
  scanf("%d%s", &n, s);
  v.resize(n);
  for (int i = 0; i < n; ++i) v[i] = s[i];
  h = mhash(v);
  vvi d(n, vi(n));
  vvi sum(n, vi(n + 1));
  for (int i = n-1; i >= 0; --i) {
    if (s[i] == '0') continue;
    d[i][n-1] = 1;
    for (int j = i; j < n-1; ++j) {
      int t = j-i+j+2;
      if (t <= n) {
        d[i][j] = sum[j+1].back() - sum[j+1][t];
        if (f(i, j+1, j-i+1)) d[i][j] += d[j+1][t-1];
        d[i][j] %= mod;
      }
    }
    for (int j = i; j < n; ++j) {
      sum[i][j+1] = (sum[i][j] + d[i][j]) % mod;
    }
  }
  ll res = 0;
  for (int i = 0; i < n; ++i) res += d[0][i];
  cout << (res % mod + mod) % mod << endl;
  return 0;
}