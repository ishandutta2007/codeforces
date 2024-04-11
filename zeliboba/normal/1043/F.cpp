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

const int N = 300000;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, d = 0;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    d = __gcd(d, a[i]);
  }
  if (d > 1) {
    cout << -1 << endl;
    return 0;
  }
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
  vvi div(N + 1);
  for (int i = 1; i < div.size(); ++i) {
    for (int j = i; j < div.size(); j += i) {
      div[j].push_back(i);
    }
  }
  vi c(N + 1);
  for (int x : a) {
    for (int y : div[x]) c[y]++;
  }
  vvi p(N + 1);
  for (int i = 2; i < div.size(); ++i) if (div[i].size() == 2) {
    for (int j = i; j < div.size(); j += i) p[j].push_back(i);
  }
  vi prec(N + 1);
  for (int i = 1; i <= N; ++i) {
    int k = p[i].size();
    for (int mask = 0; mask < (1 << k); ++mask) {
      int prod = 1, zn = 1;
      for (int j = 0; j < k; ++j) if (mask & (1 << j)) {
        prod *= p[i][j];
        zn *= -1;
      }
      prec[i] += zn * c[prod];
    }
    assert(prec[i] >= 0);
  }
  vi dist(N + 1, a.size());
  vi q = a;
  for (int x : a) dist[x] = 1;
  int it = 0;
  while (it < q.size()) {
    int v = q[it++];
    for (int d : div[v]) if (dist[d] > dist[v] + 1 && prec[v / d] > 0) {
      dist[d] = dist[v] + 1;
      q.push_back(d);
    }
  }
  cout << dist[1] << endl;
  return 0;
}