#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <list>

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

struct Man {
  int ty, a, id;
  Man() : ty(-1), a(0), id(-1) {}
};
typedef list<Man>::iterator iter;
struct cmp {
  bool operator()(const pair<int, iter> &a, const pair<int, iter> &b) const {
    if (a.first != b.first) return a.first < b.first;
    return a.second->id < b.second->id;
  }
};

void del(list<Man> &ms, set<pair<int, iter>, cmp > &ds, iter it) {
  iter pr = it, ne = it;
  if (it != ms.begin()) {
    pr--;
    if (pr->ty != it->ty)
      ds.erase(mp(abs(pr->a - it->a), pr));
  }

  ne++;
  if (ne != ms.end())
    if (it->ty != ne->ty)
      ds.erase(mp(abs(it->a - ne->a), it));

  if (it != ms.begin() && ne != ms.end())
    if (pr->ty != ne->ty)
      ds.insert(mp(abs(pr->a - ne->a), pr));
  ms.erase(it);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    list<Man> ms;
    for (int i = 0; i < n; i++) {
      char c;
      scanf(" %c", &c);
      ms.pb(Man());
      ms.back().ty = c == 'B';
      ms.back().id = i + 1;
    }
    for (iter it = ms.begin(); it != ms.end(); it++) {
      scanf("%d", &it->a);
    }

    set<pair<int, iter>, cmp > ds;
    for (iter it = ms.begin(); it != ms.end();) {
      iter ne = it; ne++;
      if (ne == ms.end()) break;

      if (it->ty != ne->ty)
        ds.insert(mp(abs(it->a - ne->a), it));

      it = ne;
    }

    vector<pii> ans;
    while (!ds.empty()) {
      iter it = ds.begin()->second, ne = it; ne++;
      ans.pb(mp(it->id, ne->id));
      del(ms, ds, it);
      del(ms, ds, ne);
    }
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); i++)
      printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}