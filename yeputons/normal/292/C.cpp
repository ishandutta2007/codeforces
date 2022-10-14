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

char gs[20];
int gcnt;

vector<unsigned> res;

int lens[4];
int sumlen;

char cur[20];

void check() {
  unsigned cres = 0;
  int ptr = 0;
  for (int i = 0; i < 4; i++) {
    int x = 0;
    if (cur[ptr] == '0' && lens[i] > 1) return;
    for (int i2 = 0; i2 < lens[i]; i2++) {
      x = x * 10 + cur[ptr] - '0';
      ptr++;
    }
    if (x < 0 || x >= 256) return;
    cres <<= 8;
    cres |= x;
  }
  res.pb(cres);
}

int was[20];
void go2(int pos) {
  if (pos > sumlen - pos - 1) {
    for (int i = 0; i < gcnt; i++)
      if (!was[i]) return;
    check();
    return;
  }
  for (int i = 0; i < gcnt; i++) {
    cur[pos] = cur[sumlen - pos - 1] = gs[i];
    was[i]++;
    go2(pos + 1);
    was[i]--;
  }
}

void go1(int pos) {
  if (pos >= 4) {
    sumlen = 0;
    for (int i = 0; i < 4; i++)
      sumlen += lens[i];
    go2(0);
    return;
  }

  for (int &i = lens[pos] = 1; i <= 3; i++)
    go1(pos + 1);
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  while (scanf("%d", &gcnt) >= 1) {
    clock_t tim = clock();
    for (int i = 0; i < gcnt; i++)
      scanf(" %c", &gs[i]);
    res.clear();
    memset(was, 0, sizeof was);
    go1(0);

    printf("%d\n", sz(res));
    for (int i = 0; i < sz(res); i++) {
      unsigned cres = res[i];
      for (int i2 = 0; i2 < 4; i2++) {
        unsigned x = (cres >> (8 * (3 - i2))) & 0xFF;
        printf("%d%c", x, "\n."[i2 < 3]);
      }
    }
    if (clock() - tim >= 100) {
      eprintf("%d\n", clock() - tim);
    }
  }
  return 0;
}