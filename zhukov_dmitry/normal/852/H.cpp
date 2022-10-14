#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

struct pt {
  ll x, y;

  pt operator+(const pt &p) const { return pt{x + p.x, y + p.y}; }
  pt operator-(const pt &p) const { return pt{x - p.x, y - p.y}; }
  ll operator*(const pt &p) const { return x * p.x + y * p.y; }
  ll operator%(const pt &p) const { return x * p.y - y * p.x; }
  pt operator*(const ll &a) const { return pt{x * a, y * a}; }
  bool operator==(const pt &p) const { return x == p.x && y == p.y; }

  bool right() const { return x == 0 ? y > 0 : x > 0; }

  bool operator<(const pt &p) const {
    if (x != p.x)
      return x < p.x;
    if (y != p.y)
      return y < p.y;
    return false;
  }

  pt rot() { return pt{-y, x}; }
  pt rotCw(pt e) { return pt{e * *this, e % *this}; }
  ll abs2() const { return x * x + y * y; }
};

istream &operator>>(istream &in, pt &p) { return in >> p.x >> p.y; }
ostream &operator<<(ostream &out, const pt &p) { return out << p.x << ' ' << p.y; }

bool cmpAngle(const pt &a, const pt &b) {
  bool au = a.right(), bu = b.right();
  if (au != bu)
    return au;
  return a % b > 0;
}

const int maxn = 205;
const int maxk = 55;
pt p[maxn];
int cnt[maxn][maxn];
pt pivot;
mt19937 rr(random_device{}());
vector<int> ord[maxn];

int insideTriangle(pt a, pt b, pt c) {
  a = a - pivot;
  b = b - pivot;
  c = c - pivot;

  int sgn = 1;
  if (a % b < 0)
    swap(a, b), sgn = -1;
  if (a % c < 0 || c % b < 0)
    return 0;
  if ((c - a) % (b - a) > 0)
    return 0;
  return sgn;
}

int inside(int a, int b, int c) {
  int res = cnt[a][b] + cnt[b][c] + cnt[c][a];
  res -= insideTriangle(p[a], p[b], p[c]);
  res -= insideTriangle(p[b], p[c], p[a]);
  res -= insideTriangle(p[c], p[a], p[b]);
  return res;
}

ll S(int a, int b, int c) {
  return llabs((p[b] - p[a]) % (p[c] - p[a]));
}

ll d[maxn][maxn][maxk];

typedef pair<ll, ll> pll;
struct Queue {
  pll va[maxn], vd[maxn];
  int ca, cd;

  Queue() {
    ca = cd = 0;
  }

  void _add(ll val, pll* q, int &c) {
    ll mx = val;
    if (c)
      mx = max(mx, q[c - 1].second);
    q[c++] = {val, mx};
  }

  void add(ll val) {
    _add(val, va, ca);
  }

  void del() {
    if (cd == 0) {
      while (ca) {
        _add(va[ca - 1].first, vd, cd);
        --ca;
      }
    }
    assert(cd);
    --cd;
  }

  ll get() {
    ll res = 0;
    if (ca) {
      res = max(res, va[ca - 1].second);
    }
    if (cd) {
      res = max(res, vd[cd - 1].second);
    }
    return res;
  }

  void clear() {
    ca = cd = 0;
  }
};
Queue f[maxk];

struct Event {
  pt dir;
  int type, id;

  bool operator<(const Event& e) const {
    return cmpAngle(dir, e.dir);
  }
};

void uax(ll& a, ll b) {
  a = max(a, b);
}

struct Hull {
  vector<pt> h;
  int n;

  void build() {
    sort(all(h));
    h.erase(unique(all(h)), h.end());
    vector<pt> top, bot;
    for (auto p: h) {
      while (sz(bot) > 1 && (p - bot.back()) %
          (p - *next(bot.rbegin())) >= 0)
        bot.pop_back();
      bot.push_back(p);
      while (sz(top) > 1 && (p - top.back()) %
          (p - *next(top.rbegin())) <= 0)
        top.pop_back();
      top.push_back(p);
    }
    if (sz(top))
      top.pop_back();
    reverse(all(top));
    if (sz(top))
      top.pop_back();
    h = bot;
    h.insert(h.end(), all(top));
    n = sz(h);
  }
};

int n, k;

Hull hullmask(int mask) {
  Hull h;
  forn (i, n) {
    if ((1 << i) & mask)
      h.h.push_back(p[i]);
  }
  h.build();
  return h;
}

