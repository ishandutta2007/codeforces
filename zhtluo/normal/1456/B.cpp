#include <bits/stdc++.h>

const int MAX = 1E9;

int N;
int A[110000];

int main() {
#ifdef LOCAL_JUDGE
  freopen(".in", "r", stdin);
#endif
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
  for (int i = 0; i + 2 < N; ++i) {
    if ((A[i] ^ A[i + 1]) > A[i + 2] || A[i] > (A[i + 1] ^ A[i + 2])) {
      puts ("1"); return 0;
    }
  }
  int sum = MAX;
  for (int i = 0; i < N; ++i)
    for (int j = i + 1; j < N; ++j)
      for (int k = j + 1; k <= N; ++k) {
        int v1 = 0, v2 = 0;
        for (int l = i; l < j; ++l) v1 ^= A[l];
        for (int l = j; l < k; ++l) v2 ^= A[l];
        if (v1 > v2) sum = std::min(sum, k - i - 2);
      }
  if (sum == MAX) puts ("-1");
  else printf("%d\n", sum);
}