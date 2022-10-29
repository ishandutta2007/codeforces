#include <cstdio>
#include <algorithm>

const int N = 7, M = 1 << N;

double win[N][M], exv[N][M];
double prob[M][M];
int n, m;

int main() {
  scanf("%d", &n);
  m = 1 << n;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%lf", &prob[i][j]);
      prob[i][j] /= 100.0;
    }
  }
  for (int i = 0; i < m; ++i) {
    win[0][i] = 1;
    exv[0][i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      win[i][j] = exv[i][j] = 0;
      for (int k = 0; k < m; ++k) {
        if (j == k) continue;
        int lcp = 0;
        for (int x = n - 1; x >= 0; --x) {
          if ((j >> x & 1) == (k >> x & 1)) ++lcp;
          else break;
        }
        if (n - lcp != i) continue;
        win[i][j] += win[i - 1][k] * prob[j][k];
        exv[i][j] = std::max(exv[i][j], exv[i - 1][j] + exv[i - 1][k]);
      }
      win[i][j] *= win[i - 1][j];
      exv[i][j] += win[i][j] * (1 << (i - 1));
    }
  }
  printf("%.20f\n", *std::max_element(exv[n], exv[n] + m));
  return 0;
}