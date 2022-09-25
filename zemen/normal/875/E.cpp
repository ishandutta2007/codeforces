#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 100100;
int s1, s2, n;
int x[maxn];
int ix[maxn];
vector<int> coords;
int C;

const int base = 1 << 17;
int t[base * 2];
void put(int v, int val) {
  v += base;
  t[v] = val;
  while (v > 1) {
    v /= 2;
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}
void clear() {
  for (int i = 0; i < 2 * base; ++i) {
    t[i] = 1e9;
  }
}
void build() {
  for (int i = base - 1; i > 0; --i) {
    t[i] = min(t[i * 2], t[i * 2 + 1]);
  }
}
int get(int l, int r, int v = 1, int cl = 0, int cr = base) {
  if (l <= cl && cr <= r)
    return t[v];
  if (r <= cl || cr <= l)
    return 1e9;
  int cc = (cl + cr) / 2;
  return min(get(l, r, v * 2, cl, cc), get(l, r, v * 2 + 1, cc, cr));
}

int rb;
void relax(int px) {
  int x1 = lower_bound(coords.begin(), coords.end(), px - C) - coords.begin();
  int x2 = upper_bound(coords.begin(), coords.end(), px + C) - coords.begin();
  int min_id = min(get(0, x1), get(x2, int(coords.size())));
  //cerr << "relax to " << min_id << '\n';
  rb = max(rb, min_id);
}

bool check() {
  clear();
  for (int i = 0; i < n; ++i) {
    put(ix[i], i);
  }
  build();
  rb = 0;
  relax(s1);
  relax(s2);
  for (int i = 0; i < n; ++i) {
    if (rb <= i)
      return false;
    relax(x[i]);
    put(ix[i], 1e9);
  }
  return true;
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  cin >> n >> s1 >> s2;
  //coords.push_back(s1);
  //coords.push_back(s2);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
    coords.push_back(x[i]);
  }
  sort(coords.begin(), coords.end());
  for (int i = 0; i < n; ++i) {
    ix[i] = lower_bound(coords.begin(), coords.end(), x[i]) - coords.begin();
  }
  int L = abs(s1 - s2) - 1, R = 1e9 + 5;
  while (L + 1 < R) {
    C = (L + R) / 2;
    if (check()) {
      R = C;
    } else {
      L = C;
    }
  }
  cout << R << '\n';
}