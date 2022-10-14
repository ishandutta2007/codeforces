#include <stdio.h>
int main() {
  #ifdef DEBUG
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  #endif

  int n, m, a;
  while (scanf("%d%d%d", &n, &m, &a) >= 1) {
    n = (n / a) + !!(n % a);
    m = (m / a) + !!(m % a);
    long long ans = (long long)n * (long long)m;
    printf("%I64d\n", ans);

    #ifndef DEBUG
    break;
    #endif
  }

  return 0;
}