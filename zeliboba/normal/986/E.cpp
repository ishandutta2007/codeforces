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
const int mod = 1000000007;

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

ll inv(ll x) {
  return mpow(x, mod - 2);
}

vvi g;
const ll MAX = 10000000;
vi erat(MAX+1);
vi a;

vii fact(int n) {
  vii v;
  while (n > 1) {
    int p = erat[n];
    v.emplace_back(p, p);
    n /= p;
    while (n % p == 0) {
      n /= p;
      v.back().second *= p;
    }
  }
  return v;
}

const int L = 17;
int lc[100005][L];
vi in, out;
int TT = 0;

void dfs(int v, int pr) {
    lc[v][0] = pr;
    in[v] = ++TT;
    for (int i = 0; i < g[v].size(); ++i) if (g[v][i] != pr) {
        dfs(g[v][i], v);
    }
    out[v] = ++TT;
}

int lca(int u, int v) {
    if (in[u] > in[v]) swap(u, v);
    if (out[u] >= out[v]) return u;
    for (int h = L-1; h >= 0; --h) {
        if (out[lc[u][h]] < out[v]) {
            u = lc[u][h];
        }
    }
    return lc[u][0];
}

vector<vii> qv;
vl ans;
ll tmp[MAX+1];
ll invi[MAX+1];

void dfs1(int v, int pr) {
  for (auto it : fact(a[v])) {
    int p = it.first;
    ll pw = p;
    while (pw <= MAX) {
      tmp[pw] = tmp[pw] * min(pw, (ll)it.second) % mod;
      pw *= p;
    }
  }
  for (auto it : qv[v]) {
    for (auto p : fact(it.first)) {
      ans[it.second] = ans[it.second] * tmp[p.second] % mod;
    }
  }
  for (int nv : g[v]) if (nv != pr) {
    dfs1(nv, v);
  }
  for (auto it : fact(a[v])) {
    int p = it.first;
    ll pw = p;
    while (pw <= MAX) {
      tmp[pw] = tmp[pw] * invi[min(pw, (ll)it.second)] % mod;
      pw *= p;
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int i = 1; i < erat.size(); ++i) {
    erat[i] = i;
    tmp[i] = 1;
  }
  invi[1] = 1;
  for (int i = 2; i <= MAX; ++i) {
    invi[i] = (mod - (mod/i) * invi[mod%i] % mod) % mod;
    if (i < 100000) assert(invi[i] == inv(i));
  }
  for (int i = 2; i * i < erat.size(); ++i) if (erat[i] == i)
    for (int j = i * i; j < erat.size(); j += i) erat[j] = i;
  int n;
  cin >> n;
  g.resize(n);
  qv.resize(n);
  in.resize(n);
  out.resize(n);
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, 0);
  for (int t = 1; t < L; ++t) for (int i = 0; i < n; ++i) lc[i][t] = lc[lc[i][t-1]][t-1];
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int Q;
  cin >> Q;
  vii q;
  vector<vii> td(Q);
  vl res(Q);
  for (int i = 0; i < Q; ++i) {
    int u, v, x;
    cin >> u >> v >> x;
    --u; --v;
    int c = lca(u, v);
//    cerr << u+1 << ' ' << v+1 << ' ' << c+1 << endl;
    td[i].emplace_back(q.size(), 1);
    q.emplace_back(u, x);
    td[i].emplace_back(q.size(), 1);
    q.emplace_back(v, x);
    td[i].emplace_back(q.size(), -2);
    q.emplace_back(c, x);
    res[i] = __gcd(a[c], x);
  }
  for (int i = 0; i < q.size(); ++i) {
    qv[q[i].first].emplace_back(q[i].second, i);
  }
  ans.assign(q.size(), 1);
  dfs1(0, 0);
  for (int i = 0; i < Q; ++i) {
    for (auto it : td[i]) {
      if (it.second == 1) res[i] = res[i] * ans[it.first] % mod;
      else res[i] = res[i] * inv(mpow(ans[it.first], 2)) % mod;
    }
    cout << res[i] << endl;
  }
  return 0;
}