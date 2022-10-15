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

int f(int a, int b, int c) {
  return min(b, max(a, c));
}

int f(const vi & a, int i) {
  assert(i > 0 && i + 1 < a.size());
  return f(a[i-1], a[i], a[i+1]);
}

int main() {
  int n;
  scanf("%d", &n);
  vi a(n);
  vi res(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    res[n-1] = max(res[n-1], a[i]);
  }
  if (n == 1) {
    printf("%d\n", a[0]);
    return 0;
  }
  if (n % 2) {
    res[1] = max(a[n/2], max(a[n/2-1], a[n/2+1]));
    for (int t = 3; t < n; t += 2) {
      res[t] = max(res[t-2], max(a[n/2-1-t/2], a[n/2+1+t/2]));
    }
    res[0] = f(a, n/2);
    for (int t = 2; t < n-2; t += 2) {
      res[t] = max(res[t-2], max(f(a, n/2-t/2), f(a, n/2+t/2)));
    }
  } else {
    res[0] = max(a[n/2], a[n/2-1]);
    for (int t = 2; t < n; t += 2) {
      res[t] = max(res[t], max(res[t-2], max(a[n/2-1-t/2], a[n/2+t/2])));
    }
    if (n != 2) {
      res[1] = max(f(a, n/2-1), f(a, n/2));
      for (int t = 3; t < n-2; t += 2) {
        res[t] = max(res[t], max(res[t-2], max(f(a, n/2-1-t/2), f(a, n/2+t/2))));
      }
    }
  }
  for (int i = 0; i < n; ++i) printf("%d ", res[i]);
  return 0;
}