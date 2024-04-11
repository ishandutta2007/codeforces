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
#include <map>
#include <queue>
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

int d[1001][1001];

int main() {
  vii e;
  int n, m, Q;
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = 0; i < m; ++i) {
    int a,b;
    scanf("%d%d",&a,&b);
    --a; --b;
    e.push_back(pii(a, b));
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      d[i][j] = 1e9;
    }
  }
  vvi q(Q, vi(5));
  for (int qq = 0; qq < Q; ++qq) {
    int l,r,s,t;
    scanf("%d%d%d%d", &l,&r,&s,&t);
    --l; --r; --s; --t;
    q[qq][0] = l; q[qq][1] = r; q[qq][2] = s; q[qq][3] = t; q[qq][4] = qq;
  }
  sort(q.rbegin(), q.rend());
  int it = 0;
  vi res(q.size());
  for (int i = m - 1; i >= 0; --i) {
    int v[2] = {e[i].first, e[i].second};
    for (int t = 0; t < 2; ++t) {
      for (int j = 0; j < n; ++j) {
        d[v[t]][j] = min(d[v[t]][j], d[v[1-t]][j]);
      }
    }
    d[v[0]][v[1]] = d[v[1]][v[0]] = i;
    while (it < q.size() && q[it][0] == i) {
      if (d[q[it][2]][q[it][3]] <= q[it][1]) res[q[it][4]] = 1;
      ++it;
    }
  }
  for (int i = 0; i < res.size(); ++i) {
    if (res[i]) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}