# include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, B = 107, MN = 101;
char a[MN];
int main() {
  int n;
  scanf("%d%s", &n, a);
  int longest = 1;
  long long pow = 1;
  long long hash1 = 0, hash2 = 0;
  for (int i = 0; i * 2 < n; ++i) {
    pow = (pow * B) % MOD;
    hash1 = (hash1 * B + a[i]) % MOD;
    hash2 = (hash2 * B * B + a[2 * i] * B + a[2 * i + 1] - pow * a[i]) % MOD;
    if ((hash1 - hash2) % MOD == 0) longest = i + 1;
  }
  printf("%d\n", n + 1 - longest);
}