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

int c = 0;

int ask(int i) {
  ++c;
  cout << "? " << i << endl;
  int res;
  cin >> res;
  return res;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    c = 0;
    vi p(n + 1);
    for (int i = 1; i <= n; ++i) if (p[i] == 0) {
      vi v;
      while (1) {
        int nx = ask(i);
        if (!v.empty() && nx == v[0]) break;
        v.push_back(nx);
      }
      for (int j = 0; j < v.size(); ++j) {
        p[v[j]] = v[(j + 1) % v.size()];  
      }
    }
    cout << "!";
    for (int i = 1; i <= n; ++i) cout << " " << p[i];
    cout << endl;
  }
  return 0;
}