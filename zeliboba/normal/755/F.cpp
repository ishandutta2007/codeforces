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

int getmi(int n, int k, const vi & cl) {
  int odd = 0;
  for (int i = 0; i < cl.size(); ++i) {
    k -= i / 2 * cl[i];
    if (i % 2) odd += cl[i];
  }
  if (k <= 0) return 0;
  if (k <= odd) {
    return k;
  }
  k -= odd;
  return 2*k+odd;
}

bitset<1000000> w;
int getma(int n, int k, vi cl) {
  w.set(0);
  for (int i = 0; i < cl.size(); ++i) if (cl[i]) {
    while (cl[i] > 2) {
      ++cl[2*i];
      cl[i] -= 2;
    }
    for (int j = 0; j < cl[i]; ++j) w |= (w << i);
  }
  if (w.test(k)) return k;
  return k-1;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  k = n-k;
  vi p(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
  }
  vi cl(n + 1);
  vi was(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) if (!was[i]) {
    int cur = i, c = 0;
    while (!was[cur]) {
      ++c;
      was[cur] = 1;
      cur = p[cur];
    }
    sum += c;
    //cerr << c << endl;
    ++cl[c];
  }
  assert(sum == n && cl[0] == 0 && cl[1] == 0);
  cout << n-getma(n, k, cl) << ' ' << n-getmi(n, k, cl) << endl;
  return 0;
}