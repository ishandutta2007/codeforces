#include <bits/stdc++.h>
using namespace std;
int cou[128];
char in[3][1000];
int main() {
  scanf("%s%s%s", in[0], in[1], in[2]);
  int coef[3] = {1, 1, -1};
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; in[i][j]; ++j)
      cou[in[i][j]] += coef[i];
  }
  bool good = true;
  for (int i = 0; i < 128; ++i)
    if (cou[i])
      good = false;
  if (good)
    printf("YES\n");
  else
    printf("NO\n");
}