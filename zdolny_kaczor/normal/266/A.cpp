# include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  char in[1000000];
  scanf("%d%s", &n, in);
  char last = '#';
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (in[i] == last)
      ans++;
    else
      last = in[i];
  }
  printf("%d\n", ans);
}