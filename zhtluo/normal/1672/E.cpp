#include <bits/stdc++.h>

int main() {
  int N;
  scanf("%d", &N);
  int l = N, r = N * 2000, ans = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    printf("? %d\n", m + (N - 1));
    fflush(stdout);
    int u;
    scanf("%d", &u);
    if (u == 1) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  int output = ans + (N - 1);
  for (int i = 2; i <= N; ++i) {
    int len = (ans + (N - i) + i - 1) / i;
    printf("? %d\n", len);
    fflush(stdout);
    int u;
    scanf("%d", &u);
    if (u != 0) output = std::min(output, len * u);
  }
  printf("! %d\n", output);
  fflush(stdout);
  return 0;
}