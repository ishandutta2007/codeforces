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

struct pt {
  int x, y, z;
  int id, ty;
  bool operator<(const pt &p) const { return z < p.z; }
  int dist(const pt &p) const { return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y); }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #else
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  srand(23478);

  int n;
  while (scanf("%d", &n) >= 1) {
    const int a = rand() % 10000;
    const int b = rand() % 10000;
    vector<pt> pts(n);
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &pts[i].x, &pts[i].y);
      pts[i].id = i + 1;
      pts[i].ty = 1;

      if (pts[i].x < 0) { pts[i].ty++; pts[i].x = -pts[i].x; }
      if (pts[i].y < 0) { pts[i].ty += 2; pts[i].y = -pts[i].y; }
      pts[i].z = -b * pts[i].x + a * pts[i].y;
    }

    double zd = sqrt(a * a + b * b);

    sort(pts.begin(), pts.end());
    int bans = 1e9;
    int ba = -1, bb = -1;

    for (int i = 0; i < sz(pts); i++) {
      for (int d = -1; d <= 1; d += 2) {
        for (int j = i + d; j >= 0 && j < sz(pts) && abs(pts[i].z - pts[j].z) < zd * bans; j += d) {
          int cans = pts[i].dist(pts[j]);
          if (cans < bans) {
            bans = cans;
            ba = i;
            bb = j;
          }
        }
      }
    }

    assert(ba >= 0);
    int rev[] = { -1, 4, 3, 2, 1 };
    printf("%d %d %d %d\n", pts[ba].id, pts[ba].ty, pts[bb].id, rev[pts[bb].ty]);
  }
  return 0;
}