#include <bits/stdc++.h>

int arr[210000];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &arr[i]);
    }
    int l = 0, r = N - 2;
    for (; l + 1 < N && arr[l] != arr[l + 1]; ++l)
      ;
    for (; r >= 0 && arr[r] != arr[r + 1]; --r)
      ;
    if (l >= r)
      puts("0");
    else
      printf("%d\n", std::max(1, r - l - 1));
  }
}