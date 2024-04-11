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
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

const int MAXN = 1 << 17;
const int INF = 1e9;
int ma[2*MAXN];
int sum[2*MAXN];

int get_max (int v, int tl, int tr, int l, int r) {
  if (l > r)
    return -INF;
  if (l == tl && r == tr)
    return ma[v];
  int tm = (tl + tr) / 2;
  return sum[v] + max(
      get_max (v*2, tl, tm, l, min(r,tm)),
      get_max (v*2+1, tm+1, tr, max(l,tm+1), r)
      );
}

int solve (int v, int tl, int tr, int l, int r, int add) {
  assert(add + get_max(v,tl,tr,l,r) > 0);
/*  if (l > r)
    return -INF;
  if (l == tl && r == tr && ma[v] <= 0) {
    return -INF;
  }*/
  if (l == r) {
    return l;
  }
  int tm = (tl + tr) / 2;
  add += sum[v];
  int v2 = add + get_max (v*2+1, tm+1, tr, max(l,tm+1), r);
  if (v2 > 0) {
    return solve(v*2+1, tm+1, tr, max(l,tm+1), r, add);
  }
  return solve(v*2, tl, tm, l, min(r,tm), add);
  //int v1 = sum[v] + get_max (v*2, tl, tm, l, min(r,tm));
}

void update (int v, int tl, int tr, int l, int r, int add) {
  if (l > r) return;
  if (l == tl && r == tr) {
    ma[v] += add;
    sum[v] += add;
  } else {
    int tm = (tl + tr) / 2;
    int l1 = max(l,tm+1), r1 = min(r,tm);
    update (v*2, tl, tm, l, r1, add);
    update (v*2+1, tm+1, tr, l1, r, add);

    ma[v] = sum[v] + max (ma[v*2], ma[v*2+1]);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  vi p(n), t(n), v(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &p[i], &t[i]);
    --p[i];
    if (t[i] == 1) {
      int x;
      scanf("%d", &x);
      v[p[i]] = x;
      update(1, 0, MAXN-1, 0, p[i], 1);
    } else {
      update(1, 0, MAXN-1, 0, p[i], -1);
    }
    if (get_max(1, 0, MAXN-1, 0, n-1) <= 0) {
      printf("-1\n");
    } else {
/*      int l = 0, r = n;
      while (r - l > 1) {
        int x = (l + r) / 2;
        int curma = get_max(1, 0, MAXN-1, x, n-1);
        if (curma > 0) {
          l = x;
        } else {
          r = x;
        }
      }*/
      int l = solve(1, 0, MAXN-1, 0, n-1, 0);
      printf("%d\n", v[l]);
    }
  }
  return 0;
}