int a[30], b[30];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", a + i, b + i);
  int c = 0;
  for (int i = 0; i < n; ++i)
    for (int k = 0; k < n; ++k)
      if (i != k && a[i] == b[k])
        c++;
  printf("%d\n", c);
}