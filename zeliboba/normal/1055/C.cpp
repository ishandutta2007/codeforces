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
#include <chrono>
#include <random>
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

ll f(array<ll, 3> a, array<ll, 3> b) {
  //r = (b[0] + k * b[2]) % a[2]
  ll d = __gcd(a[2], b[2]);
  // b[0] + k * d
  ll la = a[1] - a[0] + 1;
  ll lb = b[1] - b[0] + 1;
  ll ra = a[0] % d;
  ll rb = b[0] % d;
  if (ra > rb) rb += d;
  return min(ra + la - rb, lb);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  array<ll, 3> a, b;
  cin >> a[0] >> a[1] >> a[2];
  cin >> b[0] >> b[1] >> b[2];
  cout << max(0LL, max(f(a, b), f(b, a))) << endl;
  return 0;
}