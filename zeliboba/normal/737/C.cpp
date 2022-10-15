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
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
  int n, s;
  scanf("%d%d", &n, &s);
  --s;
  vi a(n), c(n);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (s != i) {
      ++c[a[i]];
    } else {
      if (a[i]) ++res;
    }
  }
  res += c[0];
  int it = n-1;
  while (it > 0 && c[it] == 0) --it;
  for (int i = 1; i < it; ++i) {
    if (!c[i]) {
      if (c[0]) {
        --c[0];
        continue;
      }
      ++res;
      --c[it];
      while (it > 0 && c[it] == 0) --it;
    }
  } 
  printf("%d\n", res);
  return 0;
}