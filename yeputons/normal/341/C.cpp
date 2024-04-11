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

const int MOD = 1e9 + 7;
void madd(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }

const int MAXN = 2003;
int facs[MAXN + 1];
int dyn[MAXN + 1][MAXN + 1];

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  facs[0] = 1;
  for (int i = 1; i <= MAXN; i++)
    facs[i] = mmul(facs[i - 1], i);

  dyn[0][0] = 1;
  for (int fc = 1; fc <= MAXN; fc++) {
    dyn[fc][fc] = facs[fc];
    dyn[fc][0] = mmul(fc - 1, dyn[fc - 1][1]);
    for (int gc = 1; gc < fc; gc++) {
      madd(dyn[fc][gc], mmul(gc, dyn[fc - 1][gc - 1]));
      madd(dyn[fc][gc], mmul(fc - gc, dyn[fc - 1][gc]));
    }
  }

  int n;
  while (scanf("%d", &n) >= 1) {
    vb wasVal(n, false);
    vb isFr(n, false);
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x), x--;
      if (x < 0) isFr[i] = true;
      else wasVal[x] = true;
    }
    int fc = 0, gc = 0;
    for (int i = 0; i < n; i++)
      if (isFr[i]) {
        fc++;
        if (wasVal[i]) gc++;
      }
    eprintf("%d %d\n", fc, gc);
    printf("%d\n", dyn[fc][gc]);
  }
  return 0;
}