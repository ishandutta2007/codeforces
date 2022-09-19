# include <bits/stdc++.h>
using namespace std;
const int MN = 101;
int a[MN];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  sort(a, a + n);
  reverse(a, a + n);
  int sum = 0;
  for (int i = 0; i < n; ++i)
    sum += a[i];
  int acc = 0;
  for (int i = 0; i < n; ++i) {
    acc += a[i];
    if (acc * 2 > sum) {
      printf("%d\n", i + 1);
      return 0;
    }
  }
}