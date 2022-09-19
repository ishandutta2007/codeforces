# include <cstdio>
int main() {
  long long a, b;
  scanf("%lld%lld", &a, &b);
  int m = 1;
  for (long long i = a + 1; i <= b; ++i) {
    m = (m * i) % 10;
    if (m == 0)
      break;
  }
  printf("%d\n", m);
}