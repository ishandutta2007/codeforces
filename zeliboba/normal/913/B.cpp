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

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vvi g(n);
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    g[p-1].push_back(i);
  }
  bool ok = 1;
  for (int i = 0; i < n; ++i) if (!g[i].empty()) {
    int c = 0;
    for (int v : g[i]) c += g[v].empty();
    if (c < 3) ok = 0;
  }
  if (ok) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}