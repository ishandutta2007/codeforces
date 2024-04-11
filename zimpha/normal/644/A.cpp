#include <bits/stdc++.h>
using namespace std;

int ret[200][200];

int main() {
  int n, a, b; cin >> n >> a >> b;
  int x = 0, y = 0, u = 0, v = 0;
  for (int i = 1; i <= n; ++i) {
    if (i & 1) ++x; else ++y;
  }
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b; ++j) {
      if ((i ^ j) & 1) ++u; else ++v;
    }
  }
  if (x <= u && y <= v) {
    int x = 1, y = 2;
    for (int i = 0; i < a; ++i) {
      for (int j = 0; j < b; ++j) {
        if ((i ^ j) & 1) ret[i][j] = x * (x <= n), x += 2;
        else ret[i][j] = y * (y <= n), y += 2;
        printf("%d ", ret[i][j]);
      }
      puts("");
    }
  } else if (x <= v && y <= u) {
    int x = 1, y = 2;
    for (int i = 0; i < a; ++i) {
      for (int j = 0; j < b; ++j) {
        if ((i ^ j) & 1) ret[i][j] = y * (y <= n), y += 2;
        else ret[i][j] = x * (x <= n), x += 2;
        printf("%d ", ret[i][j]);
      }
      puts("");
    }
  } else {
    puts("-1");
  }
  return 0;
}