# include <bits/stdc++.h>
using namespace std;
char in[111];
int main() {
  char pos = 'a';
  scanf("%s", in);
  int ans = 0;
  for (int i = 0; in[i]; ++i) {
    int d = pos - in[i];
    if (d < 0)
      d += 26;
    ans += min(d, 26 - d);
    pos = in[i];
  }
  printf("%d\n", ans);
}