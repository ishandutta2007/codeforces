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

int eprintf(const char* format, ...) {
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

#define pb push_back
#define mp make_pair
#define EPS 1e-9

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

int rdn(double x) {
  int y = (int)x;
  if (fabs(x - y - 1) < EPS) return y + 1;
  return y;
}
int rup(double x) {
  int y = (int)x + 1;
  if (fabs(x - y + 1) < EPS) return y - 1;
  return y;
}

const int MAXV = 5e6 + 100;
const int ZERO = MAXV;
bool was[MAXV * 2];

void add(int x) {
  x += ZERO;
  assert(0 <= x && x < MAXV * 2);
  was[x] = true;
}

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif
  
  int n, m;
  while (scanf("%d%d", &n, &m) >= 2) {
    ll ans = 0;

    memset(was, 0, sizeof was);
    for (int b = 1; b <= n; b++) {
      ll cnt = min((ll)b * b, (ll)m);
      {
        int l = 0;
        if ((ll)b * b >= m) l = rup(sqrt((ll)b * b - m));
        int r = rdn(sqrt((ll)b * b - 1));
        if (l <= r) {
          cnt -= r - l + 1;
          for (int i = l; i <= r; i++) {
            add(-i - b);
            add(i - b);
          }
        }
      }
      ans += cnt * 2;
    }
    for (int i = 0; i < MAXV * 2; i++)
      ans += was[i];
    printf("%I64d\n", ans);

    break; 
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}