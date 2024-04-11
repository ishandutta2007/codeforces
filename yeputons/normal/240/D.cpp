#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
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

void read(vi &as, int &a0, int n) {
  scanf("%d", &a0);
  as.pb(1);

  int prev = a0;
  for (int i = 1; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x != prev) as.pb(0);
    as.back()++;
    prev = x;
  }
}

struct Ans {
  vi ids;
  vi seq;

  bool operator<(const Ans &a2) const { return sz(seq) < sz(a2.seq); }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #else
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d", &n) >= 1) {
    int c1 = n;
    vi as; int a0;
    read(as, a0, n);

    vi aids(n);
    for (int i = 0; i < n; i++) aids[i] = i + 1;

    scanf("%d", &n);
    vi bs; int b0;
    read(bs, b0, n);

    vi bids(n);
    for (int i = 0; i < n; i++) bids[i] = c1 + i + 1; 

    n = sz(as);
    m = sz(bs);

    Ans ans;
    ans.seq.resize(1e6);
    for (int step = 0; step < 2; step++) {
      for (int off = -1; off <= 0; off++) {
        vi res;
        Ans cans;
        int id1 = 0, id2 = 0;
        int p1 = 0, p2 = p1 + off;
        for (; p1 < n || p2 < m; p1++, p2++) {
          if (p1 >= 0 && p1 < n) {
            for (int i = 0; i < as[p1]; i++) {
              cans.ids.pb(aids[id1++]);
              res.pb((p1 ^ a0) & 1);
            }
          }
          if (p2 >= 0 && p2 < m) {
            for (int i = 0; i < bs[p2]; i++) {
              cans.ids.pb(bids[id2++]);
              res.pb((p2 ^ b0) & 1);
            }
          }
       }
 
        res.pb(0);
        for (int i = 0; i + 1 < sz(res); i++)
          if (res[i] != res[i + 1])
            cans.seq.pb(i + 1);
        ans = min(ans, cans);
      }

      as.swap(bs);
      aids.swap(bids);
      swap(a0, b0);
      swap(n, m);
    }

    for (int i = 0; i < sz(ans.ids); i++)
      printf("%d%c", ans.ids[i], "\n "[i + 1 < sz(ans.ids)]);
    printf("%d\n", sz(ans.seq));
    for (int i = 0; i < sz(ans.seq); i++)
      printf("%d%c", ans.seq[i], "\n "[i + 1 < sz(ans.seq)]);
  }
  return 0;
}