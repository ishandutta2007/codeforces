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

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int dc = 3;
const int dx[] = { 1, 1, 0 };
const int dy[] = { 0, 1, 1 };
const int n = 19;
const int h = 5;
const int w = 5;
const int ws[] = { 3, 4, 5, 4, 3 };
const int st[] = { 0, 0, 0, 1, 2 };
//const int st[] = { 0, 0, 0, 0, 0 };
int ids[h][w];

void initIds() {
  memset(ids, -1, sizeof ids);
  int y = 0, x = st[y];
  for (int i = 0; i < n; i++) {
    ids[y][x] = i;
    if (++x >= st[y] + ws[y])
      x = st[++y];
  }
}
/*vvb get(int msk, vvb &res) {
//  vvb res(h, vb(w, false));
  int y = 0, x = st[y];
  for (int i = 0; i < n; i++) {
    res[y][x] = msk & (1 << i);
    if (++x >= st[y] + ws[y])
      x = st[++y];
  }
  return res;
}
int getMsk(const vvb &cur) {
  int res = 0;
  int y = 0, x = st[y];
  for (int i = 0; i < n; i++) {
    res += cur[y][x] << i;
    if (++x >= st[y] + ws[y])
      x = st[++y];
  }
  return res;
}*/

vi mem;
void go(int st) {
//  vvb cur(h, vb(w));
//  get(st, cur);
  if (mem[st]) return;

  mem[st] = -1;
  for (int sy = 0; sy < h; sy++)
    for (int sx = 0; sx < w; sx++)
      for (int d = 0; d < dc; d++) {
//        vvb ncur = cur;

        int x = sx, y = sy;
        int diff = 0;
        for (int l = 1;; l++) {
          if (x >= w || y >= h) break;
          if (ids[y][x] < 0) break;
          if (!(st & (1 << ids[y][x]))) break;
//          if (!cur[y][x]) break;
          assert(ids[y][x] >= 0);
          diff |= 1 << ids[y][x];
          int nid = st ^ diff;
          go(nid);
          if (mem[nid] < 0) { mem[st] = 1; return; }

          x += dx[d], y += dy[d];
        }
      }
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  initIds();
  try { 
  for (;;) {
    int st = 0;
    for (int i = 0; i < n; i++) {
      char c;
      if (scanf(" %c", &c) < 1) throw 0;
      st += (c == 'O') << i;
    }
    mem = vi(1 << n, 0);
    mem[0] = -1;
    go(st);
    printf("%s\n", (mem[st] == 1) ? "Karlsson" : "Lillebror");
  
    #ifndef DEBUG
    break;
    #endif
  }
  } catch (...) {}
  return 0;
}