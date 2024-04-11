#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi pos(n, -1);
    vi idByPos(n, -1);

    for (int i = 0; i < n; i++) {
      int id;
      scanf("%d", &id), id--;
      idByPos[i] = id;
      pos[id] = i;
    }
    int q;
    scanf("%d", &q);
    while (q --> 0) {
      int p, x, y;
      scanf("%d%d%d", &p, &x, &y), x--, y--;
      if (p == 2) {
        int p1 = x, p2 = y;
        x = idByPos[x];
        y = idByPos[y];
        swap(idByPos[p1], idByPos[p2]);
        swap(pos[x], pos[y]);
      } else {
        int ans = 0;
        int prev = n;
        for (int i = x; i <= y; i++) {
          int cur = pos[i];
          if (prev >= cur)
            ans++;
          prev = cur;
        }
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}