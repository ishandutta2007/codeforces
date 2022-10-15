#include <cstdio>
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

int main() {
  ll a, b;
  cin >> a >> b;
  vl c;
  for (ll p2 = 2; p2 < (1LL << 62); p2 *= 2) {
    for (ll p1 = 1; p1 < p2/2; p1 *= 2) {
      ll x = p2 - 1 - p1;
      if (x >= a && x <= b) c.push_back(x);
    }
  }
  sort(c.begin(), c.end());
  cout << (int)(unique(c.begin(), c.end()) - c.begin()) << endl;
  return 0;
}