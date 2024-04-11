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
typedef pair<int, int> pii;

const int MAXN = 2e5 + 1000;
vi tr[MAXN];
int tsz;

inline int f(int x) { return x & -x; }
void add(int x, int v) {
  for (x++; x > 0; x -= f(x))
    tr[x].pb(v);
}
ll get(int x, int minv) {
  ll res = 0;
  for (x++; x < tsz; x += f(x))
    res += tr[x].end() - lower_bound(tr[x].begin(), tr[x].end(), minv);
  return res;
}

bool cmp2(const pair<pii, int> &a, const pair<pii, int> &b) { return a.first.second < b.first.second; }
bool cmp2b(const pii &a, const pii &b) { return a.second < b.second; }

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vi as(n), pos(n + 1, -1);
    for (int i = 0; i < n; i++) {
      scanf("%d", &as[i]);
      pos[as[i]] = i;
    }

    tsz = n + 1;
    for (int i = 0; i < tsz; i++) {
      tr[i].reserve(100);
      tr[i].resize(0);
    }

    vector<pair<pii, int> > rqs(m);
    for (int i = 0; i < m; i++)
      scanf("%d%d", &rqs[i].first.first, &rqs[i].first.second), rqs[i].first.first--, rqs[i].first.second--, rqs[i].second = i;
    sort(rqs.begin(), rqs.end(), cmp2);

    vector<pii> all;
    for (int i = 0; i < n; i++) {
      if (as[i] >= 1) {
        int val = as[i];
        while (val <= n) {
          int v1 = pos[val], v2 = i;
          if (v1 > v2) swap(v1, v2);
          all.pb(mp(v1, v2));
          val += as[i];
        }
      }
    }
    sort(all.begin(), all.end(), cmp2b);
    eprintf("ggg %d\n", clock());

    vll ans(m, -1);
    int ptr = 0;
    int pa = 0;
    for (int i = 0; i < n; i++) {
      while (pa < sz(all) && all[pa].second <= i) {
        add(all[pa].first, all[pa].second);
        pa++;
      }

      while (ptr < m && rqs[ptr].first.second <= i) {
        int id = rqs[ptr].second;
        int l = rqs[ptr].first.first;
        int r = rqs[ptr].first.second;
        ans[id] = get(l, l);
//        if (l <= pos[1] && pos[1] <= r)
//          ans[id] += r - l + 1;
        ptr++;
      }
    }
    assert(ptr == m);

    for (int i = 0; i < m; i++)
      printf("%I64d\n", ans[i]);
  }
  eprintf("%d\n", clock());
  return 0;
}