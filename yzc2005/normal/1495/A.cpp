#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
void solve() {
  int n;
  scanf("%d", &n);
  vector<int> x, y;
  for (int i = 0; i < 2 * n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (!a) y.emplace_back(abs(b));
    else x.emplace_back(abs(a));
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  double ans = 0;
  for (int i = 0; i < n; ++i) 
    ans += sqrt(1ll * x[i] * x[i] + 1ll * y[i] * y[i]);
  printf("%.9f\n", ans);
}
int main() {
  int t; 
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}