char in[2][7];
int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", in[i % 2]);
    if (strcmp(in[0], in[1]))
      ans++;
  }
  printf("%d\n", ans);
}