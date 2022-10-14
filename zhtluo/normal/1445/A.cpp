#include <bits/stdc++.h>

int N, X;
int A[100], B[100];

int main() {
#ifndef ONLINE_JUDGE
  freopen(".in", "r", stdin);
#endif
  int T; scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &N, &X);
    for (int i = 0; i < N; ++i) 
      scanf("%d", &A[i]);
    for (int i = 0; i < N; ++i) 
      scanf("%d", &B[i]);
    bool ok = true;
    for (int i = 0; i < N; ++i)
      if (A[i] + B[N - 1 - i] > X) ok = false;
    puts (ok ? "YES" : "NO");
  }
}