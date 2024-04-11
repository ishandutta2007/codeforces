#include <bits/stdc++.h>

std::vector<int> per[210000];
int arr[210000], size[210000];
int N;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", &arr[i]);
    for (int i = 0; i < N; ++i) {
      per[size[arr[i]]].push_back(i);
      ++size[arr[i]];
    }
    for (int i = 0; i < N; ++i) {
      std::sort(per[i].begin(), per[i].end(),
                [&](int a, int b) { return arr[a] < arr[b]; });
      for (int j = 0; j + 1 < per[i].size(); ++j)
        std::swap(arr[per[i][j]], arr[per[i][j + 1]]);
    }
    for (int i = 0; i < N; ++i) printf("%d%c", arr[i], " \n"[i + 1 == N]);
    for (int i = 0; i <= N; ++i) per[i].clear();
    std::fill(size, size + N + 1, 0);
  }
}