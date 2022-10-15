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

const int B = 22;
const int N = 1 << B;
vi p(N), r(N), push(N);

int getp(int v) {
  if (p[v] == v) return v;
  return p[v] = getp(p[v]);
}

void join(int a, int b) {
  a = getp(a);
  b = getp(b);
  if (a == b) return;
  if (r[a] > r[b]) swap(a, b);
  p[a] = b;
  if (r[a] == r[b]) ++r[b];
}

void conv(vi & x) {
  for (int b = 0; b < B; ++b) {
    for (int i = 0; i < N; ++i) if (i & (1 << b)) {
      x[i] += x[i ^ (1 << b)];
    }
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vi a(m);
  for (int i = 0; i < p.size(); ++i) p[i] = i;
  vi x(N);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &a[i]);
    x[a[i]] = 1;
  }
  conv(x);
  for (int i = 0; i < m; ++i) {
    int opp = (N-1) ^ a[i];
//    cerr << a[i] << ' ' << opp << ' ' << x[opp] << endl;
    if (x[opp]) {
      join(a[i], opp);
      push[opp] = 1;
    }
  }
  for (int i = N-1; i >= 0; --i) if (push[i]) {
    for (int j = 0; j < B; ++j) if (i & (1 << j)) {
      int nx = i ^ (1 << j);
      if (!x[nx]) continue;
      push[nx] = 1;
      join(i, nx);
    }
  }
  vi all;
  for (int i = 0; i < a.size(); ++i) all.push_back(getp(a[i]));
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  cout << all.size() << endl;
  return 0;
}