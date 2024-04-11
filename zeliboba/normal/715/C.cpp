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
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vvi gr,grw;
vi rm, sz;
int c0, mod;
ll res = 0;
map<int, int> rems;
const int N = 100005;
ll pw[N];
ll invpw[N];

ll inv (ll a, ll b) {
  ll b1 = b;
  ll xa = 1, xb = 0, ya = 0, yb = 1;
  while (a % b != 0) {
    ll t = a / b;
    a -= t * b;
    xa -= t * ya;
    xb -= t * yb;
    swap(a, b);
    swap(xa, ya);
    swap(xb, yb);
  }
  return (ya%b1 + b1) % b1;
}

void dfs1(int v, int p, int mul, int h, ll s) {
  rems[s] += mul;
  if (v != p && s == 0) res += mul; 
//  cerr << v << ' ' << s << ' ' << pw[h] << endl;
  for (int i = 0; i < gr[v].size(); ++i) {
    int nv = gr[v][i];
    if (nv == p || rm[nv]) continue;
    dfs1(nv, v, mul, h + 1, (s + grw[v][i]*pw[h]) % mod);
  }
}

void dfs2(int v, int p, int h, ll s) {
  ll r = (mod - s * invpw[h] % mod) % mod;
  res += rems[r];
//  cerr << v << ' ' << s << ' ' << invpw[h] << ' ' << r << endl;
  for (int i = 0; i < gr[v].size(); ++i) {
    int nv = gr[v][i];
    if (nv == p || rm[nv]) continue;
    dfs2(nv, v, h + 1, (s*10 + grw[v][i]) % mod);
  }
}

void build(int c) {
//  cerr << c << ' ' << res << endl;
  rems.clear();
  dfs1(c, c, 1, 0, 0);
  for (int i = 0; i < gr[c].size(); ++i) {
    int nv = gr[c][i];
    if (rm[nv]) continue;
    dfs1(nv, c, -1, 1, grw[c][i]%mod);
    dfs2(nv, c, 1, grw[c][i]%mod);
    dfs1(nv, c, 1, 1, grw[c][i]%mod);
  }
}

void dfs_sz(int v, int p) {
  sz[v] = 1;
  for (int i = 0; i < gr[v].size(); ++i) {
    int nv = gr[v][i];
    if (nv == p || rm[nv]) continue;
    dfs_sz(nv, v);
    sz[v] += sz[nv];
  }
}

int find_center(int v) {
  dfs_sz(v, -1);
  int tot = sz[v], p = -1;
  while (true) {
    bool ok = 1;
    for (int i = 0; i < gr[v].size(); ++i) {
      int nv = gr[v][i];
      if (rm[nv] || nv == p) continue;
      if (sz[nv] > tot/2) {
        ok = 0;
        p = v;
        v = nv;
      }
    }
    if (ok) return v;
  }
}

void push_centroid(int v) {
  //cerr << v+1 << endl;
  build(v);
  rm[v] = 1;
  for (int i = 0; i < gr[v].size(); ++i) {
    int nv = gr[v][i];
    if (rm[nv]) {
      continue;
    }
    int c = find_center(nv);
    push_centroid(c);
  }
}

void centroid() {
  c0 = find_center(0);
  push_centroid(c0);
}

int main() {
  int n;
  cin >> n >> mod;
  pw[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw[i] = pw[i-1]*10 % mod;
    invpw[i] = inv(pw[i], mod);
  }
  gr.resize(n);
  grw.resize(n);
  rm.assign(n, 0);
  sz.assign(n, 0);
  for (int i = 0; i < n-1; ++i) {
    int a, b, c;
    scanf("%d%d%d",&a,&b,&c);
    gr[a].push_back(b);
    gr[b].push_back(a);
    grw[a].push_back(c);
    grw[b].push_back(c);
  }
  centroid();
  cout << res << endl;
  return 0;
}