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

int dfs(int v, int p, const vvi& g, const vi& my) {
  if (my[v]) return v;
  for (int nv : g[v]) if (nv != p) {
    int ret = dfs(nv, v, g, my);
    if (ret >= 0) return ret;
  }
  return -1;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    vvi g(n);
    for (int i = 0; i < n-1; ++i) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vi my(n);
    int k; cin >> k;
    for (int i = 0; i < k; ++i) {
      int v; cin >> v;
      my[v-1] = 1;
    }
    cin >> k;
    vi his(k);
    for (int i = 0; i < (int)his.size(); ++i) {
      cin >> his[i];
      --his[i];
    }
    sort(his.begin(), his.end());
    cout << "B " << his[0] + 1 << endl;
    fflush(stdout);
    int ind;
    cin >> ind; --ind;
    int my_closest = dfs(ind, -1, g, my);
    cout << "A " << my_closest + 1 << endl;
    fflush(stdout);
    cin >> ind; --ind;
    if (binary_search(his.begin(), his.end(), ind)) {
      cout << "C " << my_closest + 1 << endl;
    } else {
      cout << "C -1" << endl;
    }
    fflush(stdout);
  }
  return 0;
}