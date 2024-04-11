#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, a[N];

void solve() {
  scanf("%d", &n);
  vector<int> ans;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  set<int> cand, rest;
  auto prd = [&](int x) {
    auto it = rest.find(x);
    if (it == rest.begin()) return *--rest.end();
    return *--it;
  };
  auto suc = [&](int x) {
    auto it = rest.find(x);
    if (it == --rest.end()) return *rest.begin();
    return *++it;
  };
  for (int i = 1; i <= n; ++i) rest.insert(i);
  auto upd = [&](int x) {
    if (__gcd(a[x], a[prd(x)]) == 1) cand.insert(x);  
  };
  for (int i = 1; i <= n; ++i) upd(i);
  auto del = [&](int x) {
    int pr = prd(x), sc = suc(x);
    if (cand.count(sc)) cand.erase(sc);
    rest.erase(x);
    cand.erase(x);
    if (rest.empty()) return; 
    upd(pr), upd(sc);
  };
  int cur = 2, scc;
  while (!cand.empty()) {
    auto it = cand.upper_bound(ans.empty() ? 1 : scc);
    if (it == cand.end()) it = cand.begin();
    cur = *it;
    ans.emplace_back(cur);
    scc = suc(cur);
    del(cur);
  }
  printf("%d ", ans.size());
  for (int i = 0; i < int(ans.size()); ++i) 
    printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}