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
  int n;
  scanf("%d", &n);
  vi a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }
  vi was(n);
  vi c;
  int good = -1;
  for (int i = 0; i < n; ++i) if (!was[i]) {
    int cur = i;
    while (!was[cur]) {
      was[cur] = i + 1;
      cur = a[cur];
    }
    if (was[cur] != i + 1) continue;
    if (a[cur] == cur) good = c.size();
    c.push_back(cur);
  }
  int ch = c.size() - 1;
  if (good == -1) {
    ++ch;
    good = 0;
    a[c[good]] = c[good];
  }
  for (int i = 0; i < c.size(); ++i) if (i != good) {
    a[c[i]] = c[good];
  }
  printf("%d\n", ch);
  for (int i = 0; i < n; ++i) printf("%d ", a[i] + 1);
  return 0;
}