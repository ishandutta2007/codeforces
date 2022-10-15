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
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
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
//const int mod = ;

int a, b;

void go(int i, int N, vi& was, int& cnt) {
  if (was[i]) return;
  was[i] = 1;
  ++cnt;
  if (i >= b) go(i - b, N, was, cnt);
  if (i + a <= N) go(i + a, N, was, cnt);
}

ll calc(ll x) {
  int d = __gcd(a, b);
  ll div = x / d;
  return x + 1 + (x % d + 1) * div + (div - 1) * div / 2 * d;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n >> a >> b;
  vi was(min(n + 1, 1000001));
  was[0] = 1;
  int cur = 1;
  ll res = 1;
  for (int i = 1; i < (int)was.size(); ++i) {
    if (i >= a && was[i - a]) {
      go(i, i, was, cur);
    }
    res += cur;
  }
  res += calc(n) - calc((int)was.size() - 1);
  cout << res << endl;
  return 0;
}