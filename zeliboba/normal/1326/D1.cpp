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
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

string f(string s) {
  int n = s.size();
  vector<int> d1 (n);
  int l=0, r=-1;
  for (int i=0; i<n; ++i) {
    int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
    while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
    d1[i] = k;
    if (i+k-1 > r)
      l = i-k+1,  r = i+k-1;
  }
  vector<int> d2 (n);
  l=0, r=-1;
  for (int i=0; i<n; ++i) {
    int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
    while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
    d2[i] = k;
    if (i+k-1 > r)
      l = i-k,  r = i+k-1;
  }
  vi ma(n, 1);
  for (int i = 0; i < n; ++i) {
    if (i < n / 2) ma[i - d1[i] + 1] = max(ma[i - d1[i] + 1], 2 * d1[i] - 1);
    if (i < (n + 1) / 2) ma[i - d2[i]] = max(ma[i - d2[i]], 2 * d2[i]);
  }
  for (int i = 0; i + 1 < n; ++i) {
    ma[i + 1] = max(ma[i + 1], ma[i] - 2);
  }
  pii res(ma[0], 0);
  for (int i = 0; i < n; ++i) {
    if (s[i] != s[n - i - 1]) break;
    if (2 * (i + 1) >= n) {
      res = pii(n, 0);
      break;
    }
    pii cand(i + 1 + ma[i + 1], i + 1);
    if (cand.first + cand.second > res.first + res.second) res = cand;
//    cerr << i + 1 << ' ' << ma[i + 1] << ' ' << res.first + res.second << endl;
  }
  string t = "";
//  cerr << res.first << ' ' << res.second << endl;
  for (int i = 0; i < res.first; ++i) t += s[i];
  for (int i = 0; i < res.second; ++i) t += s[n - res.second + i];
//  cerr << t << endl;
  return t;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int tt = 0; tt < T; ++tt) {
    string s;
    cin >> s;
    string s1 = f(s);
    reverse(s.begin(), s.end());
    string s2 = f(s);
    if (s2.size() > s1.size()) s1 = s2;
    cout << s1 << '\n';
  }
  return 0;
}