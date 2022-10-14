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
    vi dyn(n + 1, 1e9);
    char buf[8];
    for (int i = 0; i < 7; i++)
      buf[i] = '0';
    buf[7] = 0;

    dyn[0] = 0;
    for (int x = 1; x <= n; x++) {
      for (int i = 0;; i++)
        if (buf[i] < '9') {
          buf[i]++;
          break;
        } else {
          buf[i] = '0';
        }

      for (int i = 0; buf[i]; i++) {
        int ne = x - (buf[i] - '0');
        if (ne < x)
          dyn[x] = min(dyn[x], dyn[ne] + 1);
      }
    }
    printf("%d\n", dyn[n]);
  }
  return 0;
}