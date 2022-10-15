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

int d[255][255][255];

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<array<int, 26>> nx(n + 2);
  for (int i = 0; i < (int)nx.size(); ++i) {
    nx[i].fill(n);
  }
  for (int i = n - 1; i >= 0; --i) {
    nx[i] = nx[i + 1];
    nx[i][s[i] - 'a'] = i;
  }
  vi l(3);
  vvi w(3);
  for (int test = 0; test < q; ++test) {
    string type, symb;
    int ind;
    cin >> type >> ind;
    --ind;
    if (type == "+") {
      cin >> symb;
      int x = symb[0] - 'a';
      w[ind].push_back(x);
      ++l[ind];
      vi pl(3);
      pl[ind] = l[ind];
      int i1 = (ind + 1) % 3, i2 = (ind + 2) % 3;
      for (pl[i1] = 0; pl[i1] <= l[i1]; ++pl[i1]) for (pl[i2] = 0; pl[i2] <= l[i2]; ++pl[i2]) {
        int x0 = pl[0], x1 = pl[1], x2 = pl[2];
        d[x0][x1][x2] = n + 1;
        if (x0) d[x0][x1][x2] = min(d[x0][x1][x2], nx[d[x0 - 1][x1][x2]][w[0][x0 - 1]] + 1);
        if (x1) d[x0][x1][x2] = min(d[x0][x1][x2], nx[d[x0][x1 - 1][x2]][w[1][x1 - 1]] + 1);
        if (x2) d[x0][x1][x2] = min(d[x0][x1][x2], nx[d[x0][x1][x2 - 1]][w[2][x2 - 1]] + 1);
      }
    } else {
      w[ind].pop_back();
      --l[ind];
    }
    if (d[l[0]][l[1]][l[2]] <= n) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}