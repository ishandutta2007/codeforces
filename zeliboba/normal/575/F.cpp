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

typedef long long i64;

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

const int N = 10010;
const i64 inf = 1e18 + 100500;

int n;
pii in[N];
vi pos;
i64 d[2][N];

void solve() {
  n = 5000;
  cin >> n;
  int st = rand();
  cin >> st;
  pos.pb(st);
  // forn(i, n) in[i] = mp(rand(), rand());
  forn(i, n) cin >> in[i].fi >> in[i].se;
  forn(i, n) pos.pb(in[i].fi), pos.pb(in[i].se);
  sort(all(pos));
  pos.erase(unique(all(pos)), pos.end());
  st = lower_bound(all(pos), st) - pos.begin();
  forn(i, n) {
    in[i].fi = lower_bound(all(pos), in[i].fi) - pos.begin();
    in[i].se = lower_bound(all(pos), in[i].se) - pos.begin();
  }

  int m = pos.size();
  forn(i, m) d[0][i] = inf;
  d[0][st] = 0;

  auto up = [&] (i64 *d) {
    forn(i, m) if(i) {
      uin(d[i], d[i-1] + pos[i] - pos[i-1]);
    }
    ford(i, m-1) {
      uin(d[i], d[i+1] + pos[i+1] - pos[i]);
    }
  };

  up(d[0]);

  forn(i, n) {
    forn(j, in[i].fi) d[(i+1)&1][j] = d[i&1][j] + pos[in[i].fi] - pos[j];
    fore(j, in[i].fi, in[i].se) d[(i+1)&1][j] = d[i&1][j];
    fore(j, in[i].se + 1, m-1) d[(i+1)&1][j] = d[i&1][j] + pos[j] - pos[in[i].se];
    up(d[(i+1)&1]);
  }

  cout << *min_element(d[n&1], d[n&1] + m) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed; cout.precision(15);
  cerr << fixed; cerr.precision(15);
#ifdef HOME
  freopen("input.txt", "r", stdin);
#endif
  solve();
  return 0;
}