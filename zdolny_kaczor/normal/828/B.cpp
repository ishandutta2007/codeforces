# include <bits/stdc++.h>
using namespace std;
char in[101][101];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%s", in[i]);
  int c = 0;
  int lx = 101, hx = 0, ly = 101, hy = 0;
  for (int i = 0; i < n; ++i)
    for (int k = 0; k < m; ++k)
      if (in[i][k] == 'B') {
        c++;
        lx = min(lx, i);
        ly = min(ly, k);
        hx = max(hx, i);
        hy = max(hy, k);
      }
  int w = hx - lx + 1;
  int h = hy - ly + 1;
  int s = max(1, max(h, w));
  if (s > min(m, n))
    printf("-1");
  else
    printf("%d\n", s * s - c);
}