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

vvi gr;
vector<int> mt;
vector<char> used; 
bool try_kuhn (int v) {
  if (used[v])  return false;
  used[v] = true;
  for (size_t i=0; i<gr[v].size(); ++i) {
    int to = gr[v][i];
    if (mt[to] == -1 || try_kuhn (mt[to])) {
      mt[to] = v;
      mt[v] = to;
      return true;
    }
  }
  return false;
}

int stupid(int n, int m) {
  gr.assign(n * m, vi());
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    int v = i * m + j;
    for (int x = -3; x <= 3; ++x) for (int y = -3; y <= 3; ++y) if (abs(x) + abs(y) == 3) {
      int ni = i + x, nj = j + y;
      if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
        gr[v].push_back(m * ni + nj);
      }
    }
  }
  mt.assign (gr.size(), -1);
  int c = 0;
  for (int run = 1; run;) {
    run = 0;
    used.assign(gr.size(), false);
    for (int v=0; v<gr.size(); ++v) if ((v / m + v % m) % 2 == 0 && mt[v] == -1 && try_kuhn(v)) {
      ++c;
      run = 1;
    }
  }
  return c * 2;
}

int calc1(int m) {
  int add = 0;
  if (m % 6 == 4) add = 2;
  if (m % 6 == 5) add = 4;
  return m - m % 6 + add;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  vvi prec(50, vi(50));
  for (int i = 1; i < prec.size(); ++i) for (int j = i; j < prec[i].size(); ++j) {
    prec[i][j] = stupid(i, j);
    if (i >= 3) assert(prec[i][j] == i * j - (i * j) % 2);
    if (i == 1) assert(prec[i][j] == calc1(j));
  }
//  for (int n = 1; n <= 10; ++n) for (int m = n; m <= 10; ++m) cerr << n << ' ' << m << ' ' << n * m << ' ' << stupid(n, m) << endl;
  ll n, m;
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (n >= 3) {
    cout << n * m - (n * m) % 2 << endl;
  } else if (m < prec[n].size()) {
    cout << prec[n][m] << endl;
  } else if (n == 2) {
    cout << n * m << endl;
  } else {
    cout << calc1(m) << endl;
  }
  return 0;
}