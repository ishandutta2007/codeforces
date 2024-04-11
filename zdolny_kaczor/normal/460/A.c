main() {
  int n, m;
  scanf("%d%d", &n, &m);
  n--;
  printf("%d\n", n % (m - 1) + n / (m - 1) * m + 1);
}