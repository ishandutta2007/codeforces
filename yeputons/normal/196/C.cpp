#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
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
typedef pair<int, int> pii;

int sgn(ll x) { return x < 0 ? -1 : !!x; }
struct pt {
  int x, y;
  int id;
  pt() : x(0), y(0) {}
  pt(int x, int y) : x(x), y(y) {}
  pt operator-(const pt &p2) const { return pt(x - p2.x, y - p2.y); }
  int operator*(const pt &p2) const { return sgn(ll(x) * p2.y - ll(y) * p2.x); }
  bool operator<(const pt &p2) const { return x != p2.x ? x < p2.x : y < p2.y; }
};

vvi es;
vector<pt> pts;
vi subsz;

void dfs1(int v, int par = -1) {
  subsz[v] = 1;
  for (int i = 0; i < sz(es[v]); i++) {
    int b = es[v][i];
    if (b == par) continue;
    dfs1(b, v);
    subsz[v] += subsz[b];
  }
}

pt root;
bool rcmp(const pt &a, const pt &b) { return (a - root) * (b - root) > 0; }

int n;
vb was;
vi ans;
void dfs2(int v, int par = -1) {
  vector<pt> rem;
  for (int i = 0; i < n; i++) if (ans[i] == v)
    rem.pb(pts[i]);
  assert(sz(rem) == subsz[v]);

  root = *min_element(rem.begin(), rem.end());
  rem.erase(min_element(rem.begin(), rem.end()));
  sort(rem.begin(), rem.end(), rcmp);

  int ptr = 0;
  for (int i = 0; i < sz(es[v]); i++) {
    int b = es[v][i];
    if (b == par) continue;

    for (int i2 = 0; i2 < subsz[b]; i2++)
      ans[rem[ptr++].id] = b;
    dfs2(b, v);
  }
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    es = vvi(n);
    pts = vector<pt>(n);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }
    for (int i = 0; i < n; i++)
      scanf("%d%d", &pts[i].x, &pts[i].y), pts[i].id = i;

    subsz = vi(n, 0);
    dfs1(0);
    was = vb(n, false);
    ans = vi(n, 0);
    dfs2(0);

    for (int i = 0; i < n; i++)
      printf("%d%c", ans[i] + 1, "\n "[i + 1 < n]);
  }
  return 0;
}