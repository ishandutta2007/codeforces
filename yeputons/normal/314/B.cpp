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

const int MAXSUMLEN = 1.1e9;
const int MAXL = 200;
const int MAXK = 30;

char t[MAXL + 1], p[MAXL + 1];
int lent, pert;

ll gos[MAXK + 1][MAXL + 1];

bool can(int perp) {
  ll sum = 0;
  for (int i = MAXK; i >= 0; i--)
    if (perp >= (1LL << i)) {
      perp -= 1LL << i;
      sum += gos[i][sum % lent];
    }
  return sum <= lent * pert;
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int perp;
  while (scanf("%d%d%s%s", &pert, &perp, t, p) >= 1) {
    lent = strlen(t);

    for (int st1 = 0; t[st1]; st1++) {
      ll a = st1;
      for (int i = 0; p[i]; i++) {
        int remop = lent + 10;
        while (t[a % lent] != p[i]) {
          a++;
          if (!--remop) {
            assert(st1 == 0);
            printf("0\n");
            goto baed;
          }
        }
        a++;
      }
      gos[0][st1] = a - st1;
    }
    goto good;
    baed: continue;
    good:

    for (int k = 1; k <= MAXK; k++)
    for (int i = 0; i < lent; i++) {
      ll fir = gos[k - 1][i];
      ll npos = (i + fir) % lent;
      gos[k][i] = fir + gos[k - 1][npos];
    }

    int L = 0, R = MAXSUMLEN / perp;
    assert(!can(perp * R));
    assert(can(perp * L));

    while (L + 1 < R) {
      int M = L + (R - L) / 2;
      if (can(perp * M)) L = M;
      else R = M;
    }
    printf("%d\n", L);
  }
  return 0;
}