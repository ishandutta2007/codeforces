# include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  if (n == 1 && t == 10)
    return 0 * printf("-1\n");
  int c = 0;
  for (int i = 0; i < n - 1; ++i) {
    printf("9");
    c = (c * 10 + 9) % t;
  }
  c = c * 10 % t;
  printf("%d\n", (t - c) % t + (9 - (t - c) % t) / t * t);
}