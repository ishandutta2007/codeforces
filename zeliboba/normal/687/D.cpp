#include <cstdio>
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
#include <array>
using namespace std;
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

int p[1000], r[1000], col[1000];

int getp(int v) {
  if (p[v] == v) return v;
  int pr = getp(p[v]);
  col[v] ^= col[p[v]];
  p[v] = pr;
  return p[v];
}

void join(int a, int b, int d) {
  //careful!!!
  if (r[a] > r[b]) swap(a, b);
  else if (r[a] == r[b]) ++r[b];
  p[a] = b;
  col[a] = 1 ^ d;
}

struct E {
  int u,v,w,i;
};

bool cmp(const E & x, const E & y) {
  return x.w > y.w;
}

int main() {
  int n, m, Q;
  scanf("%d%d%d", &n, &m, &Q);
  vector<E> v(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &v[i].v, &v[i].u, &v[i].w);
    --v[i].v; --v[i].u;
    v[i].i = i + 1;
  }
  sort(v.begin(), v.end(), cmp);
  for (int test = 0; test < Q; ++test) {
    int L,R;
    scanf("%d%d", &L, &R);
    memset(r, 0, sizeof(r));
    memset(col, 0, sizeof(col));
    for (int i = 0; i < n; ++i) p[i] = i;
    int ans = -1;
    for (int i = 0; i < v.size(); ++i) if (v[i].i >= L && v[i].i <= R) {
      int a = getp(v[i].v), b = getp(v[i].u);
      if (a != b) {
        join(a, b, col[v[i].v] ^ col[v[i].u]);
      } else {
        if (col[v[i].v] == col[v[i].u]) {
          ans = v[i].w;
          break;
        }
      }
//      for (int i = 0; i < 3; ++i) cerr << p[i]; cerr << endl;
//     for (int i = 0; i < 3; ++i) cerr << col[i]; cerr << endl;
    }
    printf("%d\n", ans);
  }
  return 0;
}