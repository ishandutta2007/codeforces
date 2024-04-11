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

vii res;
vi p, pos;
int n;

void f(int i, int j) {
  if (i == j) return;
  assert(abs(i - j) >= n / 2);
  res.emplace_back(i, j);
  pos[p[i]] = j;
  pos[p[j]] = i;
  swap(p[i], p[j]);
}

void g(int i, int j) {
  if (i > j) swap(i, j);
  if (j - i >= n / 2) {
    f(i, j);
    return;
  }
  if (j < n / 2 || i >= n / 2) {
    int k = j < n / 2 ? n - 1 : 0;
    f(i, k);
    f(j, k);
    f(i, k);
    return;
  }
  f(i, n-1);
  f(j, 0);
  f(0, n-1);
  f(i, n-1);
  f(j, 0);
  return;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  cin >> n;
  p.resize(n), pos.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
    pos[p[i]] = i;
  }
  for (int i = 0; i < n; ++i) if (p[i] != i) {
    g(pos[i], i);
  }
  for (int i = 0; i < n; ++i) assert(p[i] == i);
  cout << res.size() << endl;
  for (pii p : res) {
    cout << p.first + 1 << ' ' << p.second + 1 << '\n';
  }
  return 0;
}