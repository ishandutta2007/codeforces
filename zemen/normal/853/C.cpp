#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define y1 yy1

const int maxn = 200200;
int a[maxn];

struct Fenwick {
  int a[maxn];

  Fenwick() {
    memset(a, 0, sizeof(a));
  }

  void clear() {
    memset(a, 0, sizeof(a));
  }

  void put(int pos) {
    for (int i = pos; i < maxn; i |= i + 1) {
      a[i]++;
    }
  }

  int getTo(int r) {
    int res = 0;
    for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1)
      res += a[i];
    return res;
  }

  int getFrom(int l) {
    return getTo(maxn) - getTo(l);
  }
} fw;

int x1[maxn];
int y1[maxn];
int x2[maxn];
int y2[maxn];
vector<int> byx1[maxn];
vector<int> byx2[maxn];
ll ans[maxn];

ll c2(ll x) {
  return x * (x - 1) / 2;
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    --a[i];
  }
  for (int i = 0; i < q; ++i) {
    scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
    --x1[i];
    --y1[i];
    byx1[x1[i]].push_back(i);
    byx2[x2[i]].push_back(i);
    ans[i] = c2(n) - (c2(x1[i]) + c2(n - x2[i]) + c2(y1[i]) + c2(n - y2[i]));
  }

  for (int i = 0; i < n; ++i) {
    for (auto id : byx1[i]) {
      ans[id] += c2(fw.getTo(y1[id]));
      ans[id] += c2(fw.getFrom(y2[id]));
    }
    fw.put(a[i]);
  }
  fw.clear();
  for (int i = n - 1; i >= 0; --i) {
    fw.put(a[i]);
    for (auto id : byx2[i]) {
      ans[id] += c2(fw.getTo(y1[id]));
      ans[id] += c2(fw.getFrom(y2[id]));
    }
  }
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << '\n';
  }
}