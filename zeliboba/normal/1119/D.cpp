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
typedef pair<ll, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vl s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  vl d(s.size() - 1);
  for (int i = 0; i + 1 < (int)s.size(); ++i) {
    d[i] = s[i+1] - s[i];
  }
  sort(d.begin(), d.end());
  int Q;
  cin >> Q;
  vii q(Q);
  for (int i = 0; i < Q; ++i) {
    ll l, r;
    cin >> l >> r;
    q[i] = pii(r - l, i);
  }
  sort(q.begin(), q.end()); 
  int it = 0, c = s.size();
  ll pr = -1, sum = 0;
  vl res(Q);
  for (auto p : q) {
    while (it < d.size() && d[it] <= p.first) {
      sum += c * (d[it] - 1 - pr);
      --c;
      pr = d[it] - 1;
      ++it;
    }
    sum += c * (p.first - pr);
    pr = p.first;
    res[p.second] = sum;
  }
  for (int i = 0; i < Q; ++i) {
    cout << res[i] << ' ';
  }
  cout << endl;
  return 0;
}