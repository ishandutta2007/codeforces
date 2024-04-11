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

int n, m;
vi tmpr, tmpc;
vvi tmpres, mares;
//const ll P = 131;

void out(vi v) {
  for (int x : v) cerr << x << ' ';
  cerr << endl;
}

void out(vvi v) {
  for (auto x : v) out(x);
  cerr << endl;
}

vii tmpv;
vector<array<int, 3>> v1;
vector<vvi> orda(2);
vector<vvi> ordb(2);

void f(const vvi& a, vvi& r0, vvi& c0, vector<vvi>& res, const vector<vvi>& ord) {
  vvi w(2, vi(max(n, m)));
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (a[i][j] && !w[0][i] && !w[1][j]) {
    vi r, c;
    vii q(1, pii(0, i));
    w[0][i] = 1;
    int mi = 1e9;
    while (!q.empty()) {
      int i = q.back().second, t = q.back().first;
      q.pop_back();
      tmpv.clear();
      if (t == 0) {
        for (int j = 0; j < m; ++j) if (a[i][j]) tmpv.emplace_back(i, j);
        r.push_back(i);
      }
      if (t == 1) {
        for (int j = 0; j < n; ++j) if (a[j][i]) tmpv.emplace_back(j, i);
        c.push_back(i);
      }
      for (pii p : tmpv) {
        mi = min(mi, a[p.first][p.second]);
        if (!w[0][p.first]) {
          w[0][p.first] = 1;
          q.emplace_back(0, p.first);
        }
        if (!w[1][p.second]) {
          w[1][p.second] = 1;
          q.emplace_back(1, p.second);
        }
      }
    }
    vvi curres(r.size(), vi(c.size(), 1e9));
    vi curr, curc;
    int TIME = 2;
    for (int i : r) for (int j : c) if (a[i][j] == mi) {
      ++TIME;
      w[0][i] = TIME;
      q.assign(1, pii(0, i));
      tmpr.clear();
      tmpc.clear();
      while (!q.empty()) {
        int i = q.back().second, t = q.back().first;
        q.pop_back();
        v1.clear();
        if (t == 0) {
          for (int j : ord[t][i]) {
            v1.push_back({a[i][j], i, j});
//            assert(a[i][j]);
          }
          tmpr.push_back(i);
        }
        if (t == 1) {
          for (int j : ord[t][i]) {
            v1.push_back({a[j][i], j, i});
//            assert(a[j][i]);
          }
          tmpc.push_back(i);
        }
        for (auto x : v1) {
          pii p(x[1], x[2]);
          mi = min(mi, a[p.first][p.second]);
          if (w[0][p.first] < TIME) {
            w[0][p.first] = TIME;
            q.emplace_back(0, p.first);
          }
          if (w[1][p.second] < TIME) {
            w[1][p.second] = TIME;
            q.emplace_back(1, p.second);
          }
        }
      }
      assert(tmpr.size() == r.size() && tmpc.size() == c.size());
      tmpres.assign(r.size(), vi(c.size()));
      for (int i = 0; i < r.size(); ++i) for (int j = 0; j < c.size(); ++j) tmpres[i][j] = a[tmpr[i]][tmpc[j]];
      if (curres > tmpres) {
        curres = tmpres;
        curr = tmpr;
        curc = tmpc;
      }
    }
    res.push_back(curres);
    r0.push_back(curr);
    c0.push_back(curc);
  }
}

void g(vi v, int t, vector<array<int, 3>>& res) {
  vi w(v.size(), 0);
  for (int i = 0; i < v.size(); ++i) if (v[i] != i && !w[i]) {
    w[i] = 1;
    int cur = v[i];
    while (!w[cur]) {
      w[cur] = 1;
      res.push_back({t, i, cur});
      cur = v[cur];
    }
  }
}

void mp(vi& a, const vi& b) {
  int it = 0;
  for (int i = 0; i < a.size(); ++i) if (a[i] == -1) {
    while (it < b.size() && b[it]) ++it;
    a[i] = it++;
  }
}

const int DEBUG = 0;

void calcord(const vvi& a, vector<vvi>& ord) {
  ord[0].assign(n, vi());
  for (int i = 0; i < n; ++i) {
    vii ts;
    for (int j = 0; j < m; ++j) if (a[i][j]) ts.emplace_back(a[i][j], j);
    sort(ts.begin(), ts.end());
    for (pii p : ts) {
      ord[0][i].push_back(p.second);
      assert(a[i][p.second]);
    }
  }
  ord[1].assign(m, vi());
  for (int i = 0; i < m; ++i) {
    vii ts;
    for (int j = 0; j < n; ++j) if (a[j][i]) ts.emplace_back(a[j][i], j);
    sort(ts.begin(), ts.end());
    for (pii p : ts) ord[1][i].push_back(p.second);
  }
}

void solve(vvi a, vvi b) {
  calcord(a, orda);
  calcord(b, ordb);
  vector<vvi> resa, resb;
  vvi ra, rb, ca, cb;
  f(a, ra, ca, resa, orda);
  f(b, rb, cb, resb, ordb);
  vi was(resb.size());
  vi pr(n, -1), pc(m, -1);
  vi prw(n), pcw(m);
  bool fail = resa != resb;
//  cerr << resa.size() << endl;
  for (int i = 0; !fail && i < resa.size(); ++i) {
    bool ok = 0;
    for (int j = 0; j < resb.size(); ++j) if (!was[j] && resa[i] == resb[j]) {
      was[j] = 1;
      ok = 1;
      for (int t = 0; t < ra[i].size(); ++t) {
        pr[ra[i][t]] = rb[j][t];
        prw[rb[j][t]] = 1;
      }
      for (int t = 0; t < ca[i].size(); ++t) {
        pc[ca[i][t]] = cb[j][t];
        pcw[cb[j][t]] = 1;
      }
    }
    if (!ok) fail = 1;
  }
  if (fail) {
    cout << -1 << '\n';
    return;
  }
  mp(pr, prw);
  mp(pc, pcw);
  auto a0 = a;
  vector<array<int, 3>> res;
  g(pr, 1, res);
  g(pc, 2, res);
  cout << res.size() << '\n';
  for (auto x : res) cout << x[0] << ' ' << x[1]+1 << ' ' << x[2]+1 << '\n';
  for (auto x : res) {
    if (x[0] == 1) a[x[1]].swap(a[x[2]]);
    else for (int i = 0; i < n; ++i) swap(a[i][x[1]], a[i][x[2]]);
  }
  if (DEBUG && a != b) {
    out(a0);
    out(a);
    out(b);
    out(pr);
    out(pc);
  }
  assert(a == b);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;//DEBUG ? 100 : 1;
//  cin >> T;
  for (int test = 1; test <= T; ++test) {
    if (!DEBUG) cin >> n >> m;
    else n = m = 447;
    vvi a(n, vi(m));
    vvi b(n, vi(m));
    if (DEBUG) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) if (rand() % 10 == 0) a[i][j] = i * m + j;
        a[i][i] = 1;
      }
      b = a;
      for (int t = 0; t < n; ++t) {
        int i = rand() % n, j = rand() % n;
        b[i].swap(b[j]);
      }
      for (int t = 0; t < m; ++t) {
        int i = rand() % m, j = rand() % m;
        for (int x = 0; x < n; ++x) swap(b[x][i], b[x][j]);
      }
    } else {
      for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
      for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> b[i][j];
    }
    solve(a, b);
  }
  return 0;
}