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

int N;
vi fen;
void add(int i, int val) {
  for (; i < fen.size(); i |= i + 1)
    fen[i] = max(fen[i], val);
}

int getmax(int i) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    res = max(res, fen[i]);
  return res;
}

vi g2 (vector<int> a, bool strict = true)
{
  vi res;
  int n = a.size();
  if (n == 0) 
    return res;
  vector<pair<int, int> > L(n);
  vi P(n, -1);
  int c = 1;
  L[0] = make_pair(a[0], 0);
  for (int i = 1; i < n; ++i) {
    pair<int, int> cur = make_pair(a[i], i);
    int ps = upper_bound(L.begin(), L.begin() + c, cur) - L.begin();
    if (strict && (ps > 0 && L[ps - 1].first == a[i])) 
      continue;
    if (ps > 0) 
      P[i] = L[ps - 1].second;
    L[ps] = cur;
    if (ps == c) 
      ++c;
  }
  for (int l = L[c - 1].second; l >= 0; l = P[l]) 
    res.push_back(l);
  reverse(res.begin(), res.end());
  return res;
}

vi g (const vi & a, const vi & LL, const vi & R, vii & ts, int len, bool strict = true)
{
  vi res;
  int n = a.size();
  if (n == 0) 
    return res;
  vector<pair<int, int> > L(n);
  vector<vii> q(n);
  vi P(n, -1);
  int c = 1;
  L[0] = make_pair(a[0], 0);
  q[0].push_back(L[0]);
  for (int i = 1; i < n; ++i) {
    pair<int, int> cur = make_pair(a[i], i);
    int ps = upper_bound(L.begin(), L.begin() + c, cur) - L.begin();
    if (strict && (ps > 0 && L[ps - 1].first == a[i])) {
      --ps;
    }
    if (ps > 0) 
      P[i] = L[ps - 1].second;
    if (q[ps].empty() || q[ps].back().first > a[i]) {
      q[ps].push_back(cur);
      L[ps] = cur;
    }
    assert(ps == LL[i] - 1);
    if (ps == c) 
      ++c;
    if (ps) {
      int l = -1, r = q[ps-1].size() - 1;
      while (r - l > 1) {
        int t = (l + r) / 2;
        if (q[ps-1][t].first < a[i]) r = t;
        else l = t;
      }
      int lp = q[ps-1][r].second;
      assert(lp >= 0 && lp < i && a[lp] < a[i] && LL[lp] == ps);
      if (R[i] + ps == len && lp + 1 <= i - 1) {
        ts.push_back(pii(lp + 1, i - 1));
      }
    } else if (R[i] + ps == len) {
      ts.push_back(pii(0, i-1));
    }
    if (LL[i] == len) {
      ts.push_back(pii(i+1, n-1));
    }
  }
  for (int l = L[c - 1].second; l >= 0; l = P[l]) 
    res.push_back(l);
  reverse(res.begin(), res.end());
  return res;
}

vi f(vi h, vi L, vi R, int len) {
  int n = h.size();
  if (n == 1) {
    return vi(n, 0);
  }
  vii ts;
  vi p = g(h, L, R, ts, len);
  assert(p.size() == len);
  vi skip(n, p.size());
  for (int i = 0; i < p.size(); ++i) {
    skip[p[i]]--;
    assert(len == L[p[i]] + R[p[i]] - 1);
  }
  sort(ts.begin(), ts.end());
  if (!ts.empty()) {
    vii np(1, ts[0]);
    for (int i = 1; i < ts.size(); ++i) {
      if (ts[i].first <= np.back().second) np.back().second = max(np.back().second, ts[i].second);
      else np.push_back(ts[i]);
    }
    for (auto x : np) {
      for (int i = x.first; i <= x.second; ++i) if (skip[i] < p.size()) ++skip[i];
    }
  }
/*  reverse(h.begin(), h.end());
  for (int i = 0; i < h.size(); ++i) h[i] = N - h[i];
  vi p2 = g2(h);
  for (int i = 0; i < p.size(); ++i) {
    if (binary_search(p2.begin(), p2.end(), n - 1 - p[i])) {
      --skip[p[i]];
    }
  }*/
  return skip;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vi h(n);
  vi ts(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &h[i]);
    ts[i] = h[i];
  }
  vii q(m);
  vvi v(n);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &q[i].first, &q[i].second);
    --q[i].first;
    v[q[i].first].push_back(i);
    ts.push_back(q[i].second);
  }
  sort(ts.begin(), ts.end());
  ts.resize(unique(ts.begin(), ts.end()) - ts.begin());
  for (int i = 0; i < h.size(); ++i) {
    h[i] = lower_bound(ts.begin(), ts.end(), h[i]) - ts.begin();
  }
  for (int i = 0; i < q.size(); ++i) {
    q[i].second = lower_bound(ts.begin(), ts.end(), q[i].second) - ts.begin();
  }
  N = ts.size() - 1;
  vi l(m), r(m);
  fen.assign(N+1, 0);
  vi ma(n, 1);
  for (int i = 1; i < n; ++i) {
    add(h[i-1], ma[i-1]);
    ma[i] = 1 + getmax(h[i] - 1);
    for (auto x : v[i]) {
      l[x] = getmax(q[x].second - 1);
    }
  }
  vi L = ma;
  fen.assign(N+1, 0);
  ma.assign(n, 1);
  for (int i = n-2; i >= 0; --i) {
    add(N - h[i+1], ma[i+1]);
    ma[i] = 1 + getmax((N - h[i]) - 1);
    for (auto x : v[i]) {
      r[x] = getmax((N - q[x].second) - 1);
    }
  }
  vi R = ma;
  int len = 1;
  for (int i = 0; i < n; ++i) len = max(len, L[i]+R[i]-1);
  vi skip = f(h, L, R, len);
  for (int i = 0; i < q.size(); ++i) {
    printf("%d\n", max(l[i] + r[i] + 1, skip[q[i].first]));
  }
  return 0;
}