#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <map>
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

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    if (m == 3) {
      switch (n) {
      case 3:
        printf("0 0\n3 0\n0 3\n");
        break;
      case 4:
        printf("0 0\n3 0\n0 3\n1 1\n");
        break;
      case 5:
      case 6:
        printf("-1\n");
        break;
      }
      continue;
    }

    vector<pii> pts(m);
    int mid = m / 2;
    int dn = -1e9;
    for (int i = 0; i < m; i++) {
      pts[i] = mp(i, (i - mid) * (i - mid));
      dn = max(dn, pts[i].second);
    }

    const int MAXC = int(1e8);
    for (int i = 0; i < m; i++)
      printf("%d %d\n", pts[i].first, MAXC - dn + pts[i].second);
    for (int i = 0; i < n - m; i++)
      printf("%d %d\n", pts[i].first, -(MAXC - dn + pts[i].second));
  }
  return 0;
}