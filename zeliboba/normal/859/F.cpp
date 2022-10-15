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
#include <array>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//typedef long long int;

void out (const vl & v) {
  for (ll x : v) cerr << x << ' '; cerr << endl;
}

ll solve(int n, ll c, vl a) {
  vl s(a.size() + 1);
  for (int i = 0; i < a.size(); ++i) {
    a[i] = min(a[i], c);
    s[i + 1] = s[i] + a[i];
  }
  vl b(n), bs(n + 1);
  int it = -2;
  int best = 0;
  vi q(1, 0);
  for (int i = 0; i < n; ++i) {
    while (q.size() > best && s[2*q.back()]-bs[q.back()] >= s[2*i] - bs[i]) {
      q.pop_back();
    }
    q.push_back(i);
    while (it+2 <= 2*i && s[2*i+1] - s[it+2] >= c) {
      it += 2;
    }
    if (it >= 0) {
      b[i] = max(b[i], min(c, s[2*i+1] - s[it]) - (bs[i] - bs[it / 2]));
//      cerr << "it: " << it << ' ' << i << endl;
    }
    while (best < q.size() && q[best] <= it / 2) ++best;
    if (best < q.size()) {
      b[i] = max(b[i], min(c, s[2*i+1] - s[2 * q[best]]) - (bs[i] - bs[q[best]]));
//      cerr << "best: " << q[best] << ' ' << i << endl;
    }
/*    for (int j = i; j >= 0; --j) {
      b[i] = max(b[i], min(c, s[2*i+1] - s[2 * j]) - (bs[i] - bs[j]));
    }*/
    bs[i + 1] = bs[i] + b[i];
  }
  ll res = 0;
  for (int i = 0; i < b.size(); ++i) {
    res += b[i];
  }
//  out(b);
  return res;
}

ll stupid(int n, ll c, vl a) {
  vl s(a.size() + 1);
  for (int i = 0; i < a.size(); ++i) {
    a[i] = min(a[i], c);
    s[i + 1] = s[i] + a[i];
  }
  vl b(n), bs(n + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = i; j >= 0; --j) {
      b[i] = max(b[i], min(c, s[2*i+1] - s[2 * j]) - (bs[i] - bs[j]));
    }
    bs[i + 1] = bs[i] + b[i];
  }
  ll res = 0;
  for (int i = 0; i < b.size(); ++i) {
    res += b[i];
  }
//  out(b);
  return res;
}

int main() {
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int n = 1; n <= 0; ++n) {
    cerr << n << endl;
    vl a(2*n-1);
    for (int t = 0; t < 100000; ++t) {
      ll c = rand() % 100000000 + 1;
      for (int i = 0; i < a.size(); ++i) {
        a[i] = rand() % c + 1;
      }
      ll s1 = stupid(n, c, a);
      ll s2 = solve(n, c, a);
      if (s1 != s2) {
        cerr << n << ' ' << c << ' ' << s1 << ' ' << s2 << endl;
        out(a);
        assert(0);
      }
    }
  }
  int n;
  ll c;
  scanf("%d%lld", &n, &c);
  vl a(2 * n - 1);
  for (int i = 0; i < a.size(); ++i) {
    scanf("%lld", &a[i]);
  }
  printf("%lld\n", solve(n, c, a));
  return 0;
}