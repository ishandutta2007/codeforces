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

int main() {
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  scanf("%d%d", &n, &k);
  vi c(n);
  for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
  vi t(n);
  priority_queue<pii> q;
  for (int i = 0; i < k; ++i) q.push(pii(c[i], i));
  ll res = 0;
  for (int i = k; i < n + k; ++i) {
    if (i < n) q.push(pii(c[i], i));
    int x = q.top().second;
    q.pop();
    t[x] = i + 1;
    res += c[x] * (ll)(i - x);
  }
  printf("%lld\n", res);
  for (int x : t) printf("%d ", x);
  return 0;
}