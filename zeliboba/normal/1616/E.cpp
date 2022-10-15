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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

vi fen;

void add(int i) {
  for (; i < fen.size(); i |= i + 1) ++fen[i];
}

int getsum(int i) {
  int s = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    s += fen[i];
  return s;
}

int f(int i) {
  return i + getsum(fen.size() - 1) - getsum(i);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int tt = 0; tt < T; ++tt) {
    int n;
    string s, t;
    cin >> n >> s >> t;
    fen.assign(n, 0);
    vvi v(26);
    for (int i = 0; i < n; ++i) v[s[i] - 'a'].push_back(i);
    string s1 = s;
    sort(s1.begin(), s1.end());
    if (s1 >= t) {
      cout << -1 << '\n';
      continue;
    }
    vi it(26);
    ll res = 1e18, sum = 0;
    for (int i = 0; i < n; ++i) {
      int x = t[i] - 'a';
      for (int j = 0; j < x; ++j) if (it[j] < v[j].size()) res = min(res, sum + f(v[j][it[j]]) - i);
      if (it[x] < v[x].size()) {
        sum += f(v[x][it[x]]) - i;
        add(v[x][it[x]]);
        ++it[x];
      } else break;
    }
    cout << res << endl;
  }
  return 0;
}