ll naive() {
  assert(n <= 20);
  ll best = 0;
  forn (mask, 1 << n) {
    int bits = __builtin_popcount(mask);
    if (bits != k)
      continue;
    Hull h = hullmask(mask);
    if (h.n != k)
      continue;
    bool ok = true;
    forn (i, n) {
      if ((1 << i) & mask)
        continue;
      Hull h1 = hullmask(mask ^ (1 << i));
      if (h1.h == h.h)
        ok = false;
    }
    if (ok) {
      ll s = 0;
      forn (i, k) {
        s += h.h[i] % h.h[(i + 1) % k];
      }
      best = max(best, s);
    }
  }
  return best;
}

int main() {
#ifdef LOCAL
  assert(freopen("h.in", "r", stdin));
#endif
  cin >> n >> k;
  forn (i, n)
    cin >> p[i];
  sort(p, p + n);

#ifdef LOCAL
  ll cbest = naive();
  cout << cbest / 2 << ".";
  if (cbest % 2)
    cout << "50\n";
  else
    cout << "00\n";
#endif

  while (true) {
    pivot.x = -(rr() % int(1e6));
    pivot.y = -(rr() % int(1e6));
    bool ok = true;
    forn (i, n)
      forn (j, i)
        if ((p[i] - pivot) % (p[j] - pivot) == 0)
          ok = false, i = j = n;
    if (ok)
      break;
  }

  forn (i, n)
    forn (j, n) {
      if (i == j)
        continue;
      forn (k, n) {
        if (k == i || k == j)
          continue;
        cnt[i][j] += insideTriangle(p[i], p[j], p[k]);
      }
    }

  forn (i, n) {
    forn (j, n)
      if (j != i)
        ord[i].push_back(j);
    sort(all(ord[i]), [&](int a, int b) {
          return cmpAngle(p[a] - p[i], p[b] - p[i]);
        });
  }

  ll best = 0;

  vector<Event> es, es0, es1;
  forn (s, n - k + 1) {
    memset(d, 0, sizeof(d));
    forn (i, n - 1)
      forn (j, i) {
        int v = ord[s][i];
        int u = ord[s][j];
        if (u <= s || v <= s)
          continue;
        if (inside(s, u, v) == 0) {
          d[u][v][3] = S(s, u, v);
          //cerr << "init " << s << ' ' << u << ' ' << v << ' ' << d[u][v][3] << '\n';
        }
      }
    forn (i, n - 1) {
      int u = ord[s][i];
      if (u <= s)
        continue;
      es.clear(), es0.clear(), es1.clear();
      forn (ck, k + 1)
        f[ck].clear();
      forn (j, n - 1) {
        int v = ord[u][j];
        if (v <= s)
          continue;
        if (cmpAngle(p[u] - p[s], p[v] - p[s])) {
          if (inside(s, u, v) == 0)
            es0.push_back(Event{p[v] - p[u], 0, v});
        } else {
          es0.push_back(Event{p[v] - p[u], 1, v});
          es1.push_back(Event{p[u] - p[v], 2, v});
          if ((p[v] - p[u]).right()) {
            forn (ck, k + 1)
              if (d[v][u][ck]) {
                f[ck].add(d[v][u][ck]);
                //f[ck].insert(d[v][u][ck]);
              }
          }
        }
      }
      rotate(es1.begin(), min_element(es1.begin(), es1.end()), es1.end());
      //assert(is_sorted(all(es0)));
      //assert(is_sorted(all(es1)));
      merge(all(es0), all(es1), back_inserter(es));
      for (auto e : es) {
        int v = e.id;
        if (e.type == 0) {
          forn (ck, k) {
            ll val = f[ck].get();
            if (val)
              uax(d[u][v][ck + 1], S(s, u, v) + val);
          }
        } else if (e.type == 1) {
          forn (ck, k + 1)
            if (d[v][u][ck]) {
              f[ck].del();
              //f[ck].erase(f[ck].find(d[v][u][ck]));
            }
        } else if (e.type == 2) {
          forn (ck, k + 1)
            if (d[v][u][ck]) {
              f[ck].add(d[v][u][ck]);
              //f[ck].insert(d[v][u][ck]);
            }
        }
      }
      forn (v, n) {
        ll cur = d[u][v][k];
        //if (cur)
          //cerr << "upd " << s << ' ' << u << ' ' << v << ' ' << cur << '\n';
        best = max(best, cur);
      }
    }
    if (clock() * 1.0 / CLOCKS_PER_SEC > 1.920) break;
  }

  cout << best / 2 << ".";
  if (best % 2)
    cout << "50\n";
  else
    cout << "00\n";
#ifdef LOCAL
  assert(cbest == best);
#endif
}