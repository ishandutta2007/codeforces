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

ll n, k;

bool ask(ll l, ll r) {
  cout << l << ' ' << r << endl;
  cout.flush();
  string s;
  cin >> s;
  if (s == "No") return false;
  else if (s == "Yes") {
    if (l == r) exit(0);
    return true;
  } else {
    assert(0);
  }
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  srand(12382716487136483724198579248789124134);
  cin >> n >> k;
  ll l = 1, r = n;
  while (1) {
    if (r - l > 5 * k) {
      ll m = (l + r) / 2;
      if (ask(l, m)) {
        r = m;  
      } else {
        l = m + 1;
      }
    } else {
      ll x = l + rand() % (r - l + 1);
      ask(x, x);
    }
    l = max(1LL, l - k);
    r = min(n, r + k);
  }
  return 0;
}