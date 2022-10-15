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
const int mod = 1000000007;

vi p;

ll phi(ll n) {
  if (n == 1) return 1;
  ll res = 1;  
  for (ll x : p) {
    if (x * x > n) break;
    if (n % x == 0) {
      res *= x-1;
      n /= x;
      while (n % x == 0) {
        n /= x;
        res *= x;
      }
    }
  }
  if (n > 1) res *= n-1;
  return res;
}

int main() {
  vi erat(1000000, 1);
  for (int i = 2; i * i < erat.size(); ++i) if (erat[i]) {
    for (int j = i * i; j < erat.size(); j += i) erat[j] = 0;
  }
  for (int i = 2; i < erat.size(); ++i) if (erat[i]) p.push_back(i);
  ll n, k;
  cin >> n >> k;
  k = min(1000000LL, (k + 1) / 2);
  for (int i = 0; i < k; ++i) {
    n = phi(n);
  }
  cout << n % mod << endl;
  return 0;
}