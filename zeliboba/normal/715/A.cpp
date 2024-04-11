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
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
  ll n;
  cin >> n;
//  ll cur = 2;
  cout << 2 << endl;
  for (ll i = 2; i <= n; ++i) {
    ll x = i * (i + 1) * (i + 1) - (i - 1);
    cout << x << endl;
//    cur += x*i;
//    cerr << cur << endl;
//    cur = round(sqrt(cur));
  }
  return 0;
}