#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

vl p, in, out, dw, sum;
int pr[100005][17];
vvi g;

int getp(int v) {
  if (p[v] == v) return v;
  return p[v] = getp(p[v]);
}

bool join(int a, int b) {
  a = getp(a);
  b = getp(b);
  if (a == b) return 0;
  p[a] = b;
  return 1;
}

int TIME = 0;

void dfs(int v, int p) {
  if (p != -1) pr[v][0] = p;
  in[v] = ++TIME;
  for (int nv : g[v]) if (nv != p) {
    dfs(nv, v);
  }
  out[v] = ++TIME;
}

void dfs1(int v, int p) {
//  cerr << p << ' ' << v << endl;
  for (int nv : g[v]) if (nv != p) {
    dw[nv] += dw[v];
    dfs1(nv, v);
  }
}

int pr1(int v, int p) {
  for (int h = 16; h >= 0; --h) {
    int nv = pr[v][h];
    if (in[nv] > in[p]) v = nv;
  }
  return v;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
//  srand(83924789321759841564785628471658723648713687326118746214875612);
  int T = 1;
//  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n, m;
    cin >> n >> m;
    g.assign(n, vi());
    p.resize(n);
    in.assign(n, 0);
    out.assign(n, 0);
    dw.assign(n, 0);
    sum.assign(n, 0);
    for (int i = 0; i < n; ++i) p[i] = i;
    vector<array<int, 3>> e(m);
    for (int i = 0; i < m; ++i) {
      cin >> e[i][1] >> e[i][2];
      e[i][0] = i;
      --e[i][1];
      --e[i][2];
    }
    sort(e.begin(), e.end());
    vii bad;
    for (auto x : e) {
      if (join(x[1], x[2])) {
        g[x[1]].push_back(x[2]);
        g[x[2]].push_back(x[1]);
      } else {
        bad.emplace_back(x[1], x[2]);
      }
    }
    dfs(0, -1);
    for (int h = 1; h < 17; ++h) for (int i = 0; i < n; ++i) pr[i][h] = pr[pr[i][h-1]][h - 1];
    for (pii& p : bad) {
      if (in[p.first] > in[p.second]) swap(p.first, p.second);
//      cerr << p.first + 1 << ' ' << p.second + 1 << endl;
      if (out[p.first] > out[p.second]) {
//        cerr << p.first + 1 << ' ' << p.second + 1 << endl;
        dw[0]++;
        dw[pr1(p.second, p.first)]--;
        dw[p.second]++;
      } else {
        dw[p.first]++;
        dw[p.second]++;   
      }
    }
    dfs1(0, -1);
    for (int i = 0; i < n; ++i) {
//      cerr << i+1 << ' ' << dw[i] << endl;
      if (dw[i] == m - n + 1) cout << "1";
      else cout << "0";
    }
    cout << '\n';
  }
  return 0;
}