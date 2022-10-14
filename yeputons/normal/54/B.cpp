#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;

typedef vvi Puzzle;

char f[20][21];

Puzzle cut(int sy, int sx, int h, int w) {
  Puzzle p(h, vi(w, 0));
  for (int y = sy; y < sy + h; y++)
    for (int x = sx; x < sx + w; x++)
      p[y - sy][x - sx] = f[y][x];
  return p;
}

void turn(Puzzle &p) {
  int h = p.size();
  int w = p[0].size();
  Puzzle np(w, vi(h));
  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      np[x][h - y - 1] = p[y][x];

  p = np; // !!!
}

int h, w;
bool check(int ah, int aw) {
  set<Puzzle> pzs;
  for (int y = 0; y < h; y += ah)
    for (int x = 0; x < w; x += aw) {
      Puzzle p = cut(y, x, ah, aw);
      Puzzle mp = p;
      for (int i = 0; i < 4; i++) {
        mp = min(mp, p);
        turn(p);
      }
      pzs.insert(mp);
    }
  return pzs.size() == (h / ah) * (w / aw);
}

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  while (scanf("%d%d", &h, &w) >= 1) {
    for (int y = 0; y < h; y++)
      scanf("%s", f[y]);

    int ans = 0;
    int rh = h, rw = w;
    for (int ah = 1; ah <= h; ah++) if (!(h % ah))
      for (int aw = 1; aw <= w; aw++) if (!(w % aw)) {
        if (!check(ah, aw)) continue;
        ans++;
        if (ah * aw < rh * rw) {
          rh = ah;
          rw = aw;
        }
        if (ah * aw == rh * rw && ah < rh) {
          rh = ah;
          rw = aw;
        }
      }
    printf("%d\n%d %d\n", ans, rh, rw);

    #ifndef DEBUG
    #warning No multitest!!!
    break;
    #endif
  }
  return 0;
}