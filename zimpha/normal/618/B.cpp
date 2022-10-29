#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int a[100][100], p[100];

int main() {
  int n; scanf("%d", &n);
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= n; ++ j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; ++ i) {
    for (int r = 1; r <= n; ++ r) {
      int cnt = 0;
      for (int c = 1; c <= n; ++ c) {
        if (a[r][c] == i) ++ cnt;
      }
      if (cnt == n - i && p[r] == 0) {
        p[r] = i;
        break;
      }
    }
  }
  for (int i = 1; i <= n; ++ i) cout << p[i] << " ";
  cout << endl;
  return 0;
}