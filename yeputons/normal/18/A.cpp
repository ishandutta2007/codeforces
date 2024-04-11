#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

int eprintf(const char *format, ...) {
  #ifdef DEBUG
  va_list args;
  va_start(args, format);
  int ret = vfprintf(stderr, format, args);
  va_end(args);
  return ret;
  #else
  return 0;
  #endif
}

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;

#define INF 2000000000
#define mp make_pair
#define pb push_back

#ifdef linux
#define LLD "%lld"
#elif _WIN32
#define LLD "%I64d"
#endif

struct pt {
  int x, y;
  pt() { x = y = 0; }
  pt(int _x, int _y) { x = _x; y = _y; }
};
pt operator-(const pt &a, const pt &b) { return pt(a.x - b.x, a.y - b.y); }
bool check(pt pts[3]) {
  for (int a = 0; a < 3; a++) {
    int b = 0, c = 1;
    if (a == b) b++, c++;
    if (a == c) c++;

    pt p1 = pts[b] - pts[a];
    pt p2 = pts[c] - pts[a];
    if (!p1.x && !p1.y) continue;
    if (!p2.x && !p2.y) continue;
    if (p1.x * p2.x + p1.y * p2.y != 0) continue;
    return true;
  }
  return false;
}

const int dc = 4;
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

int main() {
  pt pts[3];
  while (scanf("%d%d", &pts[0].x, &pts[0].y) >= 2) {
    scanf("%d%d", &pts[1].x, &pts[1].y);
    scanf("%d%d", &pts[2].x, &pts[2].y);

    if (check(pts)) {
      printf("RIGHT\n");
    } else {
      bool ans = false;
      for (int i = 0; !ans && (i < 3); i++)
        for (int d = 0; d < dc; d++) {
          pts[i].x += dx[d];
          pts[i].y += dy[d];
          if (check(pts)) {
            ans = true;
            printf("ALMOST\n");
            break;
          }
          pts[i].x -= dx[d];
          pts[i].y -= dy[d];
        }
      if (!ans) printf("NEITHER\n");
    }
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}