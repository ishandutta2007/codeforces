#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<ll, ll> pii;

void upd(pii &a, const pii &b) {
  a.first = min(a.first, b.first);
  a.second = max(a.second, b.second);
}
ll max2d;
bool check(const pii &a) {
  return a.first + max2d >= a.second;
}

int n;
vector<pii> pts;
vector<pii> ls, rs;

bool can(ll maxd) {
  max2d = 2LL * maxd;
  if (check(ls[n])) return true;

  int ptr = 0;
  for (int i = 0; i < sz(pts); i++) {
    while (ptr < sz(pts) && pts[i].first + max2d >= pts[ptr].first)
      ptr++;
    assert(i < ptr);

    pii tmp = ls[i];
    upd(tmp, rs[ptr]);
    if (check(tmp)) return true;
  }
  return false;
}

const ll MAXC = 4.01e9;
void upd(pii &x, ll v) {
  x.first = min(x.first, v);
  x.second = max(x.second, v);
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    eprintf("n=%d\n", n);
    pts.resize(n);
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      pts[i] = mp(2LL * (x + y), 2LL * (x - y));
//      eprintf("%I64d %I64d\n", pts[i].first, pts[i].second);
    }
    sort(pts.begin(), pts.end());

    ls = vector<pii>(n + 1, mp(MAXC, -MAXC));
    rs = vector<pii>(n + 1, mp(MAXC, -MAXC));
    for (int i = 0; i < n; i++) {
      ls[i + 1] = ls[i];
      upd(ls[i + 1], pts[i].second);
    }
    for (int i = n - 1; i >= 0; i--) {
      rs[i] = rs[i + 1];
      upd(rs[i], pts[i].second);
    }

    ll L = -1, R = MAXC;
    assert(can(R));
    while (L + 1 < R) {
      int M = (L + R) / 2;
      if (can(M)) R = M;
      else L = M;
    }
    printf("%I64d.%I64d\n", R / 2, R % 2 * 5);
  }
  eprintf("time=%d\n", clock());
  return 0;
}