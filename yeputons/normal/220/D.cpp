#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
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

const int MOD = 1e9 + 7;
void madd(int &a, int b) { a += b; if (a >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }

ll getSq(ll x1, ll y1, ll x2, ll y2) {
  return x1 * y2 - x2 * y1;
}

const int DIV2 = (MOD + 1) / 2;

int AN2(int x) {
  int y = x;
  madd(y, MOD - 1);
  return mmul(x, y);
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int w, h;
  while (scanf("%d%d", &w, &h) >= 1) {
    int xcnt[2] = { 1 + w / 2, (w + 1) / 2 };
    int ycnt[2] = { 1 + h / 2, (h + 1) / 2 };

    int ans = 0;
    for (int y = 0; y <= min(h, 1); y++)
    for (int x = 0; x <= min(w, 1); x++) {
      int c[2][2];
      for (int a = 0; a < 2; a++)
      for (int b = 0; b < 2; b++)
        c[a][b] = mmul(xcnt[(x & 1) ^ a], ycnt[(y & 1) ^ b]);
      madd(c[0][0], MOD - 1);

      int cans = 0;
      madd(cans, mmul(2, mmul(c[0][0], c[0][1])));
      madd(cans, mmul(2, mmul(c[0][0], c[1][0])));
      madd(cans, mmul(2, mmul(c[0][0], c[1][1])));
      madd(cans, AN2(c[0][0]));
      madd(cans, AN2(c[0][1]));
      madd(cans, AN2(c[1][0]));
      madd(cans, AN2(c[1][1]));

      madd(cans, mmul(c[0][0], cans));
      madd(ans, cans);
    }

    for (int dx = 0; dx <= w; dx++) {
      int cans0 = 0;

      for (int dy = 0; dy <= h; dy++) if (dx || dy) {
        int ccnt = mmul(6, gcd(dx, abs(dy)) - 1);
        if (dx > 0 && dy > 0) madd(ccnt, ccnt);

        ccnt = mmul(ccnt, h - abs(dy) + 1);
        madd(cans0, ccnt);
      }
      cans0 = mmul(cans0, w - dx + 1);
      madd(ans, MOD - cans0);
    }
    printf("%d\n", ans);
  }
  return 0;
}