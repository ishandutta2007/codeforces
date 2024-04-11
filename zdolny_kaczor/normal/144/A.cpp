# include <bits/stdc++.h>
using namespace std;
int a[147];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  pair <int, int> m = make_pair(1410, 1410), M = make_pair(-1410, -1410);
  for (int i = 0; i < n; ++i) {
    m = min(m, make_pair(-a[i], i));
    M = max(M, make_pair(-a[i], i));
  }
  int ans = m.second + n - 1 - M.second;
  if (m.second > M.second)
    ans--;
  printf("%d\n", ans);
}