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

int l;

int g(int i, const vl& a) {
  return (a[i] <= l && a[i+1] > l) || (a[i] > l && a[i+1] <= l);
}

int f(int i, const vl& a) {
  return g(i - 1, a) + g(i, a);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m >> l;
  vl a(n + 2);
  int c = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i + 1 < a.size(); ++i) {
    c += g(i, a);
  }
  for (int i = 0; i < m; ++i) {
    int t;
    cin >> t;
    if (t == 0) {
      cout << c / 2 << endl;
    } else {
      ll p, d;
      cin >> p >> d;
      c -= f(p, a);
      a[p] += d;
      c += f(p, a);
    }
  }
  return 0;
}