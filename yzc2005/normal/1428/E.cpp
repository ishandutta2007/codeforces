#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, k, a[N];
long long ans;
struct node {
  int x, y;
  long long z;
  inline bool operator < (const node &rhs) const {
    return z < rhs.z;
  }
};
priority_queue<node> q;
inline long long calc(int x, int y) {
  int z = x / y, r = x % y;
  return 1ll * z * z * (y - r) + 1ll * (z + 1) * (z + 1) * r;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    ans += 1ll * a[i] * a[i];
    q.push((node) {a[i], 1, calc(a[i], 1) - calc(a[i], 2)});
  }
  for (int i = 1; i <= k - n; ++i) {
    node cur = q.top();
    q.pop();
    ans -= cur.z;
    q.push((node) {cur.x, cur.y + 1, calc(cur.x, cur.y + 1) - calc(cur.x, cur.y + 2)});
  }
  printf("%lld\n", ans);
  return 0;
}