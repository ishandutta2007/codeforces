#include <cstdio>
#include <algorithm>

int main() {
  int n;
  scanf("%d", &n);
  int ret = n * 2 + 2;
  for (int i = 1; i <= n; ++i) {
    int j = (n + i - 1) / i;
    ret = std::min(ret, (i + j) * 2);
  }
  printf("%d\n", ret);
  return 0;
}