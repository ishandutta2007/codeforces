# include <cstdio>
int main() {
  int n;
  scanf("%d", &n);
  if (n % 10 <= 4)
    printf("%d\n", n - n % 10);
  else
    printf("%d\n", n - n % 10 + 10);
}