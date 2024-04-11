#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
const int N = 100005;
int tot, p[N], v[N], mu[N], pwr[N];
int n, cnt[N];
int main() {
  mu[1] = 1;
  for (int i = 2; i < N; ++i) {
    if (!v[i]) {
      p[++tot] = i;
      v[i] = i;
      mu[i] = -1; 
    }
    for (int j = 1; j <= tot && i * p[j] < N; ++j) {
      v[i * p[j]] = p[j];
      if (i % p[j] == 0) {
        break;
      } 
      mu[i * p[j]] = -mu[i];
    }
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    ++cnt[x]; 
  }
  pwr[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pwr[i] = 2ll * pwr[i - 1] % P;
  }
  int ans = 0;
  for (int i = 1; i < N; ++i) {
    int x = 0;
    for (int j = i; j < N; j += i) {
      x += cnt[j];
    }
    ans = (ans + mu[i] * (pwr[x] - 1)) % P;
  }
  printf("%d\n", (ans + P) % P);
  return 0;
}