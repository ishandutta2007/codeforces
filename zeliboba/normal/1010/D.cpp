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

int t[1000001];
int val[1000001];
int res[1000001];
vvi g;

int f(int a, int b, int t) {
  assert(t >= 0 && t < 3);
  if (t == 0) return a & b;
  if (t == 1) return a | b;
  return a ^ b;
}

void dfs0(int v) {
  for (int nv : g[v]) {
    dfs0(nv);
  }
  if (t[v] == 3) {
    val[v] = val[g[v][0]] ^ 1;
  } else if (t[v] < 3) {
    val[v] = f(val[g[v][0]], val[g[v][1]], t[v]);
  }
}

void dfs(int v) {
  if (t[v] == 3) {
    res[g[v][0]] = res[v];
  } else if (t[v] < 3) {
    array<int, 2> x = {val[g[v][0]], val[g[v][1]]};
    for (int i = 0; i < 2; ++i) {
      x[i] ^= 1;
      if (f(x[0], x[1], t[v]) == val[v]) {
        res[g[v][i]] = val[0];
      } else {
        res[g[v][i]] = res[v];
      }
      x[i] ^= 1;
    }
  }
  for (int nv : g[v]) {
    dfs(nv);
  }
}

int main() {
//  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  scanf("%d", &n);
  g.resize(n);
  for (int i = 0; i < n; ++i) {
    char s[5];
    int a, b;
    scanf("%s", s);
    if (s[0] == 'A') {
      t[i] = 0;
    } else if (s[0] == 'O') {
      t[i] = 1;
    } else if (s[0] == 'X') {
      t[i] = 2;
    } else if (s[0] == 'N') {
      t[i] = 3;
    } else {
      t[i] = 4;
    }
    if (t[i] < 3) {
      scanf("%d%d", &a, &b);
      --a; --b;
      g[i].push_back(a);
      g[i].push_back(b);
    } else if (t[i] == 3) {
      scanf("%d", &a);
      --a;
      g[i].push_back(a); 
    } else {
      scanf("%d", &val[i]);
    }
  }
  dfs0(0);
  res[0] = val[0] ^ 1;
  dfs(0);
  for (int i = 0; i < n; ++i) if (g[i].empty()) printf("%d", res[i]);
  printf("\n");
  return 0;
}