# include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 44;
long long a[MN];
long long ans[MN];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a[x] += x;
  }
  ans[0] = 0;
  ans[1] = a[1];
  for (int i = 2; i < MN; ++i)
    ans[i] = max(ans[i - 1], a[i] + ans[i - 2]);
  printf("%lld\n", ans[MN - 1]);
}