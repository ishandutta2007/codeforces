# include <bits/stdc++.h>
using namespace std;
const int B = 7;
const int MOD = 1e6 + 3;
#define pow asnteho
long long pow(long long b, int e) {
  if (e == 0)
    return 1;
  if (e % 2)
    return pow(b, e - 1) * b % MOD;
  return pow(b * b % MOD, e / 2);
}
int main() {
  int h1 = 0, h2 = 0;
  int c;
  while ((c = getchar()) != '\n')
    h1 = (h1 * B + c) % MOD;
  for (int i = 0; (c = getchar()) != '\n'; ++i)
    h2 = (h2 + pow(B, i) * c) % MOD;
  if (h1 == h2)
    printf("YES\n");
  else
    printf("NO\n");
}