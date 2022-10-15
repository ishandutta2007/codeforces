#include <stdio.h>
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
const int mod = 1000000007;

char s0[80];
const int N = 1 << 20;
int d[6][N];

int dw(int x) {
  if (x >= mod) return x - mod;
  return x;
}

ll solve(const vi & s, int n) {
  memset(d, 0, sizeof(d));
  for (int i = 0; i < 6; ++i) d[i][0] = 1;
  ll res = 0;
  vi good;
  for (int i = 1; i <= 20; ++i) good.push_back((1 << i) - 1);
  for (int i = 0; i <= n; ++i) {
    int st = i % 6;
    if (i != n && s[i] == 0) {
      int nx = (st + 1) % 6;
      for (int mask = 0; mask < N; ++mask) {
        d[nx][mask] = dw(d[nx][mask] + d[st][mask]);
      }
    } else {
      for (int x : good) res = (res + d[st][x]) % mod;
      int add = 0;
      for (int l = 0; l < 5 && i + l < n; ++l) {
        add = 2*add + s[i + l];
        if (!add || add > 20) continue;
        int A = 1 << (add - 1);
        int nx = (st + l + 1) % 6;
        //      cerr << st << ' ' << nx << ' ' << A << ' ' << endl;
        for (int mask = 0; mask < N; ++mask) {
          d[nx][mask | A] = dw(d[nx][mask | A] + d[st][mask]);
        }
      }
    }
    memset(d[st], 0, sizeof(d[st]));
    d[st][0] = 1;
  }
  return res;
}

ll stupid(const vi & s, int n) {
  ll res = 0;
  for (int mask = 1; mask < (1 << (n + 1)); ++mask) if (__builtin_popcount(mask) > 1) {
    vi x;
    for (int i = 0; i <= n; ++i) if (mask & (1 << i)) x.push_back(i);
    vi was(n + 2);
    bool fail = 0;
    int ma = 0;
    for (int i = 0; i + 1 < x.size(); ++i) {
      int a = 0;
      for (int j = x[i]; j < x[i+1]; ++j) a = a * 2 + s[j];
      if (!a || a >= was.size()) {
        fail = 1; break;
      }
      was[a]++;
      ma = max(ma, a);
    }
    if (fail) continue;
    for (int i = 1; i <= ma; ++i) if (!was[i]) {
      fail = 1; break;
    }
    res += !fail;
  }
  return res % mod;
}

void out(const vi & s) {
  for (int x : s) cerr << x; cerr << endl;
}

int main() {
/*  for (int n = 1; n <= 15; ++n) {
    cerr << n << endl;
    vi s(n);
    for (int mask = 0; mask < (1 << n); ++mask) {
      for (int i = 0; i < n; ++i) {
        s[i] = (bool)(mask & (1 << i));
      }
      ll s1 = solve(s, n), s2 = stupid(s, n);
      //out(s); cerr << s1 << ' ' << s2 << endl;
      assert(s1 == s2);
    }
  }*/
  int n;
  scanf("%d%s", &n, s0);
  vi s(n);
  for (int i = 0; i < n; ++i) s[i] = s0[i] - '0';
  printf("%lld\n", solve(s, n));
  return 0;
}