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

vi erat(1000001);

void f(int x, vi & c) {
  while (x > 1) {
    int p = erat[x], t = 0;
    while (x % p == 0) {
      x /= p;
      ++t;
    }
    c[p] = max(c[p], t);
  }
}

int main() {
  for (int i = 0; i < erat.size(); ++i) erat[i] = i;
  for (int i = 2; i * i < erat.size(); ++i) if (erat[i] == i) {
    for (int j = i*i; j < erat.size(); j += i) erat[j] = i;
  }
  int n, k;
  scanf("%d%d",&n,&k);
  vi need(erat.size()), ma(erat.size());
  f(k, need);
  vi a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);  
    f(a[i], ma);
  }
  bool ok = 1;
  for (int i = 0; i < erat.size(); ++i) {
    if (need[i] > ma[i]) ok = 0;
  }
  if (ok) printf("Yes\n");
  else printf("No\n");
  return 0;
}