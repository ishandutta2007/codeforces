char a[101], b[101];
main() {
  scanf("%s%s", a, b);
  for (int i = 0; a[i]; ++i)
    a[i] ^= b[i] ^ '0';
  printf("%s\n", a);
}