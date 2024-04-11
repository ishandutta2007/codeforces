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

void err(vi v) {
  for (int x : v) cerr << x << ' ';
  cerr << endl;
}

vi in, out;
int TIME = 1;

void dfs(int i, const vvi & g) {
  if (in[i]) return; 
  in[i] = TIME++;
  for (int nv : g[i]) dfs(nv, g);
  out[i] = TIME++;
}

const int DEBUG = 0;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1000;
  if (!DEBUG) cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n = 12;
    if (!DEBUG) cin >> n;
    vi a(n), b(n), c(n + 1);
    vii tsa(n), tsb(n);
    pii ma(0, 0);
    if (DEBUG) {
      int D = rand() % (n - 1) + 1;
      for (int i = 0; i < n; ++i) a[i] = i / D + 1;
//      random_shuffle(a.begin(), a.end());
      b = a;
      for (int i = 0; i < n - D - 1; ++i) {
        int x = rand() % n, y = rand() % n;
        swap(b[x], b[y]);
      }
      cerr << n << ' ' << D << endl;
      err(a);
      err(b);
    }
    for (int i = 0; i < n; ++i) {
      if (!DEBUG) cin >> a[i];
      c[a[i]]++;
      ma = max(ma, pii(c[a[i]], a[i]));
      tsa[i] = pii(a[i], i);
    }
    for (int i = 0; i < n; ++i) {
      if (!DEBUG) cin >> b[i];
      tsb[i] = pii(b[i], i);
    }
    sort(tsa.begin(), tsa.end());
    sort(tsb.begin(), tsb.end());
    vi p(n);
    for (int i = 0; i < n; ++i) {
      p[tsa[i].second] = tsb[i].second;
    }
    vi was(n);
    bool ok = 1;
    vvi g(n + 1);
    in.assign(n + 1, 0);
    out.assign(n + 1, 0);
    for (int s = 0; s < n; ++s) if (!was[s]) {
      vi v;
      int i = s;
      int it = -1;
      while (!was[i]) {
        v.push_back(a[i]);
        was[i] = 1;
        if (it == -1 && a[i] == ma.second) {
          it = v.size() - 1;
          assert(v[it] == ma.second);
        }
        i = p[i];
      }
      if (it == -1) {
        ok = 0; break;
      }
      assert(v[it] == ma.second);
      vi nv;
      for (int i = it; i < v.size(); ++i) nv.push_back(v[i]);
      for (int i = 0; i < it; ++i) nv.push_back(v[i]);
      assert(nv[0] == ma.second);
      for (int i = 1; i < nv.size(); ++i) {
        if (nv[i - 1] != ma.second && nv[i] != ma.second) g[nv[i - 1]].push_back(nv[i]);
      }
    }
    for (int i = 0; i <= n; ++i) dfs(i, g);
    for (int i = 0; i <= n; ++i) {
      for (int ni : g[i]) {
        if (out[i] <= out[ni]) ok = 0;
      }
    }
    if (DEBUG) {
      assert(!ok);
    }
    if (ok) cout << "AC\n";
    else cout << "WA\n";
  }
  return 0;
}