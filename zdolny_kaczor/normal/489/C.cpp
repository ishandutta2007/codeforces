# include <bits/stdc++.h>
using namespace std;
int main() {
  int m, s;
  scanf("%d%d", &m, &s);
  if (s > 9 * m || (s == 0 && m > 1))
    return 0 * printf("-1 -1\n");
  if (s == 0 && m == 1)
    return 0 * printf("0 0\n");
  vector <int> low(m), high(m);
  low[0]++;
  int left = s - 1;
  for (int i = m - 1; i >= 0; --i) {
    low[i] += min(left, 9);
    left -= low[i];
  }
  left = s;
  for (int i = 0; i < m; ++i) {
    high[i] = min(left, 9);
    left -= high[i];
  }
  for (int i : low)
    printf("%d", i);
  printf(" ");
  for (int i : high)
    printf("%d", i);
  printf("\n");
}