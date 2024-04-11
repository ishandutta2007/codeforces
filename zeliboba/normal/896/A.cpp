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

const ll MAX = 1.1e18;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
  string a = "What are you doing while sending \"";
  string b = "\"? Are you busy? Will you send \"";
  string c = "\"?";
  vl l(100005);
  l[0] = f0.size();
  for (int i = 1; i < l.size(); ++i) {
    l[i] = min(MAX, (ll)(2 * l[i-1] + a.size() + b.size() + c.size()));
  }
  int T;
  cin >> T;
  string res = "";
  for (int test = 1; test <= T; ++test) {
    ll n, k;
    cin >> n >> k;
    if (k > l[n]) {
      res += ".";
      continue;
    }
    for (int i = n; i > 0; --i) {
      assert(l[i] >= k);
      if (k <= a.size()) {
        res += a[k-1]; break;
      }
      k -= a.size();
      if (k <= l[i-1]) {
        continue;
      }
      k -= l[i-1];
      if (k <= b.size()) {
        res += b[k-1]; break;
      }
      k -= b.size();
      if (k <= l[i-1]) {
        continue;
      }
      k -= l[i-1];
      assert(k <= c.size());
      res += c[k-1]; break;
    }
    if (res.size() < test) {
      assert(k <= f0.size());
      res += f0[k-1];
    }
  }
  cout << res << endl;
  return 0;
}