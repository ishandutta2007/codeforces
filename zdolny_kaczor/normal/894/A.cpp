# include <bits/stdc++.h>
using namespace std;
const int MN = 110;
char in[MN];
int main() {
  scanf("%s", in);
  int q = 0;
  for (int i = 0; in[i]; ++i)
    if (in[i] == 'Q')
      q++;
  int ans = 0;
  int seen = 0;
  for (int i = 0; in[i]; ++i) {
    if (in[i] == 'Q')
      seen++;
    else if (in[i] == 'A')
      ans += seen * (q - seen);
  }
  printf("%d\n", ans);
}