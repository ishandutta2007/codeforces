# include <cstdio>
int main() {
  int x1, x2, y1, y2, a, b;
  scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &a, &b);
  if ((x1 - x2) % a || (y1 - y2) % b || ((x1 - x2) / a + (y1 - y2) / b) % 2)
    printf("NO\n");
  else
    printf("YES\n");
}