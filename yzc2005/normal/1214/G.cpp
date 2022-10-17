#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int n, m, q, pop[N];
bitset<N> pre[N], f[N];
set<pair<int, int>> chain;
set<int> cand;

inline void flip(int i, int l, int r) {
  f[i] ^= pre[r] ^ pre[l - 1];
  pop[i] = f[i].count();
}
inline bool judge(int i, int j) {
  return (f[i] & f[j]) == f[j];
}
inline void find(int x1, int x2) {
  bitset<N> dif = f[x1] ^ f[x2];
  int y1 = (dif & f[x1])._Find_first();
  int y2 = (dif & f[x2])._Find_first();
  assert(f[x1].test(y1) && !f[x1].test(y2));
  assert(!f[x2].test(y1) && f[x2].test(y2));
  if (x1 > x2) swap(x1, x2);
  if (y1 > y2) swap(y1, y2);
  printf("%d %d %d %d\n", x1, y1, x2, y2);
}
inline void answer() {
  if (cand.empty()) puts("-1");
  else {
    int x1 = *cand.begin();
    auto cur = make_pair(-pop[x1], x1);
    int x2 = chain.upper_bound(cur)->second;
    find(x1, x2);
  }
}

inline void del(int x) {
  if (cand.count(x)) cand.erase(x);
  auto cur = make_pair(-pop[x], x);
  chain.erase(cur);
  auto it = chain.upper_bound(cur);
  if (it != chain.begin()) {
    int i = (--it)->second; ++it;
    if (cand.count(i)) cand.erase(i);
  }
  if (it != chain.end() && it != chain.begin()) {
    int j = it->second, i = (--it)->second;
    if (!judge(i, j)) cand.insert(i);  
  }    
}
inline void ins(int x) {
  auto cur = make_pair(-pop[x], x);
  auto it = chain.upper_bound(cur);
  if (it != chain.begin()) {
    int i = (--it)->second; ++it;
    if (cand.count(i)) cand.erase(i);
    if (!judge(i, x)) cand.insert(i);
  }
  if (it != chain.end()) {
    int j = it->second;
    if (!judge(x, j)) cand.insert(x);
  }  
  chain.insert(cur);
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= m; ++i) {
    pre[i] = pre[i - 1], pre[i].set(i);
    chain.emplace(0, i);
  }
  for (int tt = 0; tt < q; ++tt) {
    int i, l, r; scanf("%d%d%d", &i, &l, &r);
    del(i), flip(i, l, r), ins(i);
    answer();
  }
  return 0;
}