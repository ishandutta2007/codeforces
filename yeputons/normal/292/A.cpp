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

struct Ev {
  int t, c;
  Ev(int t, int c) : t(t), c(c) {}
  bool operator<(const Ev &e2) const {
    if (t != e2.t) return t > e2.t;
    return c > e2.c;
  }
};

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    priority_queue<Ev> evs;
    for (int i = 0; i < n; i++) {
      int t, c;
      scanf("%d%d", &t, &c);
      evs.push(Ev(t, c));
    }

    int ccnt = 0;
    int lastt = 0;
    int ans = 0;
    int biggest = 0;

    while (!evs.empty()) {
      Ev e = evs.top(); evs.pop();
      assert(lastt <= e.t);
      if (ccnt) {
        ccnt -= e.t - lastt;
        ans = max(ans, e.t);
        assert(ccnt >= 0);
      }
      lastt = e.t;

      if (e.c > 0) {
        ccnt += e.c;
        evs.push(Ev(e.t + ccnt, 0));
      }
      biggest = max(biggest, ccnt);
    }
    printf("%d %d\n", ans, biggest);
  }
  return 0;
}