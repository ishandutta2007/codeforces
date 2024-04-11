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

const int MAXL = 20;

pair<ll, int> dyn[10][MAXL + 1][10];
char buf[MAXL + 1];
int len;

pair<ll, int> calc(int maxd, int st) {
  if (!buf[st + 1]) {
    // last digit
    ll c = 0;
    int m = max(maxd, buf[st] - '0');
    int res = 0;
    if (m > 0) {
      c++;
      res = buf[st] - '0' - m;
      if (res < 0) res += 10;
    }
//    eprintf("maxd=%d, m=%d, c=%d; res=%d\n", maxd, m, int(c), res);
    if (maxd > 0 && res == 0) {
      c++;
      res = 10 - maxd;
    }
    return mp(c, res);
  }

  pair<ll, int> ne = calc(max(maxd, buf[st] - '0'), st + 1);
//  eprintf("ne=%I64d, %d; maxd=%d, st=%d\n", ne.first, ne.second, maxd, st);
  for (char d = buf[st] - 1; d >= '0'; d--) {
    pair<ll, int> cne = dyn[max(maxd, d - '0')][len - st - 2][ne.second];
//    eprintf("cne=%I64d %d (%d %d %d)\n", cne.first, cne.second, max(maxd, d - '0'), len - st - 2, ne.second);
    ne.first += cne.first;
    ne.second = cne.second;
  }
  return ne;
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  for (int fir = 0; fir < 10; fir++) {
    for (int las = 0; las < 10; las++) {
      ll c = 0;
      int m = max(las, fir);
      int res = las;

      if (m > 0) {
        c++;
        res = las - m;
        if (res < 0) res += 10;
      }
      if (res == 0 && fir > 0) {
        c++;
        res = 10 - fir;
      }
      dyn[fir][0][las] = mp(c, res);
    }
  }

  for (int i = 1; i <= MAXL; i++)
  for (int fir = 0; fir < 10; fir++) {
    for (int las = 0; las < 10; las++) {
      ll csum = 0;
      int clas = las;
      for (int dig = 9; dig >= 0; dig--) {
        pair<ll, int> ne = dyn[max(fir, dig)][i - 1][clas];
        csum += ne.first;
        clas = ne.second;
      }
      dyn[fir][i][las] = mp(csum, clas);
    }
  }

  ll n;
  while (scanf("%I64d", &n) >= 1) {
    if (n == 0) {
      printf("0\n");
      continue;
    }
    snprintf(buf, sizeof buf, "%I64d", n);
    len = strlen(buf);
    printf("%I64d\n", calc(0, 0).first);
  }
  return 0;
}