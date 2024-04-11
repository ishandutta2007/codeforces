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

const int MAXV = (1 << 22) - 1;

int main()  {
  #ifdef DEBUG
  freopen(TASKNAME ".in", "r", stdin);
  freopen(TASKNAME ".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    vi has(MAXV + 1, -1);
    for (int i = 0; i < n; i++)
      has[as[i]] = as[i];

    for (int msk = 1; msk <= MAXV; msk++) if (has[msk] < 0) {
      for (int las = 0; las < 30; las++) if (msk & (1 << las)) {
        int nmsk = msk ^ (1 << las);
        if (has[nmsk] >= 0) {
          has[msk] = has[nmsk];
          break;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      int nv = ~as[i] & MAXV;
      printf("%d%c", has[nv], "\n "[i + 1 < n]);
    }
  }
  return 0;
}