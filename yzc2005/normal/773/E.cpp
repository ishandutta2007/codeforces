#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 5e5 + 5;
int n, pos[N];
pii a[N];
int add[N * 4];
pii mn[N * 4];
void tag(int p, int v) {add[p] += v, mn[p].first += v;}
void push(int p) {if (add[p]) tag(p << 1, add[p]), tag(p << 1 | 1, add[p]), add[p] = 0;}
void pull(int p) {mn[p] = min(mn[p << 1], mn[p << 1 | 1]);}
void build(int p, int l, int r) {
  if (l == r) return void(mn[p] = {a[l].first, l});
  int mid = l + r >> 1; 
  build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
  pull(p);
}
void modify(int p, int l, int r, int ll, int rr, int v) {
  if (l >= ll && r <= rr) return tag(p, -v);
  push(p); int mid = l + r >> 1;
  if (mid >= ll) modify(p << 1, l, mid, ll, rr, v);
  if (mid < rr) modify(p << 1 | 1, mid + 1, r, ll, rr, v);
  pull(p);
} 
pii query(int p, int l, int r, int ll, int rr) {
  if (l >= ll && r <= rr) return mn[p];
  push(p); int mid = l + r >> 1;
  if (mid >= ll && mid < rr) return min(query(p << 1, l, mid, ll, rr), query(p << 1 | 1, mid + 1, r, ll, rr));
  if (mid >= ll) return query(p << 1, l, mid, ll, rr);
  return query(p << 1 | 1, mid + 1, r, ll, rr);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i].first, a[i].second = i;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) pos[a[i].second] = i;
  set<int> zero, minus, plus;
  build(1, 1, n);
  for (int id = 1; id <= n; ++id) {
    int i = pos[id];
    auto p = query(1, 1, n, i, i); 
    if (p.first == 0) {
      zero.insert(i);
    } else if (p.first < 0) {
      minus.insert(i), modify(1, 1, n, i, n, -1);
      int j = *--minus.end();
      if (a[j].first == 1 - minus.size()) {
        minus.erase(j), zero.insert(j);
        modify(1, 1, n, j, n, 1);
      } else {
        if (!zero.empty()) {
          int k = *zero.begin();
          zero.erase(k), plus.insert(k);
          modify(1, 1, n, k, n, 1);
        }
      }
    } else {
      plus.insert(i), modify(1, 1, n, i, n, 1);
      auto p = query(1, 1, n, i, n);
      if (p.first == -1) {
        int j = p.second;
        plus.erase(j),   zero.insert(j);
        modify(1, 1, n, j, n, -1);
      }
    }
    printf("%d\n", int(plus.size() - minus.size()));
  }
  return 0;
}