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

int n;
bool ask(pii a, pii b) {
  cout << "? " << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << endl;
  assert(abs(a.first - b.first) + abs(a.second - b.second) >= n - 1);
  fflush(stdout);
  string s;
  cin >> s;
  return s == "YES";
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  cin >> n;
  string pref = "", suf = "";
  pii b(1, 1), e(n, n);
  pii cur = b;
  for (int i = 0; i < n - 1; ++i) {
    pii cand = cur;
    ++cand.second;
    if (!ask(cand, e)) {
      ++cur.first;
      pref += 'D';
    } else {
      cur = cand;
      pref += 'R';
    }
  }
  cur = e;
  for (int i = 0; i < n - 1; ++i) {
    pii cand = cur;
    --cand.first;
    if (!ask(b, cand)) {
      --cur.second;
      suf += 'R';
    } else {
      cur = cand;
      suf += 'D';
    }
  }
  reverse(suf.begin(), suf.end());
  cout << "! " << pref << suf << endl;
  return 0;
}