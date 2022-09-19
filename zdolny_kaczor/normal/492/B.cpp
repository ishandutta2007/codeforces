# include <bits/stdc++.h>
using namespace std;
int a[1410];
int main() {
  int n, l;
  scanf("%d%d", &n, &l);
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  int M = 0;
  sort(a, a + n);
  M = 2 * max(a[0], l - a[n - 1]);
  for (int i = 1; i < n; ++i)
    M = max(M, a[i] - a[i - 1]);
  printf("%d.%d\n", M / 2, 5 *(M % 2));
}