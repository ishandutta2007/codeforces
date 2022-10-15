#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define ford1(i, n) for(int i = (int)(n); i>=1; --i)
#define fored(i, a, b) for(int i = (int)(b); i >= (int)(a); --i)
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

template<class T> bool uax(T&a, const T& b) { if( a < b ) { a = b; return true; } return false; }
template<class T> bool uin(T&a, const T& b) { if( b < a ) { a = b; return true; } return false; }

const int mod = 1000000000 + 7;

int mul(int x, int y) { return x * 1ll * y % mod; }

int power(int x, int n) {
  int r = 1;
  while (n) {
    if (n&1) r = mul(r, x);
    if (n/=2) x = mul(x, x);
  } return r;
}

int inv(int x) { return power(x, mod - 2); }

#ifdef HOME
#define dbg(v) do {cerr << __PRETTY_FUNCTION__ << ":" <<  __LINE__ << "|" << v << '\n';}while(0)
#else
#define dbg(v) do {;}while(0)
#endif

const int N = 100500;
const int inf = 1e9 + 100500;

vpi g[N], gt[N];
int d[N], dt[N];
int p[N], pt[N];

int pp[N];
int pe[N];
int dd[N];
bool near_t[N];


void bfs(vpi* g, int* d, int* p, int s, int t, int n, bool zero_only = false) {
  forn(i, n) d[i] = inf;
  d[s] = 0;
  forn(i, n) p[i] = -1;
  p[s] = -1;
  queue<int> Q;
  Q.push(s);

  int cnt = 0;

  while (!Q.empty()) {
    cnt += 1;
    assert (cnt <= 3 + n * 3);
    int v = Q.front();
    Q.pop();
    for (auto e: g[v]) {
      if (zero_only) {
        if (e.se != 0) continue;
      }
      if (uin(d[e.fi], d[v] + 1)) {
        p[e.fi] = v;
        Q.push(e.fi);
      }
    }
  }
}

void bfs_last(vpi* g, int *d, bool *st, int* p, int* pe, int t, int n, int ans_len) {
  set<int> cs;
  forn(i, n) if (st[i]) {
    cs.insert(i);
  }
  int cnt = 0;
  while (cs.find(t) == cs.end()) {
    cnt += 1;
    assert (cnt <= 3 + n * 3);
    assert(!cs.empty());
    forn(j, 10) {
      set<int> ncs;
      for (int v: cs) {
        for (auto& e: g[v]) if (e.se == j && ::d[e.fi] + 1 <= ans_len) {
          ncs.insert(e.fi);
          if (uin(d[e.fi], d[v] + 1)) {
            p[e.fi] = v;
            pe[e.fi] = j;
          }
        }
      }
      if (!ncs.empty()) {
        cs = ncs;
        ans_len -= 1;
        break;
      }
    }
  }
}

void solve() {
  int n, m;

  // n = 5;
  // vpi edges;
  // forn(i, n) forn(j, n) if(i != j) {
  //   if (rand()%3)
  //     edges.eb(i, j);
  // }
  // m = edges.size();

  // n = 100000;
  // m = n;

  cin >> n >> m;

  forn(i, n) g[i].clear();
  forn(i, n) gt[i].clear();

  forn(i, m) {
    int a, b, len;
    // a = edges[i].fi;
    // b = edges[i].se;
    // len = rand() % 2;
    //
    // a = i/2*2; b = i + 1; len = 1;
    cin >> a >> b >> len;
    g[a].eb(b, len);
    gt[b].eb(a, len);

    g[b].eb(a, len);
    gt[a].eb(b, len);
  }

  bfs(gt, dt, pt, n-1, 0, n, true);
  bfs(g, d, p, 0, n-1, n);

  if (d[n-1] == inf) {
    assert(false);
    return ;
  }
  // cerr << n << ' ' << m << '\n';

  forn(i, n) near_t[i] = dt[i] != inf;
  forn(i, n) pp[i] = pt[i];
  forn(i, n) if (near_t[i]) dd[i] = dt[i]; else dd[i] = inf;

  int ans_len = inf;
  forn(i, n) if (near_t[i]) uin(ans_len, d[i]);

  bfs_last(gt, dd, near_t, pp, pe, 0, n, ans_len); 

  int v = 0;
  vi path;
  vi pathe;

  int cnt = 0;
  while (v != n-1) {
    cnt += 1;
    assert(cnt <= 3 * n + 3);
    assert(v != -1);
    path.pb(v);
    pathe.pb(pe[v]);
    v = pp[v];
  }

  while(pathe.size() >= 2 && pathe.back() == 0)
    pathe.pop_back();
  reverse(all(pathe));

  if (1) {
    forn(i, pathe.size()) cout << pathe[i];
    cout << '\n';
    cout << path.size() + 1 << '\n';
    for(int x: path) cout << x << ' ';
    cout << n-1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed; cout.precision(15);
  cerr << fixed; cerr.precision(15);
#ifdef HOME
  freopen("input.txt", "r", stdin);
#endif
  // while (1)
    solve();
  return 0;
}