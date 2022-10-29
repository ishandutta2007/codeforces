#include <cstdio>

char a[100], b[100];

int main() {
  int n;
  scanf("%d", &n);
  int soft = 0, hard = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s%s", a, b);
    if (b[0] == 's') ++soft;
    else ++hard;
  }
  for (int x = 1; x < 1000; ++x) {
    int a = x * x / 2, b = x * x - a;
    if (a >= soft && b >= hard || a >= hard && b >= soft) {
      printf("%d\n", x);
      return 0;
    }
  }
  return 0;
}