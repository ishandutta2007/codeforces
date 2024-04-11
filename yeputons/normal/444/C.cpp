#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
#define TASKNAME ""

#ifdef DEBUG
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;

const int inf = 1e9;
const double eps = 1e-9;
const int INF = inf;
const double EPS = eps;

#ifdef DEBUG
struct __timestamper {
  ~__timestamper(){
    TIMESTAMP(end);
  }
} __Timestamper;
#else
struct __timestamper {};
#endif

/*Template end*/

const int BSZ = 70;
struct Block {
  int cols[BSZ];
  int scols[BSZ];
  ll scsum[BSZ + 1];

  ll anses[BSZ];
  ll sumans;

  int fircol, lascol;
  ll fcoladd;
  ll toadd;

  void norm() {
    if (fircol < 0) return;
    for (int i = 0; i < BSZ; i++) {
      ll diff = abs(cols[i] - fircol) + toadd;
      anses[i] += diff;
      sumans += diff;
      cols[i] = lascol;
    }
    for (int i = 0; i < BSZ; i++) {
      scols[i] = lascol;
      scsum[i + 1] = scsum[i] + scols[i];
    }
    fircol = lascol = -1;
    fcoladd = 0;
    toadd = 0;
  }
  void updScols() {
    memcpy(scols, cols, sizeof scols);
    sort(scols, scols + BSZ);
    for (int i = 0; i < BSZ; i++) {
      scsum[i + 1] = scsum[i] + scols[i];
    }
  }

public:
  Block() {
    memset(cols, 0, sizeof cols);
    memset(scols, 0, sizeof scols);
    memset(scsum, 0, sizeof scsum);
    memset(anses, 0, sizeof anses);
    sumans = 0;
    fircol = lascol = -1;
    fcoladd = 0;
    toadd = 0;
  }
  void clearExceptCols() {
    norm();
    memset(anses, 0, sizeof anses);
    sumans = 0;
    fircol = lascol = -1;
    fcoladd = 0;
    toadd = 0;
  }
  void paint(int l, int r, int col) {
    l = max(0, l);
    r = min(r, BSZ - 1);
    if (l > r) return;

    if (l == 0 && r == BSZ - 1) {
      if (lascol >= 0)
        toadd += ll(abs(lascol - col));
      else {
        fircol = col;
        fcoladd = 0;

        int pos = lower_bound(scols, scols + BSZ, fircol) - scols;
        fcoladd += ll(pos) * fircol - scsum[pos];
        fcoladd += (scsum[BSZ] - scsum[pos]) - ll(BSZ - pos) * fircol;
      }
      lascol = col;
      return;
    }
    norm();
    for (int i = l; i <= r; i++) {
      int diff = abs(cols[i] - col);
      anses[i] += diff;
      sumans += diff;
      cols[i] = col;
    }
    updScols();
  }
  ll get(int l, int r) {
    l = max(0, l);
    r = min(r, BSZ - 1);
    if (l > r) return 0;

    if (l == 0 && r == BSZ - 1) {
      ll res = sumans + ll(toadd) * BSZ + fcoladd;
      return res;
    }
    norm();
    ll res = 0;
    for (int i = l; i <= r; i++)
      res += anses[i];
    return res;
  }
};

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    vector<Block> bs((n + BSZ - 1) / BSZ);
    for (int i = 0; i < n; i++) {
      bs[i / BSZ].paint(i % BSZ, i % BSZ, i + 1);
    }
    for (Block &b : bs)
      b.clearExceptCols();

    while (m --> 0) {
      int ty, l, r;
      scanf("%d%d%d", &ty, &l, &r), l--, r--;

      int col = -1;
      if (ty == 1) scanf("%d", &col);
      ll ans = 0;

      for (int i = 0; i < sz(bs); i++) {
        int st = i * BSZ;
        if (col >= 0) bs[i].paint(l - st, r - st, col);
        else ans += bs[i].get(l - st, r - st);
      }

      if (col == -1) printf(LLD"\n", ans);
    }
  }

  return 0;
}