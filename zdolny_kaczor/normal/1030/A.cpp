# include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  int x;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    if (x == 1) {
      printf("%c%c%c%c\n", 'H' + 32 * (i % 5 % 2), 'A' + 32 * (i % 17 % 5 % 2), 'R' + 32 * (i % 19 % 2), 'D' + 32 * (i % 43 % 5 % 2));
      return 0;
    }
  }
  printf("EaSY\n");
}