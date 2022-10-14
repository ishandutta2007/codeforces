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
  ll x, y;
  pt() : x(0), y(0) {}
  pt(ll _x, ll _y) : x(_x), y(_y) {}
  pt operator-(const pt &p) const { return pt(x - p.x, y - p.y); }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  pt a, b, c;
  while (scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y) >= 1) {
    bool g = false;
    for (int step = 0; step < 4; step++) {
      pt off = b - a;

      ll A = -c.y, B = c.x, C = 0;
      if (A * A + B * B) {
        ll D = A * off.x + B * off.y + C;

        if (D % (A * A + B * B) == 0) {
          A = c.x, B = c.y, C = 0;
          D = A * off.x + B * off.y + C;
          if (D % (A * A + B * B) == 0)
            g = true;
        }
      } else {
        if (!off.x && !off.y)
          g = true;
      }

      swap(b.x, b.y);
      b.x = -b.x;
    }
    printf(g ? "YES\n" : "NO\n");

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}