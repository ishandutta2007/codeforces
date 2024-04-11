#include <bits/stdc++.h>

int T, N, M;
int A[200][200];
std::vector<std::vector<std::pair<int, int>>> ans;

void flip(int x, int y) {
  int cnt = A[x][y] + A[x + 1][y] + A[x][y + 1] + A[x + 1][y + 1];
  if (cnt == 0) return;
  ans.push_back(std::vector<std::pair<int, int>>());
  if (cnt == 1) {
    for (int i = 0, f = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        if (A[x + i][y + j] == 1 || (f < 2 && (++f)))
          ans.back().push_back(std::make_pair(x + i, y + j));
  } else if (cnt == 2) {
    for (int i = 0, f = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        if (A[x + i][y + j] == 0 || (f < 1 && (++f)))
          ans.back().push_back(std::make_pair(x + i, y + j));
  } else {
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        if (A[x + i][y + j] && ans.back().size() < 3)
          ans.back().push_back(std::make_pair(x + i, y + j));
  }
  assert(ans.back().size() == 3);
  for (auto &p: ans.back())
    A[p.first][p.second] ^= 1;
}

void fix1(int x, int y) {
  ans.push_back(std::vector<std::pair<int, int>>());
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      if ((i == 0 && A[x + i][y + j]) || (i == 1 && ans.back().size() < 3))
        ans.back().push_back(std::make_pair(x + i, y + j));
  if (ans.back().size() == 2) {
    ans.pop_back();
    return;
  }
  for (auto &p: ans.back())
    A[p.first][p.second] ^= 1;
}

void fix2(int x, int y) {
  ans.push_back(std::vector<std::pair<int, int>>());
  for (int j = 0; j < 2; ++j)
    for (int i = 0; i < 2; ++i)
      if ((j == 0 && A[x + i][y + j]) || (j == 1 && ans.back().size() < 3))
        ans.back().push_back(std::make_pair(x + i, y + j));
  if (ans.back().size() == 2) {
    ans.pop_back();
    return;
  }
  for (auto &p: ans.back())
    A[p.first][p.second] ^= 1;
}

void work(int x, int y) {
  int cnt = A[x][y] + A[x + 1][y] + A[x][y + 1] + A[x + 1][y + 1];
  /*
  int f1 = (N & 1) && (x + 1 == N - 2);
  int f2 = (M & 1) && (y + 1 == M - 2);
  if (x != N - 2 && y != M - 2 && f1) {
    fix1(x, y); return;
  }
  if (x != N - 2 && y != M - 2 && f2) {
    fix2(x, y); return;
  }
  */
  while (cnt) {
    flip(x, y);
    cnt = A[x][y] + A[x + 1][y] + A[x][y + 1] + A[x + 1][y + 1];
  }
}

int main() {
#ifdef LOCAL_JUDGE
  freopen(".in", "r", stdin);
#endif
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j) {
        char c; scanf(" %c", &c);
        A[i][j] = c - '0';
      }
  /*
  for (N = 2; N <= 4; ++N) for (M = 2; M <= 4; ++M) for (int mask = 0; mask < (1 << N * M); ++mask) {
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j) {
        A[i][j] = mask >> (i * M + j) & 1;
      }
  */
    ans.clear();
    for (int i = 0; i + 1 < N; i += 2)
      for (int j = 0; j + 2 < M; ++j)
        fix2(i, j);
    if (N & 1)
      for (int j = 0; j + 1 < M; ++j) fix2(N - 2, j);
    for (int i = 0; i + 1 < N; ++i) fix1(i, M - 2);
    work(N - 2, M - 2);
    /*
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
          printf("%d", mask >> (i * M + j) & 1);
        puts("");
      }
      fflush(stdout);
    */
    printf("%d\n", (int)ans.size());
    for (auto &v: ans) {
      for (auto &p: v)
        printf("%d %d ", p.first + 1, p.second + 1);
      puts("");
    }
    assert((int)ans.size() <= N * M);
    // for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j)
    //  printf("%d%c", A[i][j], " \n"[j + 1 == M]);
    // fflush(stdout);
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) assert(A[i][j] == 0);
  }
}