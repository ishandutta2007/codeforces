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
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<ll, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

ll p2(ll x) {
  return x * x;
}

ll calc(ll a, ll c) {
  return (a % c) * p2(a / c + 1) + (c - a % c) * p2(a / c);
}

ll f(ll a, ll c) {
  if (c == a) return 0;
  return -calc(a, c) + calc(a, c + 1);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  cin >> n >> k;
  vl a(n), c(n, 1);
  set<pii> q;
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    res += p2(a[i]);
    q.insert(pii(f(a[i], c[i]), i));
  }
  while (k > n) {
    --k;
    int i = q.begin()->second;
    res += q.begin()->first;
    q.erase(q.begin());
    ++c[i];
    q.insert(pii(f(a[i], c[i]), i));
  }
  cout << res << '\n';
/*  int l = 0, r = a.back();
  while (r - l > 1) {
    int x = (l + r) / 2;
    ll s = 0;
    for (ll t : a) {
    }
    if (s <= k) r = x;
    else l = x;
  }*/
  return 0;
}