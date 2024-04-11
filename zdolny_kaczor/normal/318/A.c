long long n, k;
main() {
  scanf("%lld%lld", &n, &k);
  if (k <= (n + 1) / 2)
    printf("%lld\n", k * 2 - 1);
  else
    printf("%lld\n", 2 * (k - (n + 1) / 2));
}