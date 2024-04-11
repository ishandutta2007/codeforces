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
/*
const int N = 1 << 17;
ll a0[2][2*N], s[2][2*N];

void update (int t, int v, int tl, int tr, int l, int r, ll add) {
  if (l > r)
    return;
  if (l == tl && tr == r) {
    a0[t][v] = a0[t][v] + add;
    s[t][v] += add * (r - l + 1);
  } else {
    int tm = (tl + tr) / 2;
    int l1 = max(l,tm+1), r1 = min(r,tm);
    int l2 = max(l, tl), r2 = min(r, tr);
    if (l2 <= r2) {
      s[t][v] += add * (r2 - l2 + 1);
    }
    update (v*2, tl, tm, l, r1, add);
    update (v*2+1, tm+1, tr, l1, r, add);
  }
}

ll getsum (int t, int v, int tl, int tr, int l, int r, ll add) {
  if (l > r)
    return 0;
  if (l == tl && tr == r) {
    return (s[t][v] + add * (r - l + 1));
  } else {
    int tm = (tl + tr) / 2;
    add = add + a0[t][v];
    return getsum (v*2, tl, tm, l, min(r,tm), add) +
           getsum (v*2+1, tm+1, tr, max(l,tm+1), r, add);
  }
}*/
//update(1, 0, N-1, l, r, add);
//getsum(1, 0, N-1, l, r, 0);
ll mi[200005], ma[200005], s[200005];
int add[200005], a[200005], adeb[200005];
int M = 300, n;

void upd(int i) {
  for (int j = i; j < min(n, i + M); ++j) {
    a[j] += add[i];
  }
  add[i] = 0;
  mi[i] = a[i];
  ma[i] = 0;
  s[i] = a[i];
  for (int j = i + 1; j < min(n, i + M); ++j) {
    if (j % 2) {
      s[i] -= a[j];
      ma[i] = max(ma[i], s[i]);
    } else {
      s[i] += a[j];
      mi[i] = min(mi[i], s[i]);
    }
  }
//  for (int j = i; j < min(n, i + M); ++j) cerr << a[j] << ' ';
//  cerr << "upd " << i << ' ' << s[i] << endl;
}

const int DEBUG = 0;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
    adeb[i] = a[i];
//    s[i%2][N + i / 2] = a[i];
  }
//  for (int t = 0; t < 2; ++t) for (int i = N - 1; i >= 0; --i) s[t][i] = s[t][2*i]+s[t][2*i+1];
  int T;
  scanf("%d", &T);
  M = min(n, M);
  for (int i = 0; i < n; i += M) {
    upd(i);
  }
  for (int test = 1; test <= T; ++test) {
    int type, l, r, cadd;
    scanf("%d%d%d", &type, &l, &r);
    ++r;
    int l1 = (l + M - 1) / M * M;
    int r1 = r / M * M;
    if (type == 1) {
      scanf("%d", &cadd);
      if (DEBUG) for (int i = l; i < r; ++i) adeb[i] += cadd;
      for (int i = l; i < min(l1, r); ++i) a[i] += cadd;
      for (int i = max(l1, r1); i < r; ++i) a[i] += cadd;
      if (r1 < n) upd(r1);
      if (l1 > 0) upd(l1 - M);
      for (int x = l1; x < r1; x += M) add[x] += cadd;
//      update(1, 0, N-1, l, r, add);      
    } else {
      if (r1 < n) upd(r1);
      if (l1 > 0) upd(l1 - M);
//      for (int i = l; i < r; ++i) cerr << a[i] << ' ';
      ll sum = 0;
      int res = 1;
      for (int i = l; i < min(l1, r); ++i) {
        if ((i - l) % 2) {
          sum -= a[i];
          if (sum > 0) {res = 0; break;}
        } else {
          sum += a[i];
          if (sum < 0) {res = 0; break;}
        }
      }
//      cerr << l1 << ' ' << r1 << ' ' << sum << ' ' << res << endl;
      if (res) for (int i = l1; i < r1; i += M) {
//        cerr << i << ' ' << s[i] << endl;
        if (l % 2 == 0) {
          if (sum + mi[i] + add[i] < 0) {res = 0; break;}
          if (sum + ma[i] > 0) {res = 0; break;}
          sum += s[i];
        } else {
          if (sum - mi[i] - add[i] > 0) {res = 0; break;}
          if (sum - ma[i] < 0) {res = 0; break;}
          sum -= s[i];
        }
      }
//      cerr << l1 << ' ' << r1 << ' ' << sum << ' ' << res << endl;
      if (res) for (int i = max(l1, r1); i < r; ++i) {
        if ((i - l) % 2) {
          sum -= a[i];
          if (sum > 0) {res = 0; break;}
        } else {
          sum += a[i];
          if (sum < 0) {res = 0; break;}
        }
      }
//      cerr << l1 << ' ' << r1 << ' ' << sum << ' ' << res << endl;
      if (sum) res = 0;
      if (DEBUG) {
        int resdeb = 1;
        ll sum = 0;
        for (int i = l; i < r; ++i) {
          if ((i - l) % 2) {
            sum -= adeb[i];
            if (sum > 0) {resdeb = 0; break;}
          } else {
            sum += adeb[i];
            if (sum < 0) {resdeb = 0; break;}
          }
        }
        if (sum) resdeb = 0;
        printf("%d %d\n", res, resdeb);
        assert(res == resdeb);
      } else {
        printf("%d\n", res);
      }
    }
  }
  return 0;
}