#include <bits/stdc++.h>

int A[210000], B[210000];
int size[210000];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
    for (int i = 0; i < N; ++i) scanf("%d", &B[i]);
    std::fill(size, size + N + 1, 0);
    int i = 0, j = 0, cur = -1;
    for (; i < N && j < N;) {
      if (A[i] != B[j]) {
        if (B[j] == cur && size[cur] > 0) {
          --size[cur];
          ++j;
        } else {
          ++size[A[i]];
          ++i;
        }
      } else {
        cur = A[i];
        ++i;
        ++j;
      }
    }
    for (; j < N;) {
      if (B[j] == cur && size[cur] > 0) {
        --size[cur];
        ++j;
      } else {
        puts("NO");
        goto end;
      }
    }
    puts("YES");
  end:;
  }
}