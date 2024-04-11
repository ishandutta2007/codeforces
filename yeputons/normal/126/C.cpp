#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

char f[2000][2010];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    for (int y = 0; y < n; y++) {
      scanf("%s", f[y]);
      for (int x = 0; x < n; x++)
        f[y][x] -= '0';
    }

    int ans = 0;
    vi valDiag(n, 0);
    for (int step = 0; step < 2; step++) {
      vi xcol(n, 0);

      for (int y = 0; y < n; y++) {
        int rcol = 0;
        for (int x = n - 1; x > y; x--) {
          int ccol = rcol ^ xcol[x];
          if (ccol != f[y][x]) {
            ans++;
            valDiag[x] ^= 1;
            valDiag[y] ^= 1;
            rcol ^= 1;
            xcol[x] ^= 1;
          }
        }
      }

      for (int y = 0; y < n; y++)
        for (int x = y + 1; x < n; x++)
          swap(f[y][x], f[x][y]);
    }
    for (int i = 0; i < n; i++)
      if (valDiag[i] != f[i][i])
        ans++;
    printf("%d\n", ans);
  }
  return 0;
}