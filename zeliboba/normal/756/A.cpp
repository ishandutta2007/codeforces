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

int main() {
  int n;
  scanf("%d", &n);
  vi p(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
  }
  int s = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    s += b[i];
  }
  int cnt = 0;
  vi was(n);
  for (int i = 0; i < n; ++i) if (!was[i]) {
    ++cnt;
    int cur = i;
    while (!was[cur]) {
      was[cur] = 1;
      cur = p[cur];
    }
  }
  int res = 1 - s%2;
  if (cnt > 1) res += cnt;
  printf("%d\n", res);
  return 0;
}