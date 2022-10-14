#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <set>

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

const int MAXH = 1000;
const int MAXW = 1000;
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

/*template<typename T> class ndeque {
  vector<T> data;
  int st;

  public:
  ndeque() : data(), st(0) {}
  void push_back(const T &x) { data.pb(x); }
  void pop_front() { assert(!empty()); st++; }
  bool empty() { return st >= sz(data); }
  const T& front() { return data[st]; }
};*/

char buf[MAXH][MAXW + 1];
int w, h;

bool bad(int x, int y) {
  if (x < 0 || y < 0 || x >= w || y >= h) return true;
  if (buf[y][x] != '.') return true;
  return false;
}

bool cur[MAXH][MAXW];
int deg[MAXH][MAXW];
vector<deque<pii> > qs;
bool dfs(int x, int y) {
  if (bad(x, y)) return false;
  if (cur[y][x]) return true;

  cur[y][x] = true;
  deg[y][x] = 0;
  for (int d = 0; d < 4; d++)
    deg[y][x] += dfs(x + dx[d], y + dy[d]);
  qs[deg[y][x]].pb(mp(x, y));
  return true;
}

int id[MAXH][MAXW];
vvi neigh;
void paint(int x, int y, int curid) {
  id[y][x] = curid;

  for (int d = 0; d < 4; d++) {
    int nx = x + dx[d], ny = y + dy[d];
    if (bad(nx, ny)) continue;
    if (id[ny][nx] >= 0) {
      if (id[ny][nx] != curid) {
        neigh[curid].pb(id[ny][nx]);
        neigh[id[ny][nx]].pb(curid);
      }
      continue;
    }
    deg[ny][nx]--;
    qs[deg[ny][nx]].pb(mp(nx, ny));
  }
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d%d", &h, &w) >= 2) {
    for (int y = 0; y < h; y++)
      scanf("%s", buf[y]);

    try {
      memset(id, -1, sizeof id);
      memset(cur, 0, sizeof cur);

      neigh.clear();
      qs.clear();
      qs.resize(5);
      int curid = 0;
      for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
          if (buf[y][x] == '.' && id[y][x] < 0) {
            dfs(x, y);
            if (!qs[0].empty()) throw 0;

            for (;;) {
              int x0 = -1, y0 = -1;
              for (int dg = 0; dg <= 4; dg++) {
                while (!qs[dg].empty()) {
                  x0 = qs[dg].front().first;
                  y0 = qs[dg].front().second;
                  qs[dg].pop_front();
                  if (deg[y0][x0] != dg || id[y0][x0] >= 0) {
                    x0 = y0 = -1;
                    continue;
                  }
                  assert(dg);
                  goto found;
                }
              }
              found:;
              if (x0 < 0 || y0 < 0) break;

              assert(deg[y0][x0]);
              neigh.pb(vi());

              int rx = -1, ry = -1;
              for (int d = 0; d < 4; d++) {
                int nx = x0 + dx[d], ny = y0 + dy[d];
                if (bad(nx, ny) || id[ny][nx] >= 0) continue;

                rx = nx; ry = ny;
                break;
              }
              assert(rx >= 0 && ry >= 0);

              paint(rx, ry, curid);
              int cnt = 1;
              for (int step = 0; step < 2; step++) {
                for (int d = 0; d < 4; d++) {
                  int nx = rx + dx[d], ny = ry + dy[d];
                  if (bad(nx, ny) || id[ny][nx] >= 0) continue;
                  if (!deg[ny][nx] || (step && cnt == 1)) {
                    paint(nx, ny, curid);
                    cnt++;
                  }
                }
              }

              curid++;
            }
          }

      vi newc(curid, -1);
      for (int i = 0; i < curid; i++)
        newc[i] = i;

      for (int i = 0; i < curid; i++) {
        vi ns = neigh[i];
        for (int i2 = 0; i2 < sz(ns); i2++)
          ns[i2] = newc[ns[i2]];
        sort(ns.begin(), ns.end());
        ns.resize(unique(ns.begin(), ns.end()) - ns.begin());

        int c = 0;
        for (c = 0; c < sz(ns) && ns[c] == c; c++);
        newc[i] = c;
      }

      for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
          if (buf[y][x] == '#') putc('#', stdout);
          else putc('0' + newc[id[y][x]], stdout);
        printf("\n");
      }
    } catch (...) {
      printf("-1\n");
    }

    #ifndef DEBUG
    break;
    #else
    printf("\n");
    #endif
  }
  return 0;
}