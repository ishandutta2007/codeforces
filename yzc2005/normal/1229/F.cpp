#include <bits/stdc++.h>
const int N = 35005;
using ll = long long;
int n, l[N], r[N]; 
ll calc(int x1) {
  std::priority_queue<ll> lef;
  std::priority_queue<ll, std::vector<ll>, std::greater<ll>> rig;
  for (int i = 0; i < n; ++i) lef.push(x1), rig.push(x1);
  ll dl = 0, dr = 0, val = abs(x1);
  for (int i = 2; i <= n; ++i) {
    dl -= r[i], dr -= l[i];
    ll pl = lef.top() + dl, pr = rig.top() + dr;
    if (pl <= 0 && pr >= 0) lef.push(-dl), rig.push(-dr);
    else if (pl > 0) val += pl, rig.push(pl - dr), lef.pop(),  lef.push(-dl), lef.push(-dl);
    else val -= pr, lef.push(pr - dl), rig.pop(), rig.push(-dr), rig.push(-dr);
  }
  dl -= x1, dr -= x1;           
  ll pl = lef.top() + dl, pr = rig.top() + dr;
  if (pl > r[1]) {
    ll cur = 0, lst = pl; lef.pop();
    while (lef.top() + dl > r[1]) {
      val += ++cur * (lst - lef.top() - dl);
      lst = lef.top() + dl, lef.pop();
      assert(!lef.empty());
    }
    return val + ++cur * (lst - r[1]);
  } 
  if (pr < l[1]) {
    ll cur = 0, lst = pr; rig.pop();
    while (rig.top() + dr < l[1]) {
      val += ++cur * (rig.top() + dr - lst);
      lst = rig.top() + dr, rig.pop();
      assert(!rig.empty());
    }
    return val + ++cur * (l[1] - lst);
  }
  return val;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; ++i)
    scanf("%d%d%d", &x, &l[i], &r[i]), l[i] -= x, r[i] -= x;
  int r = N * N, l = -r; calc(1);
  while (l < r) {
    int mid = (l + r) >> 1;
    if (calc(mid) > calc(mid + 1)) l = mid + 1;
    else r = mid;
  }
  printf("%lld\n", calc(l));
  return 0;
}