#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()

const int maxn = 300300;
const int K = 5;
int a[maxn];
vector<int> s[maxn];

struct E {
  pii v[12];
  int c;

  E() : c(0) {
  }

  E(const E& a, const E& b) {
    int ia = 0, ib = 0;
    c = 0;
    assert(a.c <= K);
    assert(b.c <= K);
    while (ia < a.c || ib < b.c) {
      if (ia < a.c && ib < b.c && a.v[ia].first == b.v[ib].first) {
        v[c++] = pii{a.v[ia].first, a.v[ia].second + b.v[ib].second};
        ++ia, ++ib;
        continue;
      }
      if (ia < a.c && (ib == b.c || a.v[ia].first < b.v[ib].first)) {
        v[c++] = a.v[ia++];
      } else {
        v[c++] = b.v[ib++];
      }
    }
    assert(c <= 2 * K);
    if (c > K) {
      sort(v, v + c, [](pii a, pii b) {
            return a.second > b.second;
          });
      int rem = v[K].second;
      forn (i, K)
        v[i].second -= rem;
      c = K;
      sort(v, v + c);
    }
  }
};

const int base = 1 << 19;
E t[base * 2];

E get(int l, int r, int v = 1, int cl = 0, int cr = base) {
  if (l <= cl && cr <= r)
    return t[v];
  if (r <= cl || cr <= l)
    return E();
  int cc = (cl + cr) / 2;
  auto res = E(get(l, r, v * 2, cl, cc), get(l, r, v * 2 + 1, cc, cr));
  return res;
}

int cnt(int x, int l, int r) {
  return lower_bound(all(s[x]), r) - lower_bound(all(s[x]), l);
}

const int inf = 2e9;
int query(int l, int r, int k) {
  int res = inf;
  auto e = get(l, r);
  int bound = (r - l) / k + 1;
  forn (i, e.c) {
    int x = e.v[i].first;
    if (cnt(x, l, r) >= bound) {
      res = min(res, x);
    }
  }
  if (res == inf)
    res = -1;
  return res;
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n, q;
  scanf("%d%d", &n, &q);
  forn (i, n) {
    scanf("%d", &a[i]);
    s[a[i]].push_back(i);
    t[i + base].v[0] = pii(a[i], 1);
    t[i + base].c = 1;
  }
  for (int i = base - 1; i > 0; --i) {
    t[i] = E(t[i * 2], t[i * 2 + 1]);
  }
  forn (i, q) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    --l;
    cout << query(l, r, k) << '\n';
  }
}