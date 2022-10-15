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
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

const ll MAX = 100000LL * 1000000000LL;

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vi a(n);
  vl s(n + 1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    s[i+1] = s[i] + a[i];
  }
  vl cand(1, 1);
  if (k == -1) cand.push_back(-1);
  if (abs(k) > 1) for (int i = 0; i < 60; ++i) {
    ll x = k * cand.back();
    if (abs(x) > MAX) break;
    cand.push_back(x);
  }
  ll res = 0;
  map<ll, int> was;
  was[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < cand.size(); ++j) {
      ll need = s[i] - cand[j];
      if (was.count(need)) res += was[need];
    }
    was[s[i]]++;
  }
  printf("%lld\n", res);
  return 0;
}