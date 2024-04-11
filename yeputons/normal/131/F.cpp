#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

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

const int dx[] = { 1, 0, 1, 2, 1 };
const int dy[] = { 0, 1, 1, 1, 2 };

char f1[1000][1001];
bool f[1000][1000];
int ycnt[1001];
int ysum[1001];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int h, w, k;
  while (scanf("%d%d%d", &h, &w, &k) >= 3) {
    for (int y = 0; y < h; y++)
      scanf("%s", f1[y]);

    if (h <= 2 || w <= 2) {
      printf("0\n");
      continue;
    }

    h -= 2;
    w -= 2;
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        f[y][x] = true;
        for (int i = 0; i < 5; i++)
          f[y][x] = f[y][x] && f1[y + dy[i]][x + dx[i]] == '1';
//        eprintf("%d", f[y][x]);
      }
//      eprintf("\n");
    }

    ll ans = 0;
    for (int x1 = 0; x1 < w; x1++) {
      for (int y = 0; y <= h; y++)
        ycnt[y] = ysum[y] = 0;

      for (int x2 = x1; x2 < w; x2++) {
        for (int y = 0; y < h; y++)
          ycnt[y] += f[y][x2];
        ysum[0] = 0;
        for (int y = 0; y < h; y++)
          ysum[y + 1] = ysum[y] + ycnt[y];

//        eprintf("%d..%d (%d %d %d)\n", x1, x2, ysum[0], ysum[1], ysum[2]);
        int p1 = 0;
        for (int p2 = 0; p2 < h; p2++) {
          while (p1 <= p2 && ysum[p1] + k <= ysum[p2 + 1])
            p1++;
          ans += p1;
        }
      }
    }
    printf("%I64d\n", ans);
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}