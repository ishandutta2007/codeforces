#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 22;
const int INF = 1e9;

int n;
int costs[2][MAXN][MAXN];
int result;

int a[MAXN + 1][MAXN + 1];
int u[MAXN][MAXN + 1], v[MAXN][MAXN + 1], p[MAXN][MAXN + 1], way[MAXN][MAXN + 1];
int minv[MAXN + 1];
bool used[MAXN + 1];

void update_ans(int final_step) {
  result = max(result, v[final_step - 1][0]);
}

void update_hung_impl(int step) {
  p[step][0] = step + 1;
  int j0 = 0;

  for (int i = 0; i < MAXN; i++) {
    minv[i] = INF;
    used[i] = 0;
  }

  do {
    used[j0] = true;
    int i0 = p[step][j0],  delta = INF,  j1;
    for (int j=1; j<=n; ++j)
      if (!used[j]) {
        int cur = a[i0][j]-u[step][i0]-v[step][j];
        if (cur < minv[j])
          minv[j] = cur,  way[step][j] = j0;
        if (minv[j] < delta)
          delta = minv[j],  j1 = j;
      }
    for (int j=0; j<=n; ++j)
      if (used[j])
        u[step][p[step][j]] += delta,  v[step][j] -= delta;
      else
        minv[j] -= delta;
    j0 = j1;
  } while (p[step][j0] != 0);
  do {
    int j1 = way[step][j0];
    p[step][j0] = p[step][j1];
    j0 = j1;
  } while (j0);
}

void update_hung(int step) {
  if (step > 0) {
    for (int i = 0; i < MAXN; i++) {
      u[step][i] = u[step - 1][i];
      v[step][i] = v[step - 1][i];
      p[step][i] = p[step - 1][i];
      way[step][i] = way[step - 1][i];
      u[step][i] = u[step - 1][i];
    }
  } else {
    for (int i = 0; i < MAXN; i++) {
      u[step][i] = 0;
      v[step][i] = 0;
      p[step][i] = 0;
      way[step][i] = 0;
      u[step][i] = 0;
    }
  }
  update_hung_impl(step);
}

void dfs(int step, int zero, int one) {
  if (zero == 0 && one == 0) {
    update_ans(step);
  }
  if (zero > 0) {
    for (int i = 0; i < n; i++)
      a[step + 1][i + 1] = costs[0][i][step];
    update_hung(step);
    dfs(step + 1, zero - 1, one);
  }
  if (one > 0) {
    for (int i = 0; i < n; i++)
      a[step + 1][i + 1] = costs[1][i][step];
    update_hung(step);
    dfs(step + 1, zero, one - 1);
  }
}

int main() {
  scanf("%d", &n);
  for (int x = 0; x <= 1; x++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &costs[x][i][j]);
        costs[x][i][j] = -costs[x][i][j];
      }
    }
  }
  dfs(0, n / 2, n / 2);
  printf("%d\n", result);
  return 0;
}