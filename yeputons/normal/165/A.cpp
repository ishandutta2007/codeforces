#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define TASKNAME "std"
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int sgn(int x) { return x < 0 ? -1 : !!x; }

const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

int main()  {
  #ifdef DEBUG
  freopen(TASKNAME ".in", "r", stdin);
  freopen(TASKNAME ".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<pii> pts(n);
    for (int i = 0; i < n; i++)
      scanf("%d%d", &pts[i].first, &pts[i].second);

    int cnt = 0;
    for (int a = 0; a < n; a++) {
      bool g = true;
      for (int ty = 0; ty < 4; ty++) {
        bool h = false;
        for (int b = 0; b < n; b++)
          if (sgn(pts[b].first - pts[a].first) == dx[ty] && sgn(pts[b].second - pts[a].second) == dy[ty])
            h = true;
        if (!h) g = false;
      }
      cnt += g;
    }
    printf("%d\n", cnt);
  }
  return 0;
}