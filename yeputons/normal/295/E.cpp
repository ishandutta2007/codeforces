#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

class fenv_tree {
  static int f(int x) { return x & -x; }
  vll t;

  public:
  fenv_tree(int n) : t(n + 1, 0) {}
  void add(int x, ll v) {
    for (x++; x < sz(t); x += f(x))
      t[x] += v;
  }
  ll get(int x) const {
    ll res = 0;
    for (x++; x > 0; x -= f(x))
      res += t[x];
    return res;
  }
};
class MagicVec {
  vll vec;
  fenv_tree tr;

  public:
  MagicVec(int n) : vec(n, 0), tr(n) {}
  ll operator[](int x) {
    return vec[x] + tr.get(x);
  }
  void set(int x, ll v) {
    vec[x] = v - tr.get(x);
  }
  void addToSuf(int x, ll v) {
    if (x >= sz(vec)) return;
    tr.add(x, v);
  }
};

void rebuild(int ptr, vector<pii> &xs, vi &poses, MagicVec &sums, MagicVec &sums2k) {
  int l = ptr, r = ptr;
  while (ptr + 1 < sz(xs) && xs[ptr].first > xs[ptr + 1].first) {
    swap(poses[xs[ptr].second], poses[xs[ptr + 1].second]);
    swap(xs[ptr], xs[ptr + 1]);
    r++;
    ptr++;
  }

  while (ptr > 0 && xs[ptr].first < xs[ptr - 1].first) {
    swap(poses[xs[ptr].second], poses[xs[ptr - 1].second]);
    swap(xs[ptr], xs[ptr - 1]);
    l--;
    ptr--;
  }

  ll ds = 0, ds2k = 0;
  for (int i = l; i <= r; i++) {
    ll ns = sums[i] + xs[i].first, ns2k = sums2k[i] + xs[i].first * ll(2 * i);
    if (i < r) {
      sums.set(i + 1, ns);
      sums2k.set(i + 1, ns2k);
    } else {
      ds = ns - sums[i + 1];
      ds2k = ns2k - sums2k[i + 1];
    }
  }
  sums.addToSuf(r + 1, ds);
  sums2k.addToSuf(r + 1, ds2k);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<pii> xs(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &xs[i].first), xs[i].second = i;
    sort(xs.begin(), xs.end());

    vi poses(n);
    for (int i = 0; i < n; i++)
      poses[xs[i].second] = i;

    MagicVec sums(n + 1), sums2k(n + 1);
    for (int i = 0; i < n; i++) {
      sums.set(i + 1, sums[i] + xs[i].first);
      sums2k.set(i + 1, sums2k[i] + xs[i].first * ll(2 * i));
    }

    int m;
    scanf("%d", &m);
    while (m --> 0) {
      int t;
      scanf("%d", &t);
      if (t == 1) {
        int id, off;
        scanf("%d%d", &id, &off);
        id--;
        assert(0 <= id && id < n);

        xs[poses[id]].first += off;
        rebuild(poses[id], xs, poses, sums, sums2k);
      } else {
        int lx, rx;
        scanf("%d%d", &lx, &rx);
        int l = lower_bound(xs.begin(), xs.end(), mp(lx, -1)) - xs.begin();
        int r = upper_bound(xs.begin(), xs.end(), mp(rx, int(1e9))) - xs.begin();

        int cnt = r - l ;
        ll res = sums2k[r] - sums2k[l];
        ll sum = sums[r] - sums[l];

        int ksrc = 2 * l;
        int ktarg = -(cnt - 1);
        res += sum * (ktarg - ksrc);
        printf("%I64d\n", res);
      }
    }
  }
  return 0;
}