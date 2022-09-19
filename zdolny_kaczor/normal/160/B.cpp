# include <bits/stdc++.h>
using namespace std;
char in[110];
int main() {
  int n;
  scanf("%d%s", &n, in);
  sort(in, in + n);
  sort(in + n, in + n * 2);
  bool gr = true, le = true;
  for (int i = 0; i < n; ++i) {
    if (in[i] >= in[i + n])
      le = false;
    if (in[i] <= in[i + n])
      gr = false;
  }
  if (gr || le) printf("YES\n");
  else printf("NO\n");
}