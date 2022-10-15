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
//const int mod = ;

const int N = 15000001;
int c[N];
char erat[N];

int main() {
//  std::ios::sync_with_stdio(false); std::cin.tie(0);
  memset(erat, 1, sizeof(erat));
  erat[0] = erat[1] = 0;
  for (int i = 2; i * i < N; ++i) if (erat[i]) {
    for (int j = i * i; j < N; j += i) erat[j] = 0;
  }
  int n;
  scanf("%d", &n);
//  cin >> n;
  vi a(n);
  int d = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
//    cin >> a[i];
    d = __gcd(d, a[i]);
  }
  for (int i = 0; i < n; ++i) {
    a[i] /= d;
    ++c[a[i]];
  }
  if (c[1] == n) {
    printf("-1\n");
    return 0;
  }
  int ma = 0;
  for (int p = 2; p < N; ++p) if (erat[p]) {
    int cur = 0;
    for (int i = p; i < N; i += p) cur += c[i];
    ma = max(ma, cur);
  }
  printf("%d\n", n - ma);
  return 0;
}