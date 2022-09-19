# include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    char s[4];
    scanf("%s", s);
    ans += s[1] == '+' ? 1 : -1;
  }
  printf("%d\n", ans);
